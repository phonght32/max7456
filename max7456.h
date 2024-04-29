// MIT License

// Copyright (c) 2024 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __MAX7456_H__
#define __MAX7456_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "err_code.h"


typedef err_code_t (*max7456_func_spi_send)(uint8_t *buf_send, uint16_t len);
typedef err_code_t (*max7456_func_spi_recv)(uint8_t *buf_recv, uint16_t len);
typedef err_code_t (*max7456_func_set_gpio)(uint8_t level);
typedef void (*max7456_func_delay)(uint32_t time_ms);

/**
 * @brief   MAX7456 handle structure.
 */
typedef struct max7456* max7456_handle_t;

/**
 * @brief   Configuration structure.
 */
typedef struct {
	max7456_func_spi_send 		spi_send;			/*!< Function SPI send */
	max7456_func_spi_recv 		spi_recv;			/*!< Function SPI receive */
	max7456_func_set_gpio 		set_cs;				/*!< Function set chip select pin */
	max7456_func_delay			delay; 				/*!< Function delay */
} max7456_cfg_t;

/*
 * @brief   Initialize MAX7456 with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
max7456_handle_t max7456_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   config Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t max7456_set_config(max7456_handle_t handle, max7456_cfg_t config);

/*
 * @brief   Configure MAX7456 to run.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t max7456_config(max7456_handle_t handle);

#ifdef __cplusplus
}
#endif

#endif /* __MAX7456_H__ */