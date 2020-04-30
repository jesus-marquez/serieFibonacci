#include<18f4550.h>
#fuses hs//configuracion hs hasta 20Mhz
#use delay (clock=20m)
#BYTE TRISB=0x86
//definimos el puerto b para el uso del display
#define use_portB_lcd true
#include<lcd.c>//libreria para el uso del lcd
void main()
{
TRISB=0x00000000;
lcd_init();//funcion de inicio del lcd
while(1)
{
 int i, u, serie;
 i=0;
 u=1;
 serie=0;
 lcd_gotoxy(2,1);
printf(lcd_putc,"\f %i", serie);
delay_ms(300);
 do
 {
 serie=i+u;
lcd_gotoxy(2,1);
printf(lcd_putc,"\f %i", serie);
delay_ms(300);
i=u;
u=serie;
 }while(serie<50);
 serie=0;
}
}
