/*
 * create_all_timers.c
 *
 * Created: 5/10/2019 1:59:04 PM
 *  Author: drags
 */ 

#include "../Headers/m_lora_includes.h"


void timer_callback(TimerHandle_t pxTimer);

TimerHandle_t xTimer;

void create_all_timers()
{
	xTimer = xTimerCreate("5 minutes timer",
			(10000/portTICK_PERIOD_MS),
			pdTRUE,
			(void *)0,
			timer_callback);
}