/* -*-c++-*-
 * @file: hardware_specific.hpp
 * @author: Dmitry Shpakov
 * @date: 2024/04/19
 * @licence: LGPL3 (see text at the end of a file)
 * @description: hardware specific config.
 *               All defines are specified in Makefile.
 *               Basically this should be the only place where
 *               conditional compilation is happening.
 *               I want to believe in this.
 */

#pragma once

#if defined ( TARGET_NRF52840_QFAAF )
  #include <config/mcu/nrf52840_qfaaf.hpp>
#else
  #error "No target microcotroller is defined to run this software"
#endif

#if defined ( SENSOR_THP_REV_A )
  #include <config/board/sensor_thp_rev_a.hpp>
#elif defined ( SENSOR_THP_REV_B )
  #include <config/board/sensor_thp_rev_b.hpp>
#else
  #error "No target board is defined"
#endif

// incompability checks
// this is as an example
#if defined ( TARGET_NRF52840_QFAAF ) && defined ( SENSOR_THP_REV_B )
  #error "This microcontroller and board are incompatible"
#endif

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

