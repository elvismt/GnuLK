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

#ifndef GNULK_UTIL_ARRAY_P_H
#define GNULK_UTIL_ARRAY_P_H

#include <GnuLK/Util/Math.h>
#include <cstdlib>

GNULK_BEGIN_NAMESPACE

template <class T>
class array_storage
{
public:

    template <class... CtorArgs> inline
    array_storage(uint64_t size, CtorArgs... args) {
        m_buffer = nullptr;
        m_ref_count = 1UL;
        m_publ_size = 0UL;
        m_max_size = 0UL;
        this->resize(size, args...);
    }


    ~array_storage() {
        this->free();
    }


    template <class... CtorArgs> inline
    void resize(uint64_t size, CtorArgs... args)
    {
        if (m_max_size < size)
        {
            if (m_buffer == nullptr) {
                m_buffer = static_cast<T*>(
                    std::malloc(size * sizeof(T)));
            } else {
                m_buffer = static_cast<T*>(
                    std::realloc(m_buffer, size * sizeof(T)));
            }
            m_max_size = size;
        }
        for (uint64_t k=m_publ_size; k<size; ++k) {
            new (m_buffer + k) T(args...);
        }
        m_publ_size = size;
    }


    inline
    void free()
    {

    }


private:

    T *m_buffer;
    uint64_t m_ref_count;
    uint64_t m_publ_size;
    uint64_t m_max_size;
};




GNULK_END_NAMESPACE

#endif // GNULK_UTIL_ARRAY_P_H
