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

#ifndef GNULK_UTIL_ARRAYBASE_H
#define GNULK_UTIL_ARRAYBASE_H

#include <GnuLK/Util/ArrayStorage.h>
#include <array>
#include <numeric>

GNULK_BEGIN_NAMESPACE

template <int _Dn, typename _Tp, typename _Alloc = std::allocator<_Tp> >
class   ArrayBase
{
public:

    typedef _Tp  value_type;
    typedef _Tp&  reference;
    typedef const _Tp&  const_reference;
    typedef _Tp*  pointer;
    typedef const _Tp*  const_pointer;
    typedef ArrayStorage<_Tp,_Alloc>  storage_type;
    typedef std::array<_Tp,_Dn>  shape_type;
    typedef std::array<_Tp,_Dn>&  shape_reference;
    typedef const std::array<_Tp,_Dn>&  shape_const_reference;
    typedef typename storage_type::size_type  size_type;
    typedef typename storage_type::vector_type  vector_type;
    typedef typename storage_type::vector_reference  vector_reference;
    typedef typename storage_type::vector_const_reference  vector_const_reference;


    reference at(size_type idx) { return vec_()[idx]; }
    const_reference at(size_type idx) const { return vec_()[idx]; }
    pointer ptr_at(size_type idx) { return &(vec_()[idx]); }
    const_pointer ptr_at(size_type idx) const { return &(vec_()[idx]); }
    shape_const_reference shape() const { return shape_; }
    size_type total_size() const { return std::accumulate(shape_.begin(), shape_.end(), 0); }


    ArrayBase(): storage_(nullptr) {}


    template <class... CtorArgs>
    ArrayBase(CtorArgs... args)
        : storage_(new storage_type(args...)) {}


    ArrayBase(const ArrayBase &that) {
        this->storage_ = nullptr;
        this->join_(that);
    }


    ArrayBase(ArrayBase &&that) {
        this->storage_ = nullptr;
        this->join_(that);
    }


    ArrayBase& operator= (const ArrayBase &that) {
        this->join_(that);
        return *this;
    }


    ArrayBase& operator= (ArrayBase &&that) {
        this->join_(that);
        return *this;
    }


    ~ArrayBase() {
        detach_();
    }


protected:

    vector_const_reference vec_() const { return storage_->vector_; }
    vector_reference vec_() { return storage_->vector_; }


    void detach_() {
        if (storage_ != nullptr) {
            if (storage_->unref_()) delete storage_;
            storage_ = nullptr;
            std::fill(shape_.begin(), shape_.end(), 0);
        }
    }


    void join_(const ArrayBase &that) {
        if (storage_ != that.storage_) {
            detach_();
            storage_ = (that.storage_ != nullptr) ? that.storage_->ref_() : nullptr;
            std::copy(that.shape_.begin(), that.shape_.end(), shape_.begin());
        }
    }


    void join_(ArrayBase &&that) {
        if (storage_ != that.storage_) {
            detach_();
            storage_ = (that.storage_ != nullptr) ? that.storage_->ref_() : nullptr;
            std::copy(that.shape_.begin(), that.shape_.end(), shape_.begin());
        }
    }


    shape_type shape_;
    storage_type *storage_;
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAYBASE_H
