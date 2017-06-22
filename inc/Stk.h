/*
    Stk - SDL-based GUI Toolkit
    Copyright (C) 2017  EasyDevCpp

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _Stk
#define _Stk

#include <string>
#include <vector>

#ifdef WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#endif

namespace Stk
{
    /* Global section */
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event event;
    int mouse_x;
    int mouse_y;
    Uint32 mouse_timer;

    /* Includes */
    #include "Style.h"
    #include "Widget.h"
    #include "Screen.h"
    #include "EventLoop.h"
    #include "Window.h"
}

#endif