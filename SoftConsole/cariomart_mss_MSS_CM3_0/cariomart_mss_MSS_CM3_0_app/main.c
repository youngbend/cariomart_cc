#include <stdio.h>
#include "lcd.h"
#include "drivers/mss_uart/mss_uart.h"

int main() {
	LCD_init();

	LCD_startCountdown();

	while(1) {

	}
}