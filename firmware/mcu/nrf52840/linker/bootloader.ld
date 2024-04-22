/* -*-ld-*-
 * @file: bootloader.ld
 * @author: Dmitry Shpakov
 * @date: 2024/04/22
 * @licence: LGPL3 (see text at the end of a file)
 * @description: bootloader linker script file
 */

ENTRY(RESET_Handler)

INCLUDE("memory.ld")

SECTIONS {
    . = ORIGIN(BOOTROM);
    .text ALIGN(4) : {
        __text_start__ = .;
        KEEP(*(.stack))
        KEEP(*(.exception_vectors))
        KEEP(*(.isr_vectors))
        *(.text)
        *(.text*)
        KEEP(*(.rodata*))
    } > BOOTROM

    .preinit_array ALIGN(4) : {
        __preinit_array_start__ = .;
        KEEP(*(.preinit_array))
        KEEP(*(.preinit_array*))
        __preinit_array_end__ = .;
    } > BOOTROM

    .init_array ALIGN(4) : {
        __init_array_start__ = .;
        KEEP(*(.init_array))
        KEEP(*(.init_array*))
        __init_array_end__ = .;
    } > BOOTROM

    .fini_array ALIGN(4) : {
        __fini_array_start__ = .;
        KEEP(*(.fini_array))
        KEEP(*(.fini_array*))
        __fini_array_end__ = .;
    } > BOOTROM

    __text_end__ = .;

    /* according to ARM should be aligned to 8-byte border */
    __stack_top__ = ALIGN (ORIGIN(RAM) + LENGTH(RAM), 8);
    __data_load__ = LOADADDR(.data);
    . = ORIGIN(RAM);

    .data ALIGN(4) : {
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        __data_end__ = .;
    } > RAM AT > BOOTROM

    .bss ALIGN(4) (NOLOAD) : {
        __bss_start__ = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        __bss_end__ = .;
        *(.noinit*)
    } > RAM

    . = ALIGN(4);
    __heap_start__ = .;
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

