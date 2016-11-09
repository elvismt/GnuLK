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

#ifndef GNULK_UTIL_OBJECT_P_H
#define GNULK_UTIL_OBJECT_P_H

#include <GnuLK/Util/Global.h>

#define GNULK_GET_PUBLIC(Class, instance) \
    (static_cast<Class*>((instance)->__getpubl()))

#define GNULK_PRIVATE(Class) \
    auto m = GNULK_GET_PUBLIC(Class,this)

GNULK_BEGIN_NAMESPACE

// forward declaration
class Object;

class GNULK_EXPORT ObjectPrivate
{
public:

    virtual ~ObjectPrivate()
    { }

    ObjectPrivate(Object *publ)
        : m_publ(publ)
    { }

    inline
    Object* __getpubl() const {
        return m_publ;
    }


protected:

    Object *const m_publ;
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_OBJECT_P_H
