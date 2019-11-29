#ifndef LCD_H
#define LCD_H

#include <inttypes.h>

typedef struct {
	int line_num;
	int horiz_indent;
	int vert_indent;
	int padding;
} PropsStruct;

float time;

PropsStruct textProps;

// Initialize the LCD display
void LCD_init(void);

// Clear the screen
void LCD_clear(void);

// Print string to LCD (maximum of 26 characters) and goes to a new line
void LCD_printString(char* string);

// Goes to the next line
void LCD_newLine();

// Draw a line between two points
// X range from 0 to 159, Y range from 0 to 127
void LCD_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

// Draw a box on the screen from two points
void LCD_drawBox(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

// Draw a circle on the screen given center point and radius
void LCD_drawCircle(uint8_t x, uint8_t y, uint8_t radius);

// Erase a block of pixels given two corners of the box in x and y coordinates
void LCD_eraseBlock(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

// Set printing position of the display. Values between 0 and 154 are allowed
void LCD_setX(uint8_t x);

// Set printing position of the display. Values between 0 and 120 are allowed
void LCD_setY(uint8_t y);

// Bring printing back to starting position
void LCD_setHome();

// Set line number to write on
void LCD_setLineNum(int line);

// Set properties for text printing and reset line number to 0
void LCD_setTextProps(int horiz_indent, int vert_indent, int padding);

// Restore default text settings;
void LCD_defaultTextSettings();

// Show the introduction to the race;
void LCD_showRaceIntro();

// Starting animation for the race
void LCD_startCountdown();

// Display race positions with player 1 in first
void LCD_showP1first();

// Display race positions with player 2 in first
void LCD_showP2first();

// Display race time starting from 0
void LCD_startCounter();

// Increment race time by 1 seconds (to be used in periodic interrupt)
void LCD_incrementCounter();


#endif
