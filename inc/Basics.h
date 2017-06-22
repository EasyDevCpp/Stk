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
#ifndef _StkBasics
#define _StkBasics

namespace Base
{
    void renderCopyEx(SDL_Texture* tex,int x,int y,int w,int h)
	{
	    SDL_Rect temp={x,y,w,h};
	    SDL_RenderCopy(render, tex, NULL, &temp);
	}

	void renderFillRect(SDL_Color color,int x,int y,int w,int h)
	{
	    SDL_Rect temp={x,y,w,h};
	    SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
	    SDL_RenderFillRect(render,&temp);
	}

	void renderDrawRect(SDL_Color color,int x,int y,int w,int h)
	{
		SDL_Rect temp={x,y,w,h};
		SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
	    SDL_RenderDrawRect(render,&temp);
	}
}

#endif