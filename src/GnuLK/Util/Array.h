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

#ifndef GNULK_UTIL_ARRAY_H
#define GNULK_UTIL_ARRAY_H

#include <GnuLK/Util/Array1.h>
#include <GnuLK/Util/Math.h>

#include <iostream>
#include <cmath>
using namespace std;

GNULK_BEGIN_NAMESPACE

typedef Array1<double> Array1D;


template <typename T> inline
Array1D arange(const T &start, const T &stop, const T &step=T(1)) {
    Array1D ret((stop-start)/step);
    for (uint32_t k=0; k<ret.total_size(); ++k)
        ret[k] = start + k * step;
    return ret;
}


template <typename F, int D, typename T, typename A>
inline void apply(F func, ArrayBase<D,T,A> &arr) {
    for (uint32_t k=0; k<arr.total_size(); ++k)
        func(arr.at(k));
}


template <typename F, int D, typename T, typename A>
inline ArrayBase<D,T,A> applyed(F func, ArrayBase<D,T,A> &arr) {
    ArrayBase<D,T,A> ret(arr.total_size());
    for (uint32_t k=0; k<ret.total_size(); ++k)
        ret.at(k) = func(arr.at(k));
    return ret;
}

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAY_H
