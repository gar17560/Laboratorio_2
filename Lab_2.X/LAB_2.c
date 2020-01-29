/*
 * File:   Laboratorio_2.c
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

void config(void);

void main(void) {
    
    
    
    
  
    
    return;
}


void config(void){

    //ei(); //GIE = 1 del INTCON
    //di(); //GIE = 0
    
    TRISC = 0x00;
    PORTC = 0x00;   //Todo el puerto C como salida
    
    PORTE = 0x0;
    ANSEL = 0x01;  // ANS0 como  
    TRISE = 0x0;   //Todo el puerto E como salida
    
    PORTB = 0x00;
    TRISB = 0b11111111;
    ANSELH = 0x00;
    WPUB = 0b11111111;
    OPTION_REGbits.nRBPU = 0;  //Puertp B como entrada con PULL-UP
    IOCB = 0x03;                //Habilitamos las interrupciones para el puerto B
    
    PORTA = 0x00;
    TRISA = 0x01;       // Puerto A0 como entrada
    
    PORTD = 0x00;
    TRISD = 0x00;        // Puerto D como salida  
    
    
    ////////////////////////////////////////////////////////////////////////////
    
    ei();
    INTCONbits.RBIE = 1;
    
    
    
}