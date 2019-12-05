 #ifndef DEFINE_H
 #define DEFINE_H
 #define BASIC
 

#define SET_BIT_8(reg, bit)							reg |= ((uint8_t) 1 << bit)
#define CLEAR_BIT_8(reg, bit)						reg &= (~((uint8_t) 1 << bit))
#define INVERT_BIT_8(reg, bit)						reg ^= ((uint8_t) 1 << bit)
#define BIT_IS_SET_8(reg, bit)						((reg & ((uint8_t) 1 << bit)) != 0)
#define IT_IS_CLEAR_8(reg, bit)						((reg & ((uint8_t) 1 << bit)) == 0)

//delays in microseconds
#define COMMAND_DELAY								40
#define ENABLE_PULSE_WIDTH							1
#define ENABLE_CYCLE_TIME							2
#define POWER_ON_DELAY_1602							50000	
#define POWER_ON_DELAY_12864						100000
#define INIT_DELAY_1STEP_1602						
#define INIT_DELAY_2STEP_1602
#define INIT_DELAY_3STEP_1602
#define INIT_DELAY_1STEP_12864
#define INIT_DELAY_2STEP_12864
#define INIT_DELAY_3STEP_12864
#define INIT_DELAY_4STEP_12864
#define INIT_DELAY_5STEP_12864

#define ON											1
#define OFF											0

#define DDRAM										0
#define CGRAM										1
#define GDRAM										2

//control pins
#define RS_HIGH										*(volatile uint8_t*)(0x25) |= ((uint8_t) 1 << 4);
#define RS_LOW										*(volatile uint8_t*)(0x25) &= (~((uint8_t) 1 << 4));
#define ENABLE_HIGH									*(volatile uint8_t*)(0x25) |= ((uint8_t) 1 << 3);
#define ENABLE_LOW									*(volatile uint8_t*)(0x25) &= (~((uint8_t) 1 << 3));
#define READ_ON										*(volatile uint8_t*)(0x25) |= ((uint8_t) 1 << 2);
#define WRITE_ON									*(volatile uint8_t*)(0x25) &= (~((uint8_t) 1 << 2));

//main bit masks for command function
#define SCREEN_CLEAR								(uint8_t) 0b00000001
#define CURSOR_RETURN								(uint8_t) 0b00000010
#define INPUT_SET									(uint8_t) 0b00000100
#define DISPLAY_SWITCH								(uint8_t) 0b00001000
#define DISPLAY_ON									(uint8_t) 0b00000100
#define DISPLAY_OFF									(uint8_t) 0b00000000
#define CURSOR_ON									(uint8_t) 0b00000010
#define CURSOR_OFF									(uint8_t) 0b00000000
#define BLINK_ON									(uint8_t) 0b00000001
#define BLINK_OFF									(uint8_t) 0b00000000
#define SHIFT_LCD									(uint8_t) 0b00010000
#define FUNCTION_SET								(uint8_t) 0b00100000
#define CGRAM_AD_SET								(uint8_t) 0b01000000
#define DDRAM_AD_SET								(uint8_t) 0b10000000

//optional flags for command bit mask
#define INC_MODE_SET								(uint8_t) 0b00000010
#define DEC_MODE_SET								(uint8_t) 0b00000000
#define SHIFT_ACTION								(uint8_t) 0b00000001

// commands
#define LCD_CLEARDISPLAY							(uint8_t) 0x01
#define LCD_RETURNHOME								(uint8_t) 0x02
#define LCD_ENTRYMODESET							(uint8_t) 0x04
#define LCD_DISPLAYCONTROL							(uint8_t) 0x08
#define LCD_CURSORSHIFT								(uint8_t) 0x10
#define LCD_FUNCTIONSET								(uint8_t) 0x20
#define LCD_SETCGRAMADDR							(uint8_t) 0x40
#define LCD_SETDDRAMADDR							(uint8_t) 0x80
#define LCD_SETGDRAMADDR							(uint8_t) 0x80

#define LCD_EXTENDED_INSTRUCTION					(uint8_t) 0x04										//0b00000100
#define LCD_GRAPHIC_DISPLAY_ON						(uint8_t) 0x02										//0b00000010
#define LCD_GRAPHIC_DISPLAY_OFF						(uint8_t) 0x00										//0b00000000
#define SELECT_RAM_ADDRESS							(uint8_t) 0x02										//0b00000010
#define SELECT_VERTICAL_SCROLL						(uint8_t) 0x03										//0b00000011
#define STANDBY										(uint8_t) 0x01										//0b00000001

// flags for display entry mode
#define LCD_ENTRYRIGHT								(uint8_t) 0x00
#define LCD_ENTRYLEFT								(uint8_t) 0x02
#define LCD_ENTRYSHIFTINCREMENT						(uint8_t) 0x01
#define LCD_ENTRYSHIFTDECREMENT						(uint8_t) 0x00

#define DISPLAY_SHIFT								(uint8_t) 0b00001000
#define CURSOR_SHIFT								(uint8_t) 0b00000000
#define RIGHT_SHIFT									(uint8_t) 0b00000100
#define LEFT_SHIFT									(uint8_t) 0b00000000
#define FULL_DATA_BUS								(uint8_t) 0b00010000
#define HALF_DATA_BUS								(uint8_t) 0b00000000
#define DOUBLE_ROW									(uint8_t) 0b00001000
#define ONE_ROW										(uint8_t) 0b00000000
#define FONT_5_10_STYLE								(uint8_t) 0b00000100
#define FONT_5_7_STYLE								(uint8_t) 0b00000000


#endif