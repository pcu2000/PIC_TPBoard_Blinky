/**
 * @file main.c
 * @author pcu2000
 * @date 2026-02-14
 * @brief Hello World Progamm für PIC I/O TP Board Light Edition V2.1
 */
// PIC16F15376 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = HFINT1  // Power-up default value for COSC bits (HFINTOSC (1MHz))
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config BBSIZE = BB512   // Boot Block Size Selection bits (512 words boot block size)
#pragma config BBEN = OFF       // Boot Block Enable bit (Boot Block disabled)
#pragma config SAFEN = OFF      // SAF Enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block Write Protection bit (Application Block not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration Register not write protected)
#pragma config WRTSAF = OFF     // Storage Area Flash Write Protection bit (SAF not write protected)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (UserNVM code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>

// ** DELAY-EINSTELLUNGEN ** 
#define _XTAL_FREQ 1000000 // Frequenz 1MHz 
#define delay_EINHEIT 1 // Basiszeit 1ms 
#define led_IMPULS 500 //   1ms = 500ms 
#define led_ZYKLUS 1000 //   1ms = 1s 

#define INTLed PORTEbits.RE0 //Interne LED auf PIC Module
#define ON 1
#define OFF 0


int main(void) {
// *** Variabeln *** 
 unsigned int delay_Timer = 0; // Delaytimer-Einheit = 10ms 
 
 // *** INITIALISIERUNG *** 
 // ** TRISx ** 
 TRISA = 0b01010111; // PORTA 1 = Input / 0 = Output
 TRISB = 0x00; // PORTB 1 = Input / 0 = Output 
 TRISC = 0xFF; // PORTC 1 = Input / 0 = Output 
 TRISD = 0x00; // PORTD 1 = Input / 0 = Output 
 TRISE = 0x00; // PORTE 1 = Input / 0 = Output

 // ** ADC *** 
 ANSELA = 0x00; // Set PORTA as Digital I/O 
 ANSELB = 0x00; // Set PORTB as Digital I/O 
 ANSELC = 0x00; // Set PORTC as Digital I/O 
 ANSELD = 0x00; // Set PORTD as Digital I/O 
 ANSELE = 0x00; // Set PORTE as Digital I/O 
 
 // ** PORTx ** 
 PORTA = 0x00; // PORTD auf 0 setzen 
 PORTB = 0x00; // PORTD auf 0 setzen 
 //PORTC = 0x00; // PORTD auf 0 setzen 
 PORTD = 0x00; // PORTD auf 0 setzen 
 PORTE = 0x00; // PORTD auf 0 setzen 
 
 // *** ENDLOS-LOOP *** 
 while(1) 
 { 
 PORTD = PORTC; //Schalterstellung auf LED's
 // *** BLINKVORGANG *** 
 if(delay_Timer <= led_IMPULS) // Time-Phase kleiner led_IMPULS 
 { 
 //PORTE = 0x01;
 INTLed = ON;
 } 
 else if(delay_Timer <= led_ZYKLUS) // Zeit <= LED-Zyklus 
 { 
 //PORTE = 0x00;
 INTLed = OFF;
 } 
 else 
 { 
 delay_Timer = 0; // neuer Zyklus 
 } 
 
 // *** GLOBAL DELAY *** 
 __delay_ms(delay_EINHEIT); // 1ms warten 
 delay_Timer = delay_Timer + 1; 
 } //end of while 
} //end of main 


