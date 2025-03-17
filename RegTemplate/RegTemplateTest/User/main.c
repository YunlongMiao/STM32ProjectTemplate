#include "./SYSTEM/sys/sys.h" 
#include "./SYSTEM/usart/usart.h" 
#include "./SYSTEM/delay/delay.h"


int main(void) {
	
		uint8_t t = 0; 
		sys_stm32_clock_init(336, 8, 2, 7);
		delay_init(168); 
		usart_init(84, 115200);
	
		while (1) {
			printf("t:%d\r\n", t); 
			delay_ms(500); t++;
		}
		
		
}
