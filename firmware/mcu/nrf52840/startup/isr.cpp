/* -*-c++-*-
 * @file: isr.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/05/11
 * @licence: LGPL3 (see text at the end of a file)
 * @description: isr vector table
 */

#include <cstdint>
#include <mcu/memory_map.hpp>

__attribute__((section(".stack"), used)) uint32_t *__stack_init = &__stacktop__;

extern "C" void __stop(void)  {
    while (true) {
        ;
    }
}

void RESET_Handler(void)        __attribute__((weak, alias("__stop")));
void NMI_Handler(void)          __attribute__((weak, alias("__stop")));
void HARDFAULT_Handler(void)    __attribute__((weak, alias("__stop")));
void MEMMANAGE_Handler(void)    __attribute__((weak, alias("__stop")));
void BUSFAULT_Handler(void)     __attribute__((weak, alias("__stop")));
void USAGEFAULT_Handler(void)   __attribute__((weak, alias("__stop")));
void SVCALL_Handler(void)       __attribute__((weak, alias("__stop")));
void PENDSV_Handler(void)       __attribute__((weak, alias("__stop")));
void SYSTICK_Handler(void)      __attribute__((weak, alias("__stop")));

void DUMMY_Handler(void)        __attribute__((weak, alias("__stop")));

__attribute__((section(".exception_vectors"), used)) funcPtr __exceptionVectors__[] = {
    RESET_Handler,
    NMI_Handler,
    HARDFAULT_Handler,
    MEMMANAGE_Handler,
    BUSFAULT_Handler,
    USAGEFAULT_Handler,
    DUMMY_Handler,
    DUMMY_Handler,
    DUMMY_Handler,
    DUMMY_Handler,
    SVCALL_Handler,
    DUMMY_Handler,
    DUMMY_Handler,
    PENDSV_Handler,
    SYSTICK_Handler
};

void POWERCLOCK_Handler(void)        __attribute__ ((weak, alias("__stop")));
void RADIO_Handler(void)             __attribute__ ((weak, alias("__stop")));
void UART0_Handler(void)             __attribute__ ((weak, alias("__stop")));
void SPI0TWI0_Handler(void)          __attribute__ ((weak, alias("__stop")));
void SPI1TWI1_Handler(void)          __attribute__ ((weak, alias("__stop")));
void NFCTAG_Handler(void)            __attribute__ ((weak, alias("__stop")));
void GPIOTE_Handler(void)            __attribute__ ((weak, alias("__stop")));
void SAADC_Handler(void)             __attribute__ ((weak, alias("__stop")));
void TIMER0_Handler(void)            __attribute__ ((weak, alias("__stop")));
void TIMER1_Handler(void)            __attribute__ ((weak, alias("__stop")));
void TIMER2_Handler(void)            __attribute__ ((weak, alias("__stop")));
void RTC0_Handler(void)              __attribute__ ((weak, alias("__stop")));
void TEMP_Handler(void)              __attribute__ ((weak, alias("__stop")));
void RNG_Handler(void)               __attribute__ ((weak, alias("__stop")));
void ECB_Handler(void)               __attribute__ ((weak, alias("__stop")));
void AARCCM_Handler(void)            __attribute__ ((weak, alias("__stop")));
void WDT_Handler(void)               __attribute__ ((weak, alias("__stop")));
void RTC1_Handler(void)              __attribute__ ((weak, alias("__stop")));
void QDEC_Handler(void)              __attribute__ ((weak, alias("__stop")));
void COMPLPCOMP_Handler(void)        __attribute__ ((weak, alias("__stop")));
void EGU0SWI0_Handler(void)          __attribute__ ((weak, alias("__stop")));
void EGU1SWI1_Handler(void)          __attribute__ ((weak, alias("__stop")));
void EGU2SWI2_Handler(void)          __attribute__ ((weak, alias("__stop")));
void EGU3SWI3_Handler(void)          __attribute__ ((weak, alias("__stop")));
void EGU4SWI4_Handler(void)          __attribute__ ((weak, alias("__stop")));
void EGU5SWI5_Handler(void)          __attribute__ ((weak, alias("__stop")));
void TIMER3_Handler(void)            __attribute__ ((weak, alias("__stop")));
void TIMER4_Handler(void)            __attribute__ ((weak, alias("__stop")));
void PWM0_Handler(void)              __attribute__ ((weak, alias("__stop")));
void PDM_Handler(void)               __attribute__ ((weak, alias("__stop")));
void ACLNVMC_Handler(void)           __attribute__ ((weak, alias("__stop")));
void PPI_Handler(void)               __attribute__ ((weak, alias("__stop")));
void MVU_Handler(void)               __attribute__ ((weak, alias("__stop")));
void PWM1_Handler(void)              __attribute__ ((weak, alias("__stop")));
void PWM2_Handler(void)              __attribute__ ((weak, alias("__stop")));
void SPI2_Handler(void)              __attribute__ ((weak, alias("__stop")));
void RTC2_Handler(void)              __attribute__ ((weak, alias("__stop")));
void I2C_Handler(void)               __attribute__ ((weak, alias("__stop")));
void FPU_Handler(void)               __attribute__ ((weak, alias("__stop")));
void USBD_Handler(void)              __attribute__ ((weak, alias("__stop")));
void UART1_Handler(void)             __attribute__ ((weak, alias("__stop")));
void QSPI_Handler(void)              __attribute__ ((weak, alias("__stop")));
void CCHOSTRGFCRYPTO_Handler(void)   __attribute__ ((weak, alias("__stop")));
void PWM3_Handler(void)              __attribute__ ((weak, alias("__stop")));
void SPI3_Handler(void)              __attribute__ ((weak, alias("__stop")));

__attribute__((section(".isr_vectors"), used)) funcPtr __isrVectors__[] = {
    POWERCLOCK_Handler,
    RADIO_Handler,
    UART0_Handler,
    SPI0TWI0_Handler,
    SPI1TWI1_Handler,
    NFCTAG_Handler,
    GPIOTE_Handler,
    SAADC_Handler,
    TIMER0_Handler,
    TIMER1_Handler,
    TIMER2_Handler,
    RTC0_Handler,
    TEMP_Handler,
    RNG_Handler,
    ECB_Handler,
    AARCCM_Handler,
    WDT_Handler,
    RTC1_Handler,
    QDEC_Handler,
    COMPLPCOMP_Handler,
    EGU0SWI0_Handler,
    EGU1SWI1_Handler,
    EGU2SWI2_Handler,
    EGU3SWI3_Handler,
    EGU4SWI4_Handler,
    EGU5SWI5_Handler,
    TIMER3_Handler,
    TIMER4_Handler,
    PWM0_Handler,
    PDM_Handler,
    ACLNVMC_Handler,
    PPI_Handler,
    MVU_Handler,
    PWM1_Handler,
    PWM2_Handler,
    SPI2_Handler,
    RTC2_Handler,
    I2C_Handler,
    FPU_Handler,
    USBD_Handler,
    UART1_Handler,
    QSPI_Handler,
    CCHOSTRGFCRYPTO_Handler,
    DUMMY_Handler,
    DUMMY_Handler,
    PWM3_Handler,
    DUMMY_Handler,
    SPI3_Handler
};

/*

Copyright © 2024 Dmitry Shpakov

This library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, see <http://www.gnu.org/licenses/>.

*/

