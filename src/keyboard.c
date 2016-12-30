/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "string.h"
#include "console.h"
#include "ioports.h"
#include "interrupt.h"
#include "ascii.h"
#include "process.h"
#include "kernelcore.h"
#include "string.h"


#define KEYBOARD_PORT 0x60

#define KEY_INVALID 0127

string readStr()
{

    string buffstr = (string) kmalloc(200);
    uint8_t i = 0;
    uint8_t reading = 1;
    while(reading)
    {
        if(inb(0x64) & 0x1)                 
        {
            switch(inb(0x60))
            { 
      /*case 1:
                console_putchar('(char)27);           Escape button
                buffstr[i] = (char)27;
                i++;
                break;*/
        case 2:
                console_putchar('1');
                buffstr[i] = '1';
                i++;
                break;
        case 3:
                console_putchar('2');
                buffstr[i] = '2';
                i++;
                break;
        case 4:
                console_putchar('3');
                buffstr[i] = '3';
                i++;
                break;
        case 5:
                console_putchar('4');
                buffstr[i] = '4';
                i++;
                break;
        case 6:
                console_putchar('5');
                buffstr[i] = '5';
                i++;
                break;
        case 7:
                console_putchar('6');
                buffstr[i] = '6';
                i++;
                break;
        case 8:
                console_putchar('7');
                buffstr[i] = '7';
                i++;
                break;
        case 9:
                console_putchar('8');
                buffstr[i] = '8';
                i++;
                break;
        case 10:
                console_putchar('9');
                buffstr[i] = '9';
                i++;
                break;
        case 11:
                console_putchar('0');
                buffstr[i] = '0';
                i++;
                break;
        case 12:
                console_putchar('-');
                buffstr[i] = '-';
                i++;
                break;
        case 13:
                console_putchar('=');
                buffstr[i] = '=';
                i++;
                break;
        case 14:
                console_putchar('\b');
                i--;
                if(i<0)
                {
                	i = 0;
                }
                buffstr[i+1] = 0;
                buffstr[i] = 0;
                break;
       /* case 15:
                console_putchar('\t');          Tab button
                buffstr[i] = '\t';
                i++;
                break;*/
        case 16:
                console_putchar('q');
                buffstr[i] = 'q';
                i++;
                break;
        case 17:
                console_putchar('w');
                buffstr[i] = 'w';
                i++;
                break;
        case 18:
                console_putchar('e');
                buffstr[i] = 'e';
                i++;
                break;
        case 19:
                console_putchar('r');
                buffstr[i] = 'r';
                i++;
                break;
        case 20:
                console_putchar('t');
                buffstr[i] = 't';
                i++;
                break;
        case 21:
                console_putchar('y');
                buffstr[i] = 'y';
                i++;
                break;
        case 22:
                console_putchar('u');
                buffstr[i] = 'u';
                i++;
                break;
        case 23:
                console_putchar('i');
                buffstr[i] = 'i';
                i++;
                break;
        case 24:
                console_putchar('o');
                buffstr[i] = 'o';
                i++;
                break;
        case 25:
                console_putchar('p');
                buffstr[i] = 'p';
                i++;
                break;
        case 26:
                console_putchar('[');
                buffstr[i] = '[';
                i++;
                break;
        case 27:
                console_putchar(']');
                buffstr[i] = ']';
                i++;
                break;
        case 28:
                 console_putchar('\n');
                 buffstr[i] = '\n';
                  i++;
               reading = 0;
                break;
      /*  case 29:
                console_putchar('q');           Left Control
                buffstr[i] = 'q';
                i++;
                break;*/
        case 30:
                console_putchar('a');
                buffstr[i] = 'a';
                i++;
                break;
        case 31:
                console_putchar('s');
                buffstr[i] = 's';
                i++;
                break;
        case 32:
                console_putchar('d');
                buffstr[i] = 'd';
                i++;
                break;
        case 33:
                console_putchar('f');
                buffstr[i] = 'f';
                i++;
                break;
        case 34:
                console_putchar('g');
                buffstr[i] = 'g';
                i++;
                break;
        case 35:
                console_putchar('h');
                buffstr[i] = 'h';
                i++;
                break;
        case 36:
                console_putchar('j');
                buffstr[i] = 'j';
                i++;
                break;
        case 37:
                console_putchar('k');
                buffstr[i] = 'k';
                i++;
                break;
        case 38:
                console_putchar('l');
                buffstr[i] = 'l';
                i++;
                break;
        case 39:
                console_putchar(';');
                buffstr[i] = ';';
                i++;
                break;
        case 40:
                console_putchar((char)44);               //   Single quote (')
                buffstr[i] = (char)44;
                i++;
                break;
        case 41:
                console_putchar((char)44);               // Back tick (`)
                buffstr[i] = (char)44;
                i++;
                break;
     /* case 42:                                 Left shift 
                console_putchar('q');
                buffstr[i] = 'q';
                i++;
                break;
        case 43:                                 \ (< for somekeyboards)   
                console_putchar((char)92);
                buffstr[i] = 'q';
                i++;
                break;*/
        case 44:
                console_putchar('z');
                buffstr[i] = 'z';
                i++;
                break;
        case 45:
                console_putchar('x');
                buffstr[i] = 'x';
                i++;
                break;
        case 46:
                console_putchar('c');
                buffstr[i] = 'c';
                i++;
                break;
        case 47:
                console_putchar('v');
                buffstr[i] = 'v';
                i++;
                break;                
        case 48:
                console_putchar('b');
                buffstr[i] = 'b';
                i++;
                break;               
        case 49:
                console_putchar('n');
                buffstr[i] = 'n';
                i++;
                break;                
        case 50:
                console_putchar('m');
                buffstr[i] = 'm';
                i++;
                break;               
        case 51:
                console_putchar(',');
                buffstr[i] = ',';
                i++;
                break;                
        case 52:
                console_putchar('.');
                buffstr[i] = '.';
                i++;
                break;            
        case 53:
                console_putchar('/');
                buffstr[i] = '/';
                i++;
                break;            
        case 54:
                console_putchar('.');
                buffstr[i] = '.';
                i++;
                break;            
        case 55:
                console_putchar('/');
                buffstr[i] = '/';
                i++;
                break;            
      /*case 56:
                console_putchar(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break;*/           
        case 57:
                console_putchar(' ');
                buffstr[i] = ' ';
                i++;
                break;
            }
        }
      
    }
    return buffstr;
}