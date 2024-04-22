/* -*-ld-*-
 * @file: memory_map.ld
 * @author: Dmitry Shpakov
 * @date: 2024/04/20
 * @licence: LGPL3 (see text at the end of a file)
 * @description: 
 */

FLASH_SIZE = 1M
RAM_SIZE = 256K
FLASH_ORIGIN = 0x00000000
RAM_ORIGIN = 0x20000000

SHARED_SIZE = 4K
BOOTLOADER_SIZE = 4K

MEMORY {
    BOOTROM (rx) : ORIGIN = FLASH_ORIGIN, LENGTH = BOOTLOADER_SIZE
    APPROM  (rx) : ORIGIN = FLASH_ORIGIN + BOOTLOADER_SIZE, LENGTH = FLASH_SIZE - BOOTLOADER_SIZE
    SHARED  (rxw) : ORIGIN = RAM_ORIGIN, LENGTH = SHARED_SIZE
    RAM     (rwx) : ORIGIN = RAM_ORIGIN + SHARED_SIZE, LENGTH = RAM_SIZE - SHARED_SIZE
}

__bootrom_start__ = ORIGIN(BOOTROM);
__bootrom_size__ = LENGTH(BOOTROM);
__approm_start__ = ORIGIN(APPROM);
__approm_size__ = LENGTH(APPROM);
__shared_start__ = ORIGIN(SHARED);
__shared_size__ = LENGTH(SHARED);
__ram_start__ = ORIGIN(RAM);
__ram_size__ = LENGTH(RAM);

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

