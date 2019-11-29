#include "lcd.h"
#include "drivers/mss_uart/mss_uart.h"


void LCD_init(void) {
	MSS_UART_init(
		&g_mss_uart1,
		MSS_UART_115200_BAUD,
		MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT
	);

	LCD_defaultTextSettings();
}

void LCD_clear(void) {
	uint8_t bytes[2] = { 0x7c , 0x00 };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
	LCD_setHome();
}

void LCD_printString(char* string) {
	MSS_UART_polled_tx_string( &g_mss_uart1, (uint8_t*)string);
	LCD_newLine();
}

void LCD_newLine() {
	LCD_setLineNum(++textProps.line_num);
}

void LCD_drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	uint8_t bytes[7] = { 0x7c , 0x0c , x1 , 0x7f - y1 , x2 , 0x7f - y2 , 0x01 };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_drawBox(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	uint8_t bytes[7] = { 0x7c , 0x0f , x1 , 0x7f - y1 , x2 , 0x7f - y2 , 0x01 };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_drawCircle(uint8_t x, uint8_t y, uint8_t radius) {
	uint8_t bytes[6] = { 0x7c , 0x03 , x , 0x7f - y , radius , 0x01 };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_eraseBlock(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	uint8_t bytes[6] = { 0x7c , 0x05 , x1 , 0x7f - y1 , x2 , 0x7f - y2 };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_setX(uint8_t x) {
	uint8_t bytes[3] = { 0x7c , 0x18 , x };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_setY(uint8_t y) {
	uint8_t bytes[3] = { 0x7c , 0x19 , y };
	MSS_UART_polled_tx( &g_mss_uart1, bytes, sizeof(bytes) );
}

void LCD_setHome() {
	LCD_setLineNum(0);
}

void LCD_setLineNum(int line) {
	LCD_setX(textProps.horiz_indent);
	LCD_setY((127 - textProps.vert_indent) - (line * (8 + textProps.padding)));
	textProps.line_num = line;
}

void LCD_setTextProps(int horiz_indent, int vert_indent, int padding) {
	textProps.vert_indent = vert_indent;
	textProps.horiz_indent = horiz_indent;
	textProps.padding = padding;
	LCD_setHome();
}

void LCD_defaultTextSettings() {
	textProps.horiz_indent = 1;
	textProps.vert_indent = 1;
	textProps.padding = 0;
	LCD_setHome();
}

void LCD_showRaceIntro() {
	LCD_clear();
	LCD_setTextProps(20,13,0);
	LCD_printString("Welcome to CarioMart");
	LCD_setTextProps(1,32,2);
	LCD_printString("CarioMart is the greatest");
	LCD_printString("EECS 373 project at the");
	LCD_printString("expositon.");
	LCD_printString("To play, grab a controller");
	LCD_printString("and use tilt controls to");
	LCD_printString("steer and the button to");
	LCD_printString("accelerate. To begin,");
	LCD_printString("press the button on the");
	LCD_printString("center console.");
	LCD_drawBox(9,10,150,22);
	LCD_drawBox(5,5,155,25);
	LCD_defaultTextSettings();
}

void LCD_startCountdown() {
	// Draw large 3
	LCD_clear();
	LCD_drawLine(60,30,99,30);	// top
	LCD_drawLine(60,98,99,98);	// bottom
	LCD_drawLine(99,30,99,98);	// vert
	LCD_drawLine(60,63,99,63);	// middle

	// Stall for 1 second

	// Draw large 2
	LCD_clear();
	LCD_drawLine(59,30,99,30);	// top
	LCD_drawLine(59,98,99,98);	// bottom
	LCD_drawLine(59,63,99,63);	// middle
	LCD_drawLine(99,30,99,63);
	LCD_drawLine(59,63,59,98);

	// Stall for 1 second

	// Draw large 1
	LCD_clear();
	LCD_drawLine(59,98,99,98);	// bottom
	LCD_drawLine(79,98,79,30);	// middle
	LCD_drawLine(59,38,79,30);	// top

	// Stall for 1 second

}

void LCD_showP1first() {

}

void LCD_showP2first() {

}

void LCD_startCounter() {

}

void LCD_incrementCounter() {

}

