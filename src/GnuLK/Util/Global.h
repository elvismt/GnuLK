/*
 * Copyright (C) 2016  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GNULK_UTIL_GLOBAL_H
#define GNULK_UTIL_GLOBAL_H

#include <cstdint>
#include <string>
#include <vector>
#include <list>

#define GNULK_BEGIN_NAMESPACE \
    namespace GnuLK {

#define GNULK_END_NAMESPACE \
    } // namespace GnuLK

#define GNULK_BEGIN_MATH_NAMESPACE \
    namespace GnuLK { namespace Math {

#define GNULK_END_MATH_NAMESPACE \
    }} // namespace GnuLK::Math

#define GNULK_EXPORT

#define GNULK_UNUSED(var) (void) var


GNULK_BEGIN_NAMESPACE

using String = std::string;

template <typename T>
using Vector = std::vector<T>;

template <typename T>
using List = std::list<T>;

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_GLOBAL_H
