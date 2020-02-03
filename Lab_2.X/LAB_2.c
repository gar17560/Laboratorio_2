/*
 * File:   LAB_2.c
 * Author: Miguel García
 * Carné: 17560
 * Electrónica digital 2
 * Sección: 21
 *
 * Created on 29 de enero de 2020, 14:18
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdint.h>
#include "funciones.h"


#define _XTAL_FREQ 4000000 //Frecuencia de trabajo

// Variables--------------------------------------------------------------------
uint8_t contador = 0;
uint8_t a = 0;
uint8_t b = 0;
uint8_t valor_adc = 0x00;
uint8_t transis = 0x01;


//Funciones---------------------------------------------------------------------
void config(void);



//Loop principal----------------------------------------------------------------
void main(void) {
    config();
    init_ADC(0x00);                      // función del ADC con AN0
    init_TMR0(0xFF);
    
    contador = 0x00;
    PORTD = contador;
    while(1){
        PORTD = contador;
        if(PORTBbits.RB0 == 1){
            a=0;
        }
        if(PORTBbits.RB1 == 1){
            b=0;
        }
        
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO == 1){
            
        }    
    if (valor_adc > contador){
        PORTEbits.RE2 = 1;
    }
    
    if (valor_adc < contador){
        PORTEbits.RE2 = 0;
    }
    
    }
    
    
    return;
}

void __interrupt() isr(void){
    if(PIR1bits.ADIF == 1){
        valor_adc = ADRESH;
        PIR1bits.ADIF = 0;
    }
    
    if (INTCONbits.RBIF == 1){
        //uint8_t hola;
        //hola = PORTB;
        if (PORTBbits.RB0==0 && a==0){    
            a = 1;
            if(contador >0x00){
                contador--;
            }
        }
        if (PORTBbits.RB1==0 && b ==0){    
            b = 1;
            if(contador < 0xFF){
                contador++;
        }
        }
//        PORTD = contador;
        INTCONbits.RBIF = 0;   
    }
    
    if(INTCONbits.T0IF == 1){
        hexa_display(valor_adc, transis );
        switch(transis){
            case 0:
                transis = 0x01;
                break;
            case 1:
                transis = 0x00;
                break;
        }
    INTCONbits.T0IF = 0;
    }
    return;
}



void config(void){

    //ei(); //GIE = 1 del INTCON
    //di(); //GIE = 0
    
    TRISC = 0x00;
    PORTC = 0x00;   //Todo el puerto C como salida
    
    PORTE = 0x0;
    ANSEL = 0x01;  // ANS0 como entrada analogica
    TRISE = 0x0;   //Todo el puerto E como salida
    
    PORTB = 0x00;
    TRISB = 0b11111111;
    ANSELH = 0x00;
    WPUB = 0b11111111;
    OPTION_REGbits.nRBPU = 0;  //Puertp B como entrada con PULL-UP
    IOCB = 0x03;                //Habilitamos las interrupciones para el puerto B en RB0 y RB1
    
    PORTA = 0x00;
    TRISA = 0x01;       // Puerto A0 como entrada
    
    PORTD = 0x00;
    TRISD = 0x00;        // Puerto D como salida  
    
    
    ////////////////////////////////////////////////////////////////////////////
    ////    INTERRUPCIONES PUERTO B
    ////////////////////////////////////////////////////////////////////////////
    ei();
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;
    INTCONbits.PEIE = 1;
    
}