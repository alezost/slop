/* xselectrectangle.hpp: Handles creating rectangles on the screen in pure X11.
 *
 * Copyright (C) 2014: Dalton Nell, Slop Contributors (https://github.com/naelstrof/slop/graphs/contributors).
 *
 * This file is part of Slop.
 *
 * Slop is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Slop is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Slop.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IS_X_SELECT_RECTANGLE_H_
#define IS_X_SELECT_RECTANGLE_H_

#include "x.hpp"
#include "selectrectangle.hpp"

#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/extensions/shape.h>
#include <X11/Xatom.h>

#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

namespace slop {

class XSelectRectangle: public SelectRectangle {
public:
            XSelectRectangle( int sx, int sy, int ex, int ey, int border, bool highlight, float r, float g, float b, float a );
            ~XSelectRectangle();
    void    setPos( int x, int y );
    void    setDim( int w, int h );
    void    setGeo( int x, int y, int w, int h );
    XColor  m_color;
private:
    XColor  convertColor( float r, float g, float b );
    void    constrain( int w, int h );
};

}

#endif // IS_X_SELECT_RECTANGLE_H_
