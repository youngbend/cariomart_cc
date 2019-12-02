#include "lcd.h"
#include "utility.h"
#include "xbee.h"
#include "drivers/mss_uart/mss_uart.h"

int race_status;

int main() {
	LCD_init();
	XBEE_init();

	while(1) {
		LCD_showRaceIntro();

		while (race_status == 0);

		LCD_countdown();

		// Broadcast the race status
		XBEE_send("0,1");

		LCD_startTimer();

		int leaderboard_shown = 0, lap_stats = 1;
		p1lap = 1, p2lap = 1;

		while (1) {
			// Show the leaderboard if any player is in second lap
			if (!leaderboard_shown && (p1lap > 1 || p2lap > 1)) {
				LCD_showLeaderboard();
				leaderboard_shown = 1;
			}

			// Check for a winner
			if ()

			// Update the leaderboard when someone crosses the finish line
			if (leaderboard_shown && lap_stats == p1lap && p2lap > p1lap) {
				LCD_showP2first();
				++lap_stats;
			}
			else if (leaderboard_shown && lap_stats == p2lap && p1lap > p2lap) {
				LCD_showP1first();
				++lap_stats;
			}
			else lap_stats = (p1lap > p2lap) ? p1lap : p2lap;

			//
		}
	}
}
