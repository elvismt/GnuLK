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

#ifndef GnuLK_Util_Global_H
#define GnuLK_Util_Global_H

#include <cstdint>
#include <string>
#include <vector>
#include <list>

#define GnuLK_Begin_Namespace namespace GnuLK {

#define GnuLK_End_Namespace } // namespace GnuLK


GnuLK_Begin_Namespace

using String = std::string;

template <class T>
using Vector = std::vector<T>;

template <class T>
using List = std::list<T>;

GnuLK_End_Namespace

#endif // GnuLK_Util_Global_H
