/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18857
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SIN aliases
#define SIN_TRIS                 TRISAbits.TRISA4
#define SIN_LAT                  LATAbits.LATA4
#define SIN_PORT                 PORTAbits.RA4
#define SIN_WPU                  WPUAbits.WPUA4
#define SIN_OD                   ODCONAbits.ODCA4
#define SIN_ANS                  ANSELAbits.ANSA4
#define SIN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SIN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SIN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SIN_GetValue()           PORTAbits.RA4
#define SIN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SIN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SIN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SIN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SIN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SIN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SIN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SIN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SOUT aliases
#define SOUT_TRIS                 TRISAbits.TRISA5
#define SOUT_LAT                  LATAbits.LATA5
#define SOUT_PORT                 PORTAbits.RA5
#define SOUT_WPU                  WPUAbits.WPUA5
#define SOUT_OD                   ODCONAbits.ODCA5
#define SOUT_ANS                  ANSELAbits.ANSA5
#define SOUT_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SOUT_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SOUT_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SOUT_GetValue()           PORTAbits.RA5
#define SOUT_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SOUT_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SOUT_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SOUT_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SOUT_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SOUT_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SOUT_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SOUT_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set BUTTON1 aliases
#define BUTTON1_TRIS                 TRISAbits.TRISA7
#define BUTTON1_LAT                  LATAbits.LATA7
#define BUTTON1_PORT                 PORTAbits.RA7
#define BUTTON1_WPU                  WPUAbits.WPUA7
#define BUTTON1_OD                   ODCONAbits.ODCA7
#define BUTTON1_ANS                  ANSELAbits.ANSA7
#define BUTTON1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BUTTON1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BUTTON1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BUTTON1_GetValue()           PORTAbits.RA7
#define BUTTON1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BUTTON1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BUTTON1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BUTTON1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BUTTON1_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define BUTTON1_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define BUTTON1_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define BUTTON1_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC4
#define LED1_LAT                  LATCbits.LATC4
#define LED1_PORT                 PORTCbits.RC4
#define LED1_WPU                  WPUCbits.WPUC4
#define LED1_OD                   ODCONCbits.ODCC4
#define LED1_ANS                  ANSELCbits.ANSC4
#define LED1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED1_GetValue()           PORTCbits.RC4
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/