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
public:
    EventLoop(){SDL_StartTextInput();}
    ~EventLoop(){SDL_StopTextInput();}
    bool loop()
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)    
            {
                case SDL_QUIT:
                    return true;
                    break;
                case SDL_TEXTINPUT:
                    for(int i=0;i<Internal::text_active.size();i++)
                    {
                        if(Internal::text_active.at(i))
                        {
                            Internal::text_input.at(i)+=event.text.text;
                            Internal::text_update.at(i)=true;
                            Internal::text_cursor.at(i)++;
                            break;
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_BACKSPACE)
                    {
                        for(int i=0;i<Internal::text_active.size();i++)
                        {
                            if(Internal::text_active.at(i))
                            {
                                if(Internal::text_cursor.at(i)>0)
                                {
                                    Internal::text_input.at(i)=Internal::text_input.at(i).erase(Internal::text_cursor.at(i)-1,Internal::text_marklen.at(i));
                                    Internal::text_update.at(i)=true;
                                    Internal::text_cursor.at(i)--;
                                    Internal::text_marklen.at(i)=1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(event.key.keysym.sym==SDLK_LEFT)
                    {
                        for(int i=0;i<Internal::text_active.size();i++)
                        {
                            if(Internal::text_active.at(i))
                            {
                                const Uint8* keys=SDL_GetKeyboardState(NULL);
                                if(keys[SDL_SCANCODE_LSHIFT]||keys[SDL_SCANCODE_RSHIFT])
                                {
                                    
                                }
                                if(Internal::text_cursor.at(i)>0)
                                {
                                    Internal::text_cursor.at(i)--;
                                    break;
                                }
                            }
                        }
                    }
                    break;
            }
        }
        return false;
    }
};

#endif