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

#include <GnuLK/Util/ArrayData.h>
#include <GnuLK/Util/Math.h>

GNULK_BEGIN_NAMESPACE

template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
struct Array1
{
public:

    typedef _Tp  value_type;
    typedef _Tp&  reference;
    typedef const _Tp&  const_reference;
    typedef _Tp*  pointer;
    typedef const _Tp*  const_pointer;
    typedef ArrayData<_Tp,_Alloc>  data_type;
    typedef ArrayData<_Tp,_Alloc>*  data_pointer_type;
    typedef typename data_type::size_type  size_type;



    Array1() : size_{0}, data_{nullptr} { }


    Array1(size_type size) {
        if (size > 0) {
            size_ = size;
            data_ = new data_type(size);
        } else {
            size_ = 0;
            data_ = nullptr;
        }
    }


    Array1(size_type size, const value_type &value) {
        if (size > 0) {
            size_ = size;
            data_ = new data_type(size, value);
        } else {
            size_ = 0;
            data_ = nullptr;
        }
    }


    Array1(const Array1 &that) {
        size_ = that.size();
        data_ = nullptr;
        data_type::join_(&data_, that.data_);
    }


    Array1(Array1 &&that) {
        size_ = that.size();
        data_ = nullptr;
        data_type::join_(&data_, that.data_);
    }


    ~Array1() {
        data_type::detach_(&data_);
    }


    Array1& operator= (const Array1 &that) {
        size_ = that.size();
        data_type::join_(&data_, that.data_);
        return *this;
    }


    Array1& operator= (Array1 &&that) {
        size_ = that.size();
        data_type::join_(&data_, that.data_);
        return *this;
    }


    size_type size() const { return size_; }
    reference operator[] (size_type idx) { return data_->vector_[idx]; }
    const_reference operator[] (size_type idx) const { return data_->vector_[idx]; }


private:

    size_type size_;
    data_pointer_type data_;
};



template <typename T, typename A = std::allocator<T> >
inline Array1<T,A> arange(const T &start, const T &stop, const T &step=T(1)) {
    Array1<T,A> ret(double(stop-start)/step);
    for (uint32_t k=0; k<ret.size(); ++k)
        ret[k] = start + k *step;
    return std::move(ret);
}


template <typename F, typename T, typename A = std::allocator<T> >
inline Array1<T,A> applyed(F func, const Array1<T,A> &arr) {
    Array1<T,A> ret(arr.size());
    for (uint32_t k=0; k<ret.size(); ++k)
        ret[k] = func(arr[k]);
    return std::move(ret);
}



template <typename T, typename A = std::allocator<T> >
inline Array1<T,A> sin(const Array1<T,A> &arr) {
    return applyed(Math::sin, arr);
}


template <typename T, typename A = std::allocator<T> >
inline Array1<T,A> cos(const Array1<T,A> &arr) {
    return applyed(Math::cos, arr);
}

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAY1D_H
