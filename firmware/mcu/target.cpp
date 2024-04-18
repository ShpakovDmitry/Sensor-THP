/* -*-c++-*-
 * @file: target.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/04/18
 * @licence: LGPL3 (see text at the end of a file)
 * @description: This holds the static instance of `Target` class. This
 *               implements `singleton` pattern. We need only one instance of
 *               a target hardware class. This object is globally constructed.
 */

#include "target.hpp"

Target Target::instance;

Target &Target::getInstance() {
  return Target::instance;
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

