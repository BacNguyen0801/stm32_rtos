
INCLUDE_FOLDER += \
		src\system								\
		src\services							\
		src\common								\
		src\drivers								\
		src\config

SOURCE_FILES +=	\
		src\system\nvic_controller.c				\
		src\system\sys_init.c						\
		src\system\sys_sta.c						\
		src\system\systick_timer.c					\
		src\services\os_timer.c						\
		src\drivers\stm32f1x_crc_driver.c			\
		src\drivers\stm32f1x_rcc_driver.c			\
		src\drivers\stm32f1x_rtc_driver.c			\
		src\drivers\stm32f1x_timer_driver.c			\
		src\drivers\stm32f1x_usart_driver.c			\
		src\drivers\stm32f1x_gpio_driver.c




