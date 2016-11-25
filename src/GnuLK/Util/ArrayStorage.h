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

#ifndef GNULK_UTIL_ARRAYSTORAGE_H
#define GNULK_UTIL_ARRAYSTORAGE_H

#include <GnuLK/Util/Global.h>
#include <vector>

GNULK_BEGIN_NAMESPACE

template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
struct   ArrayStorage
{
    typedef _Tp  value_type;
    typedef std::vector<_Tp,_Alloc>  vector_type;
    typedef std::vector<_Tp,_Alloc>&  vector_reference;
    typedef const std::vector<_Tp,_Alloc>&  vector_const_reference;
    typedef typename vector_type::size_type  size_type;


    ArrayStorage() = delete;
    ArrayStorage(const ArrayStorage&) = delete;
    ArrayStorage(ArrayStorage&&) = delete;
    ArrayStorage& operator=(const ArrayStorage&) = delete;
    ArrayStorage& operator=(ArrayStorage&&) = delete;


    template <class... CtorArgs>
    ArrayStorage(CtorArgs... args)
        : vector_(args...)
        , ref_count_(1) {}


    ArrayStorage* ref_() {
        ref_count_ += 1;
        return this;
    }


    bool unref_() {
        ref_count_ -= 1;
        return ref_count_ == 0;
    }


    vector_type vector_;
    size_type ref_count_;
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAYSTORAGE_H
