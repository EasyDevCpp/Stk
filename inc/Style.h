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
#ifndef _StkStyle
#define _StkStyle

namespace Style
{
    /* Font styles */
    TTF_Font* font_big;
    TTF_Font* font_medium;
    TTF_Font* font_small;
    int big_size;
    int medium_size;
    int small_size;

    /* Colors */
    SDL_Color text_color;
    SDL_Color normal_color;
    SDL_Color hover_color;
    SDL_Color active_color;
    SDL_Color background_color;

    /* init */
    void init()
    {
        big_size=35;
        medium_size=20;
        small_size=14;
        font_big=TTF_OpenFont(("inc"+OS_SEPARATOR+"Roboto-Regular.ttf").c_str(),big_size);
        font_medium=TTF_OpenFont(("inc"+OS_SEPARATOR+"Roboto-Light.ttf").c_str(),medium_size);
        font_small=TTF_OpenFont(("inc"+OS_SEPARATOR+"Roboto-Light.ttf").c_str(),small_size);

        text_color={225,225,225};
        normal_color={45,45,45,255};
        hover_color={0,185,255,255};
        active_color={255,0,185,255};
        background_color={30,30,30,255};
    }

    /* quit */
    void quit()
    {
        TTF_CloseFont(font_big);
        TTF_CloseFont(font_medium);
        TTF_CloseFont(font_small);
    }
}

#endif