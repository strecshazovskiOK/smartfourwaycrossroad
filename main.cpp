#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
//LCD Initialize params
// PORT A NORTH
// PORT B WEST 
// PORT C South 
// PORT D East 
#define LCD_PortA PORTA
#define LCD_APin DDRA
#define RSPINA PA0
#define ENPINA PA1
#define LCD_PortB PORTB
#define LCD_BPin DDRB
#define RSPINB PB0
#define ENPINB PB1
#define LCD_PortD PORTD
#define LCD_DPin DDRD
#define RSPIND PD0
#define ENPIND PD1
#define LCD_PortC PORTC
#define LCD_CPin DDRC
#define RSPINC PC0
#define ENPINC PC1

void LCD_ActionA( unsigned char cmnd)
{
	LCD_PortA = (LCD_PortA & 0X0F) | (cmnd & 0XF0);
	LCD_PortA &= ~ (1<<RSPINA);
	LCD_PortA |= (1<<ENPINA);
	_delay_us(1);
	LCD_PortA &= ~ (1<<ENPINA);
	_delay_us(200);
	LCD_PortA = (LCD_PortA & 0X0F) | (cmnd << 4);
	LCD_PortA |= (1<<ENPINA);
	_delay_us(1);
	LCD_PortA &= ~ (1<<ENPINA);
	_delay_ms(2);
}

void LCD_ClearA() //Clear function for LCDA
{
	LCD_ActionA(0X01);
	_delay_ms(5);
	LCD_ActionA(0X80);
}

void LCD_PrintA(char *str)// this function do the print for LCDA
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_PortA = (LCD_PortA & 0X0F) | (str[i] & 0XF0);
		LCD_PortA |= (1<<RSPINA);
		LCD_PortA |= (1<<ENPINA);
		_delay_us(1);
		LCD_PortA &= ~(1<<ENPINA);
		_delay_us(200);
		LCD_PortA = (LCD_PortA & 0X0F) | (str[i] << 4);
		LCD_PortA |= (1<<ENPINA);
		_delay_us(1);
		LCD_PortA &= ~ (1<<ENPINA);
		_delay_ms(2);
	}
}
//Write on a specific location LCDA
void LCD_PrintposA(char row, char pos, char *str)
{
	if(row == 0 && pos<16)
	LCD_ActionA((pos & 0X0F) | 0X80);
	else if(row==1 & pos<16)
	LCD_ActionA((pos & 0X0F) | 0XC0);
	LCD_PrintA(str);
}
//INITIALIZE FUNCTION FOR LCDA
void LCD_InitA(void)
{
	LCD_APin = 0XFF;
	_delay_ms(15);
	LCD_ActionA(0X02);
	LCD_ActionA(0X28);
	LCD_ActionA(0X0c);
	LCD_ActionA(0X06);
	LCD_ActionA(0X01);
	_delay_ms(2);
}
//LCD functions FOR LCD B (WEST)
void LCD_ActionB( unsigned char cmnd)
{
	LCD_PortB = (LCD_PortB & 0X0F) | (cmnd & 0XF0);
	LCD_PortB &= ~ (1<<RSPINB);
	LCD_PortB |= (1<<ENPINB);
	_delay_us(1);
	LCD_PortB &= ~ (1<<ENPINB);
	_delay_us(200);
	LCD_PortB = (LCD_PortB & 0X0F) | (cmnd << 4);
	LCD_PortB |= (1<<ENPINB);
	_delay_us(1);
	LCD_PortB &= ~ (1<<ENPINB);
	_delay_ms(2);
}
//LCD CLEAR B
void LCD_ClearB()
{
	LCD_ActionB(0X01);
	_delay_ms(5);
	LCD_ActionB(0X80);
}
//LCD B PRINT
void LCD_PrintB(char *str)
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_PortB = (LCD_PortB & 0X0F) | (str[i] & 0XF0);
		LCD_PortB |= (1<<RSPINB);
		LCD_PortB |= (1<<ENPINB);
		_delay_us(1);
		LCD_PortB &= ~(1<<ENPINB);
		_delay_us(200);
		LCD_PortB = (LCD_PortB & 0X0F) | (str[i] << 4);
		LCD_PortB |= (1<<ENPINB);
		_delay_us(1);
		LCD_PortB &= ~ (1<<ENPINB);
		_delay_ms(2);
	}
}
//Write on a specific location LCDB
void LCD_PrintposB(char row, char pos, char *str)
{
	if(row == 0 && pos<16)
	LCD_ActionB((pos & 0X0F) | 0X80);
	else if(row==1 & pos<16)
	LCD_ActionB((pos & 0X0F) | 0XC0);
	LCD_PrintB(str);
}
// Initilialize LCD B
void LCD_InitB(void)
{
	LCD_BPin = 0XFF;
	_delay_ms(15);
	LCD_ActionB(0X02);
	LCD_ActionB(0X28);
	LCD_ActionB(0X0c);
	LCD_ActionB(0X06);
	LCD_ActionB(0X01);
	_delay_ms(2);
}

//LCD functions FOR LCD D (EAST)
void LCD_ActionD( unsigned char cmnd)
{
	LCD_PortD = (LCD_PortD & 0X0F) | (cmnd & 0XF0);
	LCD_PortD &= ~ (1<<RSPIND);
	LCD_PortD |= (1<<ENPIND);
	_delay_us(1);
	LCD_PortD &= ~ (1<<ENPIND);
	_delay_us(200);
	LCD_PortD = (LCD_PortD & 0X0F) | (cmnd << 4);
	LCD_PortD |= (1<<ENPIND);
	_delay_us(1);
	LCD_PortD &= ~ (1<<ENPIND);
	_delay_ms(2);
}
//LCD D CLEAR
void LCD_ClearD()
{
	LCD_ActionD(0X01);
	_delay_ms(2);
	LCD_ActionD(0X80);
}
//LCD D PRINT 
void LCD_PrintD(char *str)
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_PortD = (LCD_PortD & 0X0F) | (str[i] & 0XF0);
		LCD_PortD |= (1<<RSPIND);
		LCD_PortD |= (1<<ENPIND);
		_delay_us(1);
		LCD_PortD &= ~(1<<ENPIND);
		_delay_us(200);
		LCD_PortD = (LCD_PortD & 0X0F) | (str[i] << 4);
		LCD_PortD |= (1<<ENPIND);
		_delay_us(1);
		LCD_PortD &= ~ (1<<ENPIND);
		_delay_ms(2);
	}
}
//Write on a specific location LCD D
void LCD_PrintposD(char row, char pos, char *str)
{
	if(row == 0 && pos<16)
	LCD_ActionD((pos & 0X0F) | 0X80);
	else if(row==1 & pos<16)
	LCD_ActionD((pos & 0X0F) | 0XC0);
	LCD_PrintD(str);
}
//INITIALIZE LCD A
void LCD_InitD(void)
{
	LCD_DPin = 0XFF;
	_delay_ms(15);
	LCD_ActionD(0X02);
	LCD_ActionD(0X28);
	LCD_ActionD(0X0c);
	LCD_ActionD(0X06);
	LCD_ActionD(0X01);
	_delay_ms(2);
}
//LCD C SOUTH
void LCD_ActionC( unsigned char cmnd)
{
	LCD_PortC = (LCD_PortC & 0X0F) | (cmnd & 0XF0);
	LCD_PortC &= ~ (1<<RSPINC);
	LCD_PortC |= (1<<ENPINC);
	_delay_us(1);
	LCD_PortC &= ~ (1<<ENPINC);
	_delay_us(200);
	LCD_PortC = (LCD_PortC & 0X0F) | (cmnd << 4);
	LCD_PortC |= (1<<ENPINC);
	_delay_us(1);
	LCD_PortC &= ~ (1<<ENPINC);
	_delay_ms(2);
}
//LCD C CLEAR 
void LCD_ClearC()
{
	LCD_ActionC(0X01);
	_delay_ms(2);
	LCD_ActionC(0X80);
}
//LCD C PRINT 
void LCD_PrintC(char *str)
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_PortC = (LCD_PortC & 0X0F) | (str[i] & 0XF0);
		LCD_PortC |= (1<<RSPINC);
		LCD_PortC |= (1<<ENPINC);
		_delay_us(1);
		LCD_PortC &= ~(1<<ENPINC);
		_delay_us(200);
		LCD_PortC = (LCD_PortC & 0X0F) | (str[i] << 4);
		LCD_PortC |= (1<<ENPINC);
		_delay_us(1);
		LCD_PortC &= ~ (1<<ENPINC);
		_delay_ms(2);
	}
}
//Write on a specific location LCD C
void LCD_PrintposC(char row, char pos, char *str)
{
	if(row == 0 && pos<16)
	LCD_ActionC((pos & 0X0F) | 0X80);
	else if(row==1 & pos<16)
	LCD_ActionC((pos & 0X0F) | 0XC0);
	LCD_PrintC(str);
}
//LCD INITIALIZE C
void LCD_InitC(void)
{
	LCD_CPin = 0XFF;
	_delay_ms(15);
	LCD_ActionC(0X02);
	LCD_ActionC(0X28);
	LCD_ActionC(0X0c);
	LCD_ActionC(0X06);
	LCD_ActionC(0X01);
	_delay_ms(2);
}
int main(void)
{
	//PORTE P0 WEST BUTTON
	//PORTE P1 SOUTH BUTTON
	//PORTE P2-P3-P4 NORTH
	//PORTE P5-P6-P7 EAST
	DDRE=0x00;
	
	//initialize LCDs
	LCD_InitA();
	LCD_InitB();
	LCD_InitD();
	LCD_InitC();
	 int MainRoadcounterNorth;
	 int MainRoadcounterEast;
	 int southCounter;
	 int WestCounter;
	while (1)
	{	
		MainRoadcounterNorth = 0;
		MainRoadcounterEast = 0;
		southCounter=0;
		WestCounter=0;
		if(!(PINE & (1 << PE0)))
		{
			
			WestCounter=1;
			//LCD_PrintA("Button cal˝˛˝yor!");
		}
		if(!(PINE & (1 << PE1)))
		{
			
			southCounter=1;
			
			//LCD_PrintD("South Button cal˝˛˝yor!");
		}
		if(!(PINE & (1 << PE2)))
		{
			
			MainRoadcounterNorth++;
			//LCD_PrintA("Button cal˝˛˝yor!");
		}
		if(!(PINE & (1 << PE3)))
		{
			
			MainRoadcounterNorth++;
			
			//LCD_PrintD("South Button cal˝˛˝yor!");
		}
		
		if(!(PINE & (1 << PE4)))
		{
			
			MainRoadcounterNorth++;
			//LCD_PrintA("Button cal˝˛˝yor!");
		}
		if(!(PINE & (1 << PE5)))
		{
			
			MainRoadcounterEast++;
			
			//LCD_PrintD("South Button cal˝˛˝yor!");
		}
		
		if(!(PINE & (1 << PE6)))
		{
			
			MainRoadcounterEast++;
			//LCD_PrintA("Button cal˝˛˝yor!");
		}
		if(!(PINE & (1 << PE7)))
		{
			
			MainRoadcounterEast++;
			
			//LCD_PrintD("South Button cal˝˛˝yor!");
		}
		if(MainRoadcounterEast!=0||MainRoadcounterNorth!=0)
		{
			//LCD_PrintA("ikisi de 0 deil!");
			if(MainRoadcounterNorth>=MainRoadcounterEast)
			{	
				LCD_ClearA();
				LCD_ClearB();
				LCD_ClearC();
				LCD_ClearD();
				LCD_PrintA("YELLOW!!");//NORTH
				
				LCD_PrintD("YELLOW!!");//EAST
				_delay_ms(15);
				LCD_ClearD();
				LCD_PrintD("RED!!");
				
				LCD_PrintB("YELLOW!!");//WEST
				_delay_ms(15);
				LCD_ClearB();
				LCD_PrintB("RED!!");
				
				LCD_PrintC("YELLOW!!");//SOUTH
				_delay_ms(15);
				LCD_ClearC();
				LCD_PrintC("RED!!");
				
				LCD_ClearA();
				_delay_ms(15);
				LCD_PrintA("GREEN!!");//NORTH green
				_delay_ms(1000);
			}
			else
			{
				LCD_ClearA();
				LCD_ClearB();
				LCD_ClearC();
				LCD_ClearD();
				
				LCD_PrintD("YELLOW!!");//EAST
				
				LCD_PrintA("YELLOW!!");//NORTH
				_delay_ms(15);
				LCD_ClearA();
				LCD_PrintA("RED!!");
				
				LCD_PrintB("YELLOW!!");//WEST
				_delay_ms(15);
				LCD_ClearB();
				LCD_PrintB("RED!!");
				
				
				
				LCD_PrintC("YELLOW!!");//SOUTH
				_delay_ms(15);
				LCD_ClearC();
				LCD_PrintC("RED!!");
				
				
				LCD_ClearD();
				_delay_ms(15);
				LCD_PrintD("GREEN!!");//East green
				_delay_ms(1000);
				
			}
		}
		else
		{
			
			if(southCounter<WestCounter)
			{	
				LCD_ClearA();
				LCD_ClearB();
				LCD_ClearC();
				LCD_ClearD();
				
				LCD_PrintB("YELLOW!!");//WEST
				_delay_ms(15);
				
				LCD_PrintA("YELLOW!!");//NORTH
				_delay_ms(15);
				LCD_ClearA();
				LCD_PrintA("RED!!");
				
				LCD_PrintC("YELLOW!!");//SOUTH
				_delay_ms(15);
				LCD_ClearC();
				LCD_PrintC("RED!!");
				
				LCD_PrintD("YELLOW!!");//EAST
				_delay_ms(15);
				LCD_ClearD();
				LCD_PrintD("RED!!");
				
				LCD_ClearB();
				_delay_ms(15);
				LCD_PrintB("GREEN!!");//WEST green
				_delay_ms(1000);
				
			}
			else if(southCounter>=WestCounter&&(southCounter!=0&&WestCounter!=0))
			{
				LCD_ClearA();
				LCD_ClearB();
				LCD_ClearC();
				LCD_ClearD();
				
				LCD_PrintC("YELLOW!!");//SOUTH
				_delay_ms(15);
				
				LCD_PrintA("YELLOW!!");//NORTH
				_delay_ms(15);
				LCD_ClearA();
				LCD_PrintA("RED!!");
				
				LCD_PrintB("YELLOW!!");//WEST
				_delay_ms(15);
				LCD_ClearB();
				LCD_PrintB("RED!!");
				
				LCD_PrintD("YELLOW!!");//EAST
				_delay_ms(15);
				LCD_ClearD();
				LCD_PrintD("RED!!");
				
				LCD_ClearC();
				_delay_ms(15);
				LCD_PrintC("GREEN!!");//SOUTH green
				_delay_ms(1000);
				
				
			}
		}
		
	}

}
