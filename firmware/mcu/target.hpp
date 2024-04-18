/* -*-c++-*-
 * @file: target.hpp
 * @author: Dmitry Shpakov
 * @date: 2024/04/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: This is MCU hardware class. It implements methods to interact
 *               with the hardware. All method should be implemented for every 
 *               mcu.
 */

#pragma once

class Target final {
public:
  Target(Target const &) = delete;
  void operator=(Target const &) = delete;
  static Target &getInstance();
  // methods to implement in every target mcu
  ~Target();
  void reset(void);
  void halt(void);
  void init(void);
  void deInit(void);
private:
  Target();
  static Target m_instance;
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

