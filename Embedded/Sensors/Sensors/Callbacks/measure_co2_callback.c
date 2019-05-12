/*
 * measure_co2_callback.c
 *
 * Created: 5/11/2019 6:00:59 PM
 *  Author: drags
 */ 

#include "../Headers/m_lora_includes.h"

SemaphoreHandle_t xSemaphore_co2;
MessageBufferHandle_t xMessageBuffer_co2;

void measure_co2_callback(uint16_t ppm)
{
	uint16_t value = ppm;
	
	xMessageBufferSend( xMessageBuffer_co2
					, (void *) value
					, sizeof (value)
					,portMAX_DELAY );
	
	xSemaphoreTake(xSemaphore_co2,portMAX_DELAY);
	printf("Measured CO2 value %d sent!\n",value);
	xSemaphoreGive(xSemaphore_co2);
}