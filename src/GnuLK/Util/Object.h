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

#ifndef GNULK_UTIL_OBJECT_H
#define GNULK_UTIL_OBJECT_H

#include <GnuLK/Util/Object_p.h>

#define GNULK_GET_PRIVATE(Class, instance) \
    (static_cast<Class##Private*>((instance)->__getpriv()))

#define GNULK_PUBLIC(Class) \
    auto m = GNULK_GET_PRIVATE(Class,this)


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT Object
{
public:

    virtual ~Object() {
        if (m_priv != nullptr) {
            delete m_priv;
        }
    }

    inline
    ObjectPrivate* __getpriv() const {
        return m_priv;
    }


protected:

    Object(ObjectPrivate *priv)
        : m_priv(priv)
    { }

    ObjectPrivate *const m_priv;
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_OBJECT_H
