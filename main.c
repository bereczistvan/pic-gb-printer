/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18857
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void clkISR(void);
void update_state(uint8_t);
void reset_state(void);


enum printer_state {MAGIC0, MAGIC1, CMD, COMPR, LEN_LOW, LEN_HIGH, DATA,
                    CHECKSUM0, CHECKSUM1, ACK, P_STATUS};

/*
 * sout: Game Boy Serial Out (Printer input)
 * sin: Game Boy Serial In (Printer output)
 * bits: Bit counter
 * printer_data_len: Number of data bytes in a packet
 * printer_state: Current position in a packet
 */
uint8_t sout;
uint8_t sin;
uint8_t bits;
uint16_t printer_data_len;
enum printer_state printer_state;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // Set the External Interrupt Handler
    INT_SetInterruptHandler(clkISR);
    
    bits = 0;
    sout = 0;
    sin = 0;
    printer_data_len = 0;
    printer_state = MAGIC0;

    while (1)
    {
        if (!BUTTON1_PORT)
        {
            reset_state();
        }
    }
}

void clkISR(void)
{
    sout |= SOUT_PORT;
    if(sin & 0x80)
        SIN_PORT = 1;
    else
        SIN_PORT = 0;
    bits++;
    
    if (bits == 8)
    {
        if (printer_state == DATA)
        {
            EUSART_Write(sout);
        }
        update_state(sout);
        sout = 0;
        bits = 0;
        if (printer_state == ACK)
        {
            sin = 0x81;
            SIN_PORT = 1;
            sin <<= 1;
        }
    }
    else
    {
        sout <<= 1;
        sin <<= 1;
    }
}

/*
 * Update printer state based on current input byte and current state
 */
void update_state(uint8_t b)
{
    switch (printer_state)
    {
        case MAGIC0:
            if (b==0x88)
                printer_state = MAGIC1;
            break;
            
        case MAGIC1:
            if (b==0x33)
                printer_state = CMD;
            break;
            
        case CMD:
            printer_state = COMPR;
            break;
            
        case COMPR:
            printer_state = LEN_LOW;
            break;
            
        case LEN_LOW:
            printer_data_len = (uint16_t)b;
            printer_state = LEN_HIGH;
            break;
            
        case LEN_HIGH:
            printer_data_len |= (uint16_t)(b << 8);
            if (printer_data_len != 0)
                printer_state = DATA;
            else
                printer_state = CHECKSUM0;
            break;
            
        case DATA:
            printer_data_len--;
            if (printer_data_len !=0)
                printer_state = DATA;
            else
                printer_state = CHECKSUM0;
            break;
            
        case CHECKSUM0:
            printer_state = CHECKSUM1;
            break;
            
        case CHECKSUM1:
            printer_state = ACK;
            break;
            
        case ACK:
            printer_state = P_STATUS;
            break;
            
        case P_STATUS:
            printer_state = MAGIC0;
            break;
    }
}

void reset_state(void)
{
    bits = 0;
    sout = 0;
    sin = 0;
    printer_data_len = 0;
    printer_state = MAGIC0;
    __delay_ms(250);
}
/**
 End of File
*/