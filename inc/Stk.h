/*
    Stk - SDL-based GUI Toolkit
    Copyright (C) 2017  Robin Krause

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
#include <array>

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>

    std::string OS_SEPARATOR="\\";
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>

    std::string OS_SEPARATOR="/";
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

    /* Internal section */
    namespace Internal {
        std::vector<std::string> text_input;
        std::vector<bool> text_active;
        std::vector<bool> text_update;
        std::vector<int> text_cursor;
        std::vector<bool> text_mark;
        std::vector<int> text_markpos;
        std::vector<int> text_marklen;
        std::vector<int> text_markdir;
        std::vector<bool> text_end;

        int fps=0;
        Uint32 fps_timer;
    }

    /* Constants */
    const int CENTERED=SDL_WINDOWPOS_CENTERED;

    const int EVENT_HOVER=1;
    const int EVENT_CLICK=2;

    const int FONT_BIG=0;
    const int FONT_MEDIUM=1;
    const int FONT_SMALL=2;

    const int INPUT_TEXT=0;
    const int INPUT_PW=1;

    /* Options */
    namespace Options {
        bool MEDIUM_CPU_USAGE=false;
        bool LOW_CPU_USAGE=false;
        bool EXTRA_LOW_CPU_USAGE=false;
    }

    /* Includes */
    #include "Basics.h"
    #include "Style.h"
    #include "Widget.h"
    #include "Screen.h"
    #include "Widgets.h"
    #include "EventLoop.h"
    #include "Window.h"
}

#endif