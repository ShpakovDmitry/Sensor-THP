/* -*-c++-*-
 * @file: startup.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/05/11
 * @licence: LGPL3 (see text at the end of a file)
 * @description: mcu startup
 */
 
#include <cstdint>
#include <mcu/memory_map.hpp>

extern void main(void);

void copyDataSection(void) {
    uint32_t *src, *dst;
    src = &__data_load__;
    dst = &__data_start__;
    while (dst < &__data_end__) {
        *(dst++) = *(src++);
    }
}

void copyBssSection(void) {
    uint32_t *src;
    src = &__bss_start__;
    while (src < &__bss_end__) {
        *(src++) = 0;
    }
}

void fillHeap(uint32_t fillVal = 0xDEADC0DE) {
    uint32_t *dst, *mspReg;
    dst = &__heap_start__;
    __asm__("mrs %0, msp\n" : "=r" (mspReg));
    while (dst < mspReg) {
        *(dst++) = fillVal;
    }
}

void callInitArray(void) {
    auto array = __preinit_array_start__;
    while (array < __preinit_array_end__) {
        (*array)();
        array++;
    }
    array = __init_array_start__;
    while (array < __init_array_end__) {
        (*array)();
        array++;
    }
}

void callFiniArray(void) {
    auto array = __fini_array_start__;
    while (array < __fini_array_end__) {
        (*array)();
        array++;
    }
}

void RESET_Handler() {
    copyDataSection();
    copyBssSection();
    fillHeap();
    callInitArray();
    main();
    callFiniArray();
    while (true) {
        ;
    }
}

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

