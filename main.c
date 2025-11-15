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

	volatile uint32_t* fpu = CPACR;
	*fpu |= 0xF << 20; /* Set FPU bits */

	si7021_get_firmware();

	for (;;) {

		double temp_val = 0.0f;
		si7021_read_temp(&temp_val);

		/* 5kb worth operation wowee */
		/* Also float is unrepresented, would need implementation etc, so just gonna cast to int */
		printf("temp_val %d\r\n", (int)temp_val);


		delay(500);
	}
	return 0;
}
