 #include <avr/io.h>
 #include "define.h"
 #undef F_CPU
 #define F_CPU	16000000L
 #include <util/delay.h>
 #include <avr/interrupt.h>
 #include "lcd1602.h"

 #define PRESCALER				 (uint8_t) 0x00000001
 volatile uint32_t timer_counter = 0;
 

  //INTERRUPTS HANDLERS
 ISR(TIMER0_OVF_vect)
 {
	  if(timer_counter > 0) timer_counter--;
	  
	  //*(uint8_t*)(0x25) ^= ((uint8_t) 1 << 5);
	  //sei();
 }

void systickInit(void);
void delay(uint32_t count_val);
void setup(void);

int main(void)
{
	setup();
	     
    while (1) 
    {
		*(volatile uint8_t*)(0x25) ^= ((uint8_t) 1 << 5);
		//INVERT_BIT_8(PORTB,5);
		delay(20000);
		//_delay_ms(1);
    }
	return 0;
}


void systickInit(void)
{
	TCCR0B = PRESCALER;
	TIFR0 = 0x00;
	TIMSK0 |= (1 << TOIE0);
	GTCCR = 0x01;
	
}

void delay(uint32_t count_val)
{
	timer_counter = count_val;
	while(timer_counter != 0)
	{
	//*(volatile uint8_t*)(0x25) ^= ((uint8_t) 1 << 5);
	}
		
}

void setup(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	PORTD = 0x0;
	//printInt(16323);
	systickInit();
	initLCD(1);
	//initLCD12864(1);
	sei();
	beginLCD(16, 2, FONT_5_10_STYLE);
	//beginLCD12864(16, 2, FONT_5_7_STYLE);

	blinkOn(true);
	for(uint8_t i = 0; i < 8; i++)
	{
		writeData('g');
		_delay_ms(200);
	}
	setCursor(8,1);
	screenClear();
	printInt(16323);
	setCursor(4,0);
	printString("hello");
	_delay_ms(1000);
	screenClear();
	
	writeData('g');
	//blinkOn(OFF);
	screenClear();
	commandSet(FULL_DATA_BUS);
	_delay_us(100);
	commandSet(LCD_GRAPHIC_DISPLAY_ON);
	_delay_us(100);
	commandSet(LCD_EXTENDED_INSTRUCTION);
	_delay_us(100);
	commandSet(STANDBY);
	_delay_us(100);
	commandSet(SELECT_RAM_ADDRESS);
	_delay_us(100);
	setPosition(0, GDRAM);
	_delay_us(100);
	printString("hello");
	//_delay_us(3000);
	/*
	for(uint8_t y = 0; y < 64; y++)
	{
		for(uint8_t x = 0; x < 16; x++)
		{
			setPosition(x, GDRAM);//?
			_delay_us(100);
			setPosition(y, GDRAM);
			_delay_us(100);
			writeData('h');
			_delay_us(100);
			writeData(0x05);
			_delay_us(100);


		}
		//setPosition(i,CGRAM);
		//writeData('g');
		//_delay_ms(500);

	}
	//writeData('g');
	*/
} 