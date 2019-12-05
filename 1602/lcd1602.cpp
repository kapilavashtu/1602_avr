#include "lcd1602.h"
#include "define.h"

uint8_t display_function;
uint8_t numlines;
uint8_t display_control;
uint8_t display_mode;

void initLCD(uint8_t bitmode)
{
#ifdef BASIC
	if (bitmode) display_function = FULL_DATA_BUS | ONE_ROW | FONT_5_7_STYLE;
	else display_function = HALF_DATA_BUS | ONE_ROW | FONT_5_7_STYLE;
	beginLCD(16, 1, FONT_5_7_STYLE);
#endif

#ifdef EXTENDED
	if (bitmode) display_function = FULL_DATA_BUS | ONE_ROW | LCD_EXTENDED_INSTRUCTION;
	else display_function = HALF_DATA_BUS | ONE_ROW | LCD_EXTENDED_INSTRUCTION;
	beginLCD(16, 1, FONT_5_7_STYLE);
#endif
	
}

void beginLCD(uint8_t columns, uint8_t rows, uint8_t dot_style)
{
#ifdef BASIC
	if (rows > 1) display_function |= DOUBLE_ROW;
	numlines = rows;
	
	_delay_us(50000);
	RS_LOW
	ENABLE_LOW
	WRITE_ON
	
	commandSet(FUNCTION_SET | display_function);
	_delay_us(4500);
	commandSet(FUNCTION_SET | display_function);
	_delay_us(150);
	commandSet(FUNCTION_SET | display_function);
	commandSet(FUNCTION_SET | display_function);

	display_control = DISPLAY_ON | CURSOR_OFF | BLINK_OFF;
	displaySwitch(ON);
	screenClear();

	display_mode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	commandSet(LCD_ENTRYMODESET | display_mode);
#endif

#ifdef EXTENDED
	if (rows > 1) display_function |= DOUBLE_ROW;
	numlines = rows;
	
	_delay_us(50000);
	RS_LOW
	ENABLE_LOW
	WRITE_ON
	
	commandSet(FUNCTION_SET | display_function);
	_delay_us(4500);
	commandSet(FUNCTION_SET | display_function);
	_delay_us(150);
	commandSet(FUNCTION_SET | display_function);
	commandSet(FUNCTION_SET | display_function);

	display_control = DISPLAY_ON | CURSOR_OFF | BLINK_OFF;
	displaySwitch(ON);
	screenClear();

	display_mode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	commandSet(LCD_ENTRYMODESET | display_mode);
#endif	

}

void initLCD12864(uint8_t bitmode)
{
	if (bitmode) display_function = FULL_DATA_BUS | ONE_ROW | FONT_5_7_STYLE;
	else display_function = HALF_DATA_BUS | ONE_ROW | FONT_5_7_STYLE;
	beginLCD(16, 1, FONT_5_7_STYLE);
}

void beginLCD12864(uint8_t columns, uint8_t rows, uint8_t dot_style)
{
	if (rows > 1) display_function |= DOUBLE_ROW;
	numlines = rows;
	
	_delay_us(100000);
	RS_LOW
	ENABLE_LOW
	WRITE_ON
	
	commandSet(FUNCTION_SET | display_function);
	_delay_us(150);
	commandSet(FUNCTION_SET | display_function);
	_delay_us(50);
	
	display_control = DISPLAY_ON | CURSOR_OFF | BLINK_OFF;
	displaySwitch(ON);
	_delay_us(150);
	screenClear();
	_delay_us(20);

	display_mode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	commandSet(LCD_ENTRYMODESET | display_mode);

}

void blinkOn(uint8_t state)
{
	if(state) display_control |=  BLINK_ON;
	else display_control = BLINK_OFF;
	
	commandSet(LCD_DISPLAYCONTROL | display_control);

}

uint8_t readBusyFlag(void)
{
	return 0;
}

uint8_t readInstruction(uint8_t command)
{
	return 0;
}

void writeData(uint8_t data)
{
	RS_HIGH
	ENABLE_LOW
	WRITE_ON
	*(volatile uint8_t*)(0x2B) = data;
	pulseEnable();
}

uint8_t readData(uint8_t data)
{
	return 0;
}

void screenClear(void)
{
	commandSet(SCREEN_CLEAR);
	_delay_us(2000);
}

void cursorReturn(void)
{


}

void displaySwitch(uint8_t state)
{
	display_control |= (state ? DISPLAY_ON : DISPLAY_OFF);
	commandSet(DISPLAY_SWITCH | display_control);
}

void shift(uint8_t flags)
{


}

void commandSet(uint8_t flags)
{
	RS_LOW
	ENABLE_LOW
	WRITE_ON
	*(volatile uint8_t*)(0x2B) = flags;
	pulseEnable();
}

void pulseEnable(void)
{
	ENABLE_LOW
	_delay_us(1);
	ENABLE_HIGH
	_delay_us(1);
	ENABLE_LOW
	_delay_us(100);
}

void setCursor(uint8_t column, uint8_t row)
{
	switch(row)
	{
		case 0:
		commandSet(LCD_SETDDRAMADDR | column);
		break;

		case 1:
		commandSet(LCD_SETDDRAMADDR | 0x40 | column);
		break;
	}
}

void printChar(uint8_t character)
{
	writeData(character);
}

void printInt(int16_t val)
{
	if (val < 0)
	{
		writeData('-');
		val = -val;
	}
	if (val / 10)
	{
		printInt(val / 10);
	}
	writeData(val % 10 + '0');
	//_delay_us(500);
}

void printString(const char *string)
{
	while(*string) 
	{
		writeData(*string);
		string++;
	}

}

void setPosition(uint8_t pos, uint8_t area)
{
	switch(area)
	{
		case DDRAM:
		commandSet(LCD_SETDDRAMADDR | pos);
		break;

		case CGRAM:
		commandSet(LCD_SETCGRAMADDR | (pos & 0x3F));
		break;

		case GDRAM:
		commandSet(LCD_SETGDRAMADDR | (pos & 0x3F));
		break;

	}
	_delay_us(80);
	
}