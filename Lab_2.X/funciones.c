/*
 * File:   funciones.c
 * Author: ICHELECE
 *
 * Created on 29 de enero de 2020, 14:51
 */


#include <xc.h>
#include <stdint.h>
#include "funciones.h"


void init_ADC(uint8_t channel){
    ADCON0bits.ADCS1 = 0; 
    ADCON0bits.ADCS0 = 1;           //    FOSC/8
    
    
    switch(channel){
        case 0:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;    ///AN0
            break;
        case 1:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;    ///AN1
            break;
        case 2:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;    ///AN2
            break;
        case 3:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;    ///AN3
            break;
        case 4:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;    ///AN4
            break;
        case 5:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;    ///AN5
            break;
        case 6:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;    ///AN6
            break;
        case 7:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;    ///AN7
            break;        
        case 8:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;    ///AN8
            break;
        case 9:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;    ///AN9
            break;
        case 10:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;    ///AN10
            break;
        case 11:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;    ///AN11
            break;            
        case 12:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;    ///AN12
            break;
        case 13:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;    ///AN13
            break;
        case 14:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;    ///CVREF
            break;
        case 15:
            ADCON0bits.CHS3 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;    ///FIXED REF
            break;    
        default:
            ADCON0bits.CHS3 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;    ///AN0
            break;
    }

    ADCON1bits.ADFM = 0;
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;
    ADCON0bits.ADON = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;
}

void init_TMR0(uint8_t valor_tmr){

    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 0;
    
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PS1 = 0;
    OPTION_REGbits.PS0 = 0;     //Prescaler 32

    INTCONbits.T0IF = 0;
    
    TMR0 = valor_tmr;
}


void hexa_display(uint8_t adc_valor, uint8_t transis ){
    uint8_t valor1;
    uint8_t valor2;
    
    valor1 = adc_valor & 0x0F;
    valor2 = (adc_valor & 0xF0)>>4 ;
    
    
    switch(transis){
        case 0:
            PORTEbits.RE0 = 0;
            PORTEbits.RE1 = 1;
            switch(valor2){
                case 0:
                    PORTC = 0x3F;
                    break;
                case 1:
                    PORTC = 0x06;
                    break;
                case 2:
                    PORTC = 0x5B;
                    break;
                case 3:
                    PORTC = 0x4F;
                    break;
                case 4:
                    PORTC = 0x66;
                    break;
                case 5:
                    PORTC = 0x6D;
                    break;
                case 6:
                    PORTC = 0x7D;
                    break;
                case 7:
                    PORTC = 0x07;
                    break;
                case 8:
                    PORTC = 0x7F;
                    break;
                case 9:
                    PORTC = 0x67;
                    break;    
                case 10:
                    PORTC = 0x77;
                    break;
                case 11:
                    PORTC = 0x7C;
                    break;
                case 12:
                    PORTC = 0x39;
                    break;
                case 13:
                    PORTC = 0x5E;
                    break;
                case 14:
                    PORTC = 0x79;
                    break;
                case 15:
                    PORTC = 0x71;
                    break;        
            }
            
            break;
        case 1:
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
            switch(valor1){
                case 0:
                    PORTC = 0x3F;
                    break;
                case 1:
                    PORTC = 0x06;
                    break;
                case 2:
                    PORTC = 0x5B;
                    break;
                case 3:
                    PORTC = 0x4F;
                    break;
                case 4:
                    PORTC = 0x66;
                    break;
                case 5:
                    PORTC = 0x6D;
                    break;
                case 6:
                    PORTC = 0x7D;
                    break;
                case 7:
                    PORTC = 0x07;
                    break;
                case 8:
                    PORTC = 0x7F;
                    break;
                case 9:
                    PORTC = 0x67;
                    break;    
                case 10:
                    PORTC = 0x77;
                    break;
                case 11:
                    PORTC = 0x7C;
                    break;
                case 12:
                    PORTC = 0x39;
                    break;
                case 13:
                    PORTC = 0x5E;
                    break;
                case 14:
                    PORTC = 0x79;
                    break;
                case 15:
                    PORTC = 0x71;
                    break;        
            }
            break;
    }


}