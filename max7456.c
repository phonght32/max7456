#include "stdlib.h"
#include "max7456.h"

typedef struct max7456 {
	max7456_func_spi_send 		spi_send;			/*!< Function SPI send */
	max7456_func_spi_recv 		spi_recv;			/*!< Function SPI receive */
	max7456_func_set_gpio 		set_cs;				/*!< Function set chip select pin */
	max7456_func_delay			delay; 				/*!< Function delay */
} max7456_t;

max7456_handle_t max7456_init(void)
{
	max7456_handle_t handle = calloc(1, sizeof(max7456_t));
	if (handle == NULL)
	{
		return NULL;
	}

	return handle;
}

err_code_t max7456_set_config(max7456_handle_t handle, max7456_cfg_t config)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->spi_send = config.spi_send;
	handle->spi_recv = config.spi_recv;
	handle->set_cs = config.set_cs;
	handle->delay = config.delay;

	return ERR_CODE_SUCCESS;
}

err_code_t max7456_config(max7456_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}
	
	return ERR_CODE_SUCCESS;
}