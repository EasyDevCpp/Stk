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
#ifndef _StkEventLoop
#define _StkEventLoop

class EventLoop
{
private:

public:
    EventLoop(){}

    bool loop()
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)    
            {
                case SDL_QUIT:
                    return true;
                    break;
            }
        }
        return false;
    }
};

#endif