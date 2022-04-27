#define led PORTE.RD1
#define sw  PORTE.RD0

sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


void main() {
     
     TRISB = 0;

     TRISE = 0b00000001;        // configura��o de porta digital RE0 como entrada
     PORTE = 0b00000000;       
     OPTION_REG = 0x0E; //watchdog

     Lcd_init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1,1,"INICIANDO ALARME");
     delay_ms(4000);

  while(1){

     if(sw){       //ALARME ATIVADO
      led = 0x01;
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Cmd(_LCD_CURSOR_OFF);
      Lcd_Out(1,1,"ALARME DISPARADO");
      delay_ms(1000);
     }
     else{
      led = 0x00;
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Cmd(_LCD_CURSOR_OFF);
      Lcd_Out(1,1,"ALARME ATIVO");
      delay_ms(1000);
     }
  }
}