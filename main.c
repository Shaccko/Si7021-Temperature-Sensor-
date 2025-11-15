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

	uint32_t* fpu = CPACR;
	*fpu |= 0xF << 20; /* Set FPU bits */

	for (;;) {

		float temp_val = 0;
		si7021_read_temp(&temp_val);

		printf("temp_val %d\r\n", (int)temp_val);


		delay(500);
	}
	return 0;
}
