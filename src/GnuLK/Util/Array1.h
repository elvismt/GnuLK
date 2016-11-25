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

#ifndef GNULK_UTIL_ARRAY1_H
#define GNULK_UTIL_ARRAY1_H

#include <GnuLK/Util/ArrayBase.h>

GNULK_BEGIN_NAMESPACE

template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
struct   Array1: public  ArrayBase<1,_Tp,_Alloc>
{
public:

    typedef _Tp  value_type;
    typedef _Tp&  reference;
    typedef const _Tp&  const_reference;
    typedef _Tp*  pointer;
    typedef const _Tp*  const_pointer;
    typedef ArrayBase<1,_Tp,_Alloc>  base_type;
    typedef typename base_type::storage_type  storage_type;
    typedef typename base_type::size_type  size_type;


    size_type size() const { return this->shape_[0]; }
    reference operator[] (size_type idx) { return this->at(idx); }
    const_reference operator[] (size_type idx) const { return this->at(idx); }


    Array1() { this->shape_[0] = 0; }


    Array1(size_type size)
        : base_type(size) {
        this->shape_[0] = size;
    }


    Array1(std::initializer_list<value_type> init_list)
        : base_type(init_list){
        this->shape_[0] = init_list.size();
    }


    Array1& operator= (const base_type &that) {
        *((base_type*) this) = that;
        return *this;
    }


    Array1& operator= (base_type &&that) {
        *((base_type*) this) = that;
        return *this;
    }


    void append(const_reference value) {
        this->shape_[0] += 1;
        if (this->storage_ != nullptr) {
            this->vec_().push_back(value);
        } else {
            this->storage_ = new storage_type(1, value);
        }
    }


    void push(const_reference value) {
        this->append(value);
    }


    Array1& operator<< (const_reference value) {
        this->append(value);
        return *this;
    }
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAY1D_H
