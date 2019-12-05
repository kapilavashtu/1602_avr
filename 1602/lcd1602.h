#pragma once
#include <inttypes.h>
#undef F_CPU
#define F_CPU	16000000L
#include <util/delay.h>

#include "define.h"

extern uint8_t display_function;
extern uint8_t numlines;
extern uint8_t display_control;
extern uint8_t display_mode;
 

void initLCD(uint8_t row);
void beginLCD(uint8_t columns, uint8_t rows,uint8_t dot_style);


uint8_t readBusyFlag(void);
uint8_t readData(uint8_t data);
uint8_t readInstruction(uint8_t command);

void writeData(uint8_t data);

void screenClear(void);
void blinkOn(uint8_t state);
void cursorReturn(void);

void displaySwitch(uint8_t state);
void shift(uint8_t flags);
void setCursor(uint8_t column, uint8_t row);
void printChar(uint8_t character);
void printInt(int16_t val);
void printString(const char * string);
extern void commandSet(uint8_t flags);
void pulseEnable(void);

void initLCD12864(uint8_t bitmode);
void beginLCD12864(uint8_t columns, uint8_t rows, uint8_t dot_style);
void setPosition(uint8_t pos, uint8_t area);