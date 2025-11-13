#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include <rcc.h>
#include <hal.h>
#include <uart.h>
#include <i2c.h>
#include <si7021.h>

int main(void) {
	/* Configure hal.h to hold pin bank and pins, 32bits can fit both */

	uart2_init();
	i2c1_init();

	systick_init();

	for (;;) {
		float temp_val;
		si7021_read_temp(&temp_val);

		/* Probably getting stuck on a flag poll loop */
		printf("Temp val: %d", (int)temp_val);
		printf("done\r\n");
		delay(500);
	}
	return 0;
}
