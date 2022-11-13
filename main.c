/*
 * new2.c
 *
 * Created: 11/4/2022 10:29:55 AM
 * Author : IPK Computers
 */ 


#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>

#define lcdport PORTA

#define signal PORTB

#define en PB2

#define rw PB1

#define rs PB0
int times = 0;
char password[1];
char lock[0];
char key;
char keycheck();

char scankey();

void lcdcmd(unsigned char cmd);

void lcdint();
void lockdoor();
unsigned char  lcd_read();

void lcddata(unsigned char data);
void send_a_command(unsigned char command);

void send_a_character(unsigned char character);

void send_a_string(char *string_of_characters);

int main()

{

	DDRA=0xff;
	DDRB=0x0f;
    DDRC=0b00000011;
	DDRF=0b00000111;
	DDRK=0b00000001;

	char key;

	lcdint();
	
	lcddata('E');
	lcddata('N');
	lcddata('T');
	lcddata('E');
	lcddata('R');
	lcddata(' ');
	lcddata('P');
	lcddata('A');
	lcddata('S');
	lcddata('S');
	lcddata('W');
	lcddata('O');
	lcddata('R');
	lcddata('D');
	lcdcmd(0xC0);
	
	for(int i=0;i<3;i++)
	{
		key=scankey();
		_delay_ms(3000);
		lcddata(key);
		password[i]=key;
		}
	lcdcmd(0x01);
	
	if((password[0]=='7')&&(password[1]=='1')&&(password[2]=='4'))
	
	{	lcddata('C');
		lcddata('O');
		lcddata('R');
		lcddata('R');
		lcddata('E');
		lcddata('C');
		lcddata('T');
		lcddata(' ');
		lcddata('P');
		lcddata('A');
		lcddata('S');
		lcddata('S');
		lcddata('W');
		lcddata('O');
		lcddata('R');
		lcddata('D');
		_delay_ms(3000);
		DDRC=0xff;
		PORTC=0x02;
		_delay_ms(3000);
		PORTC=0x00;
		lcdcmd(0x01);
		lcdcmd(0x80);
		
		
		lockdoor();
		}
		
		
		/*lcddata('L');
		lcddata('O');
		lcddata('C');
		lcddata('K');
		lcddata('?');
		lcddata(' ');
		lcddata('P');
		lcddata('R');
		lcddata('E');
		lcddata('S');
		lcddata('S');
		lcddata(' ');
		lcddata('1');
		lcdcmd(0xC0);
		
		key=scankey();
		_delay_ms(1000);
		}

		lcddata(key);
		lock[0]=key;
		if(lock[0]=='1')
		
		{   
			DDRC=0xff;
			PORTC=0x01;
			_delay_ms(3000);
			PORTC=0x00;
			lcdcmd(0x01);
			lcddata('L');
			lcddata('O');
			lcddata('C');
			lcddata('K');
			lcddata('E');
			lcddata('D');
			_delay_ms(3000);
			//exit(0);
			return main();
			}else{
				return lockdoor();
			}
		}
		
	}
	
	}*/
	else{
		
		
		lcddata('W');
		lcddata('R');
		lcddata('O');
		lcddata('N');
		lcddata('G');
		lcddata(' ');
		lcddata('P');
		lcddata('A');
		lcddata('S');
		lcddata('S');
		lcddata('W');
		lcddata('O');
		lcddata('R');
		lcddata('D');
		_delay_ms(3000);
		times++;
		if(times<3){
			return main();
		}
		else{
			
			_delay_ms(3000);
			lcdcmd(0x01);
			lcdcmd(0x80);
				lcddata('A');
				lcddata('C');
				lcddata('C');
				lcddata('E');
				lcddata('S');
				lcddata('S');
				lcddata(' ');
				lcddata('D');
			lcddata('E');
			lcddata('N');
			lcddata('I');
			lcddata('E');
			lcddata('D');
			_delay_ms(3000);
			PORTK = 0b00000001;
			return(0);
			
		}
		
		
	}
	
}



char scankey()

{

	char key='a';
	while(key=='a')
	{
		key=keycheck();
		
	}
	return key;
	}

char keycheck()

{

	PORTF=0b11111110;
	_delay_ms(500);
	if((PINF&0b00001000)==0)
	{
		
		return '1';
		
	}

	if((PINF&0b10000000)==0)

	{

		return '4';

	}

	if((PINF&0b01000000)==0)

	{

		return '7';
		

	}
	if((PINF&0b00100000)==0)
	{
		return '*';
	}

	PORTF=0b11111101;

	_delay_ms(500);

	if((PINF&0b00001000)==0)

	{

		return '2';

	}

	if((PINF&0b10000000)==0)

	{

		return '5';

	}

	if((PINF&0b01000000)==0)

	{

		return '8';

	}
	if((PINF&0b00100000)==0)
	{
		return '0';
	}

	PORTF=0b111111011;

	_delay_ms(500);

	if((PINF&0b00001000)==0)

	{

		return '3';

	}

	if((PINF&0b10000000)==0)

	{

		return '6';

	}

	if((PINF&0b01000000)==0)

	{

		return '9';

	}
	if((PINF&0b00100000)==0)
	{
		return'#';
}
return 'a';
}
	/*PORTF=0b01111111;

	_delay_ms(10);

	if((PINF&0b00000001)==0)

	{

		return '*';

	}

	if((PINF&0b00000010)==0)

	{

		return '0';

	}

	if((PINF&0b00000100)==0)

	{

		return '#';

	}
	if((PINF&0b00001000)==0)
	{
		return'D';
	}
	

	return 'a';

}*/

void lockdoor()

{  { 
	
	lcddata('L');
	lcddata('O');
	lcddata('C');
	lcddata('K');
	lcddata('?');
	lcddata(' ');
	lcddata('P');
	lcddata('R');
	lcddata('E');
	lcddata('S');
	lcddata('S');
	lcddata(' ');
	lcddata('1');
	lcdcmd(0xC0);
	}
	
	key=scankey();
	_delay_ms(3000);


lcddata(key);
lock[0]=key;
if(lock[0]=='1')

{
	DDRC=0xff;
	PORTC=0x01;
	_delay_ms(3000);
	PORTC=0x00;
	lcdcmd(0x01);
	lcddata('L');
	lcddata('O');
	lcddata('C');
	lcddata('K');
	lcddata('E');
	lcddata('D');
	_delay_ms(3000);
	//exit(0);
	return main();
	}
	
else{
	lcdcmd(0x01);
	lcdcmd(0x80);
	_delay_ms(1000);
	return lockdoor();
}
	
}

void lcdint()

{

	lcdcmd(0x38);

	_delay_ms(1);

	lcdcmd(0x01);

	_delay_ms(1);

	lcdcmd(0x0F);

	_delay_ms(100);
	lcdcmd(0x82);
	
	_delay_ms(100);
	lcdcmd(0x89);
	_delay_ms(10);
	lcdcmd(0x01);
	
}



void lcdcmd(unsigned char x)

{

	lcdport=x;

	signal=(0<<rs)|(0<<rw)|(1<<en);

	_delay_ms(10);

	signal=(0<<rs)|(0<<rw)|(0<<en);

	_delay_ms(100);

}

void lcddata(unsigned char data)

{

	lcdport= data;

	signal= (1<<rs)|(0<<rw)|(1<<en);

	_delay_ms(10);

	signal= (1<<rs)|(0<<rw)|(0<<en);

	_delay_ms(100);

}
unsigned char  lcd_read()
{
	

	signal= (1<<rs)|(1<<rw)|(1<<en);

	_delay_ms(10);

	signal= (1<<rs)|(1<<rw)|(0<<en);

	_delay_ms(100);

}
 



