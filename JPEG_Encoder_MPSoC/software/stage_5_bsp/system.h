/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu_5' in SOPC Builder design 'SoC'
 * SOPC Builder design path: D:/MY_ACA/SEM_5/CO503-Advanced_Embedded_Systems/Lab_4_Part_1/SoC.sopcinfo
 *
 * Generated: Mon Mar 16 22:11:29 IST 2026
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x01040820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x19
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x01020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x19
#define ALT_CPU_NAME "cpu_5"
#define ALT_CPU_RESET_ADDR 0x01020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x01040820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x19
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x01020020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x19
#define NIOS2_RESET_ADDR 0x01020000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_5"
#define ALT_STDERR_BASE 0x1041040
#define ALT_STDERR_DEV jtag_5
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_5"
#define ALT_STDIN_BASE 0x1041040
#define ALT_STDIN_DEV jtag_5
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_5"
#define ALT_STDOUT_BASE 0x1041040
#define ALT_STDOUT_DEV jtag_5
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "SoC"


/*
 * fifo_1_5_huff configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_5_huff altera_avalon_fifo
#define FIFO_1_5_HUFF_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_5_HUFF_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_5_HUFF_BASE 0x104104c
#define FIFO_1_5_HUFF_BITS_PER_SYMBOL 16
#define FIFO_1_5_HUFF_CHANNEL_WIDTH 8
#define FIFO_1_5_HUFF_ERROR_WIDTH 8
#define FIFO_1_5_HUFF_FIFO_DEPTH 128
#define FIFO_1_5_HUFF_IRQ -1
#define FIFO_1_5_HUFF_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_5_HUFF_NAME "/dev/fifo_1_5_huff"
#define FIFO_1_5_HUFF_SINGLE_CLOCK_MODE 1
#define FIFO_1_5_HUFF_SPAN 4
#define FIFO_1_5_HUFF_SYMBOLS_PER_BEAT 2
#define FIFO_1_5_HUFF_TYPE "altera_avalon_fifo"
#define FIFO_1_5_HUFF_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_5_HUFF_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_5_HUFF_USE_AVALONST_SINK 0
#define FIFO_1_5_HUFF_USE_AVALONST_SOURCE 0
#define FIFO_1_5_HUFF_USE_BACKPRESSURE 1
#define FIFO_1_5_HUFF_USE_IRQ 0
#define FIFO_1_5_HUFF_USE_PACKET 1
#define FIFO_1_5_HUFF_USE_READ_CONTROL 0
#define FIFO_1_5_HUFF_USE_REGISTER 0
#define FIFO_1_5_HUFF_USE_WRITE_CONTROL 1


/*
 * fifo_4_5_data configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_5_data altera_avalon_fifo
#define FIFO_4_5_DATA_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_5_DATA_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_5_DATA_BASE 0x1041050
#define FIFO_4_5_DATA_BITS_PER_SYMBOL 16
#define FIFO_4_5_DATA_CHANNEL_WIDTH 8
#define FIFO_4_5_DATA_ERROR_WIDTH 8
#define FIFO_4_5_DATA_FIFO_DEPTH 128
#define FIFO_4_5_DATA_IRQ -1
#define FIFO_4_5_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_5_DATA_NAME "/dev/fifo_4_5_data"
#define FIFO_4_5_DATA_SINGLE_CLOCK_MODE 1
#define FIFO_4_5_DATA_SPAN 4
#define FIFO_4_5_DATA_SYMBOLS_PER_BEAT 2
#define FIFO_4_5_DATA_TYPE "altera_avalon_fifo"
#define FIFO_4_5_DATA_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_5_DATA_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_5_DATA_USE_AVALONST_SINK 0
#define FIFO_4_5_DATA_USE_AVALONST_SOURCE 0
#define FIFO_4_5_DATA_USE_BACKPRESSURE 1
#define FIFO_4_5_DATA_USE_IRQ 0
#define FIFO_4_5_DATA_USE_PACKET 1
#define FIFO_4_5_DATA_USE_READ_CONTROL 0
#define FIFO_4_5_DATA_USE_REGISTER 0
#define FIFO_4_5_DATA_USE_WRITE_CONTROL 1


/*
 * fifo_5_6_data_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_6_data_in altera_avalon_fifo
#define FIFO_5_6_DATA_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_6_DATA_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_6_DATA_IN_BASE 0x1041054
#define FIFO_5_6_DATA_IN_BITS_PER_SYMBOL 16
#define FIFO_5_6_DATA_IN_CHANNEL_WIDTH 8
#define FIFO_5_6_DATA_IN_ERROR_WIDTH 8
#define FIFO_5_6_DATA_IN_FIFO_DEPTH 128
#define FIFO_5_6_DATA_IN_IRQ -1
#define FIFO_5_6_DATA_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_6_DATA_IN_NAME "/dev/fifo_5_6_data_in"
#define FIFO_5_6_DATA_IN_SINGLE_CLOCK_MODE 1
#define FIFO_5_6_DATA_IN_SPAN 4
#define FIFO_5_6_DATA_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_6_DATA_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_6_DATA_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_6_DATA_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_6_DATA_IN_USE_AVALONST_SINK 0
#define FIFO_5_6_DATA_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_6_DATA_IN_USE_BACKPRESSURE 1
#define FIFO_5_6_DATA_IN_USE_IRQ 0
#define FIFO_5_6_DATA_IN_USE_PACKET 1
#define FIFO_5_6_DATA_IN_USE_READ_CONTROL 0
#define FIFO_5_6_DATA_IN_USE_REGISTER 0
#define FIFO_5_6_DATA_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_6_data_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_6_data_in_csr altera_avalon_fifo
#define FIFO_5_6_DATA_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_6_DATA_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_6_DATA_IN_CSR_BASE 0x1041020
#define FIFO_5_6_DATA_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_6_DATA_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_6_DATA_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_6_DATA_IN_CSR_FIFO_DEPTH 128
#define FIFO_5_6_DATA_IN_CSR_IRQ -1
#define FIFO_5_6_DATA_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_6_DATA_IN_CSR_NAME "/dev/fifo_5_6_data_in_csr"
#define FIFO_5_6_DATA_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_5_6_DATA_IN_CSR_SPAN 32
#define FIFO_5_6_DATA_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_6_DATA_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_6_DATA_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_6_DATA_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_6_DATA_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_6_DATA_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_6_DATA_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_6_DATA_IN_CSR_USE_IRQ 0
#define FIFO_5_6_DATA_IN_CSR_USE_PACKET 1
#define FIFO_5_6_DATA_IN_CSR_USE_READ_CONTROL 0
#define FIFO_5_6_DATA_IN_CSR_USE_REGISTER 0
#define FIFO_5_6_DATA_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_6_size_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_6_size_in altera_avalon_fifo
#define FIFO_5_6_SIZE_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_6_SIZE_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_6_SIZE_IN_BASE 0x1041048
#define FIFO_5_6_SIZE_IN_BITS_PER_SYMBOL 16
#define FIFO_5_6_SIZE_IN_CHANNEL_WIDTH 8
#define FIFO_5_6_SIZE_IN_ERROR_WIDTH 8
#define FIFO_5_6_SIZE_IN_FIFO_DEPTH 128
#define FIFO_5_6_SIZE_IN_IRQ -1
#define FIFO_5_6_SIZE_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_6_SIZE_IN_NAME "/dev/fifo_5_6_size_in"
#define FIFO_5_6_SIZE_IN_SINGLE_CLOCK_MODE 1
#define FIFO_5_6_SIZE_IN_SPAN 4
#define FIFO_5_6_SIZE_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_6_SIZE_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_6_SIZE_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_6_SIZE_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_6_SIZE_IN_USE_AVALONST_SINK 0
#define FIFO_5_6_SIZE_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_6_SIZE_IN_USE_BACKPRESSURE 1
#define FIFO_5_6_SIZE_IN_USE_IRQ 0
#define FIFO_5_6_SIZE_IN_USE_PACKET 1
#define FIFO_5_6_SIZE_IN_USE_READ_CONTROL 0
#define FIFO_5_6_SIZE_IN_USE_REGISTER 0
#define FIFO_5_6_SIZE_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_6_size_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_6_size_in_csr altera_avalon_fifo
#define FIFO_5_6_SIZE_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_6_SIZE_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_6_SIZE_IN_CSR_BASE 0x1041000
#define FIFO_5_6_SIZE_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_6_SIZE_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_6_SIZE_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_6_SIZE_IN_CSR_FIFO_DEPTH 128
#define FIFO_5_6_SIZE_IN_CSR_IRQ -1
#define FIFO_5_6_SIZE_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_6_SIZE_IN_CSR_NAME "/dev/fifo_5_6_size_in_csr"
#define FIFO_5_6_SIZE_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_5_6_SIZE_IN_CSR_SPAN 32
#define FIFO_5_6_SIZE_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_6_SIZE_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_6_SIZE_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_6_SIZE_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_6_SIZE_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_6_SIZE_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_6_SIZE_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_6_SIZE_IN_CSR_USE_IRQ 0
#define FIFO_5_6_SIZE_IN_CSR_USE_PACKET 1
#define FIFO_5_6_SIZE_IN_CSR_USE_READ_CONTROL 0
#define FIFO_5_6_SIZE_IN_CSR_USE_REGISTER 0
#define FIFO_5_6_SIZE_IN_CSR_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_5
#define ALT_TIMESTAMP_CLK TIMER_5


/*
 * jtag_5 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_5 altera_avalon_jtag_uart
#define JTAG_5_BASE 0x1041040
#define JTAG_5_IRQ 1
#define JTAG_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_5_NAME "/dev/jtag_5"
#define JTAG_5_READ_DEPTH 64
#define JTAG_5_READ_THRESHOLD 8
#define JTAG_5_SPAN 8
#define JTAG_5_TYPE "altera_avalon_jtag_uart"
#define JTAG_5_WRITE_DEPTH 64
#define JTAG_5_WRITE_THRESHOLD 8


/*
 * ram_5 configuration
 *
 */

#define ALT_MODULE_CLASS_ram_5 altera_avalon_onchip_memory2
#define RAM_5_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_5_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_5_BASE 0x1020000
#define RAM_5_CONTENTS_INFO ""
#define RAM_5_DUAL_PORT 0
#define RAM_5_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_5_INIT_CONTENTS_FILE "SoC_ram_5"
#define RAM_5_INIT_MEM_CONTENT 1
#define RAM_5_INSTANCE_ID "NONE"
#define RAM_5_IRQ -1
#define RAM_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_5_NAME "/dev/ram_5"
#define RAM_5_NON_DEFAULT_INIT_FILE_ENABLED 0
#define RAM_5_RAM_BLOCK_TYPE "AUTO"
#define RAM_5_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_5_SINGLE_CLOCK_OP 0
#define RAM_5_SIZE_MULTIPLE 1
#define RAM_5_SIZE_VALUE 131072
#define RAM_5_SPAN 131072
#define RAM_5_TYPE "altera_avalon_onchip_memory2"
#define RAM_5_WRITABLE 1


/*
 * timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1 altera_avalon_timer
#define TIMER_1_ALWAYS_RUN 0
#define TIMER_1_BASE 0x20
#define TIMER_1_COUNTER_SIZE 32
#define TIMER_1_FIXED_PERIOD 0
#define TIMER_1_FREQ 10000000
#define TIMER_1_IRQ -1
#define TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_1_LOAD_VALUE 9999
#define TIMER_1_MULT 0.0010
#define TIMER_1_NAME "/dev/timer_1"
#define TIMER_1_PERIOD 1
#define TIMER_1_PERIOD_UNITS "ms"
#define TIMER_1_RESET_OUTPUT 0
#define TIMER_1_SNAPSHOT 1
#define TIMER_1_SPAN 32
#define TIMER_1_TICKS_PER_SEC 1000.0
#define TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_TYPE "altera_avalon_timer"


/*
 * timer_2 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_2 altera_avalon_timer
#define TIMER_2_ALWAYS_RUN 0
#define TIMER_2_BASE 0x40
#define TIMER_2_COUNTER_SIZE 32
#define TIMER_2_FIXED_PERIOD 0
#define TIMER_2_FREQ 10000000
#define TIMER_2_IRQ -1
#define TIMER_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_2_LOAD_VALUE 9999
#define TIMER_2_MULT 0.0010
#define TIMER_2_NAME "/dev/timer_2"
#define TIMER_2_PERIOD 1
#define TIMER_2_PERIOD_UNITS "ms"
#define TIMER_2_RESET_OUTPUT 0
#define TIMER_2_SNAPSHOT 1
#define TIMER_2_SPAN 32
#define TIMER_2_TICKS_PER_SEC 1000.0
#define TIMER_2_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_2_TYPE "altera_avalon_timer"


/*
 * timer_3 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_3 altera_avalon_timer
#define TIMER_3_ALWAYS_RUN 0
#define TIMER_3_BASE 0x60
#define TIMER_3_COUNTER_SIZE 32
#define TIMER_3_FIXED_PERIOD 0
#define TIMER_3_FREQ 10000000
#define TIMER_3_IRQ -1
#define TIMER_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_3_LOAD_VALUE 9999
#define TIMER_3_MULT 0.0010
#define TIMER_3_NAME "/dev/timer_3"
#define TIMER_3_PERIOD 1
#define TIMER_3_PERIOD_UNITS "ms"
#define TIMER_3_RESET_OUTPUT 0
#define TIMER_3_SNAPSHOT 1
#define TIMER_3_SPAN 32
#define TIMER_3_TICKS_PER_SEC 1000.0
#define TIMER_3_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_3_TYPE "altera_avalon_timer"


/*
 * timer_4 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_4 altera_avalon_timer
#define TIMER_4_ALWAYS_RUN 0
#define TIMER_4_BASE 0x80
#define TIMER_4_COUNTER_SIZE 32
#define TIMER_4_FIXED_PERIOD 0
#define TIMER_4_FREQ 10000000
#define TIMER_4_IRQ -1
#define TIMER_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_4_LOAD_VALUE 9999
#define TIMER_4_MULT 0.0010
#define TIMER_4_NAME "/dev/timer_4"
#define TIMER_4_PERIOD 1
#define TIMER_4_PERIOD_UNITS "ms"
#define TIMER_4_RESET_OUTPUT 0
#define TIMER_4_SNAPSHOT 1
#define TIMER_4_SPAN 32
#define TIMER_4_TICKS_PER_SEC 1000.0
#define TIMER_4_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_4_TYPE "altera_avalon_timer"


/*
 * timer_5 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_5 altera_avalon_timer
#define TIMER_5_ALWAYS_RUN 0
#define TIMER_5_BASE 0xa0
#define TIMER_5_COUNTER_SIZE 32
#define TIMER_5_FIXED_PERIOD 0
#define TIMER_5_FREQ 10000000
#define TIMER_5_IRQ 0
#define TIMER_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_5_LOAD_VALUE 9999
#define TIMER_5_MULT 0.0010
#define TIMER_5_NAME "/dev/timer_5"
#define TIMER_5_PERIOD 1
#define TIMER_5_PERIOD_UNITS "ms"
#define TIMER_5_RESET_OUTPUT 0
#define TIMER_5_SNAPSHOT 1
#define TIMER_5_SPAN 32
#define TIMER_5_TICKS_PER_SEC 1000.0
#define TIMER_5_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_5_TYPE "altera_avalon_timer"


/*
 * timer_6 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_6 altera_avalon_timer
#define TIMER_6_ALWAYS_RUN 0
#define TIMER_6_BASE 0x0
#define TIMER_6_COUNTER_SIZE 32
#define TIMER_6_FIXED_PERIOD 0
#define TIMER_6_FREQ 10000000
#define TIMER_6_IRQ -1
#define TIMER_6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_6_LOAD_VALUE 9999
#define TIMER_6_MULT 0.0010
#define TIMER_6_NAME "/dev/timer_6"
#define TIMER_6_PERIOD 1
#define TIMER_6_PERIOD_UNITS "ms"
#define TIMER_6_RESET_OUTPUT 0
#define TIMER_6_SNAPSHOT 1
#define TIMER_6_SPAN 32
#define TIMER_6_TICKS_PER_SEC 1000.0
#define TIMER_6_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_6_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
