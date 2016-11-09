/*
 * This file is part of GnuLK.
 *
 * Copyright (c) 2016  Elvis M. Teixeira
 *
 * GnuLK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuLK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GnuLK.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GNULK_UTIL_GLOBAL_H
#define GNULK_UTIL_GLOBAL_H

#include <cstdint>
#include <string>
#include <vector>
#include <list>

#define GNULK_BEGIN_NAMESPACE namespace GnuLK {

#define GNULK_END_NAMESPACE } // namespace GnuLK


GNULK_BEGIN_NAMESPACE

using String = std::string;

template <class T>
using Vector = std::vector<T>;

template <class T>
using List = std::list<T>;

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_GLOBAL_H
