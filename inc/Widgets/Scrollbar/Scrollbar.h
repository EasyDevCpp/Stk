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
#ifndef _StkScrollbar
#define _StkScrollbar

class Scrollbar: public Widget
{
private:
    Screen* sc;
    int id;
    bool vertical=false;
    bool horizontal=false;
    int atm_biggest_x=0;
    int atm_biggest_y=0;
    int vertical_v=0;
    int horizontal_v=0;
    int vertical_stepc=0;
    int horizontal_stepc=0;

public:
    Scrollbar(){}
    Scrollbar(Screen* screen)
    {
        sc=screen;
        Internal::scrollbar_mwheel.push_back(0);

        id=Internal::scrollbar_mwheel.size();

        for(Widget* t: screen->getAll())
        {
            if(t->getY()+t->getHeight()>Internal::height&&t->getY()+t->getHeight()>atm_biggest_y)
            {
                atm_biggest_y=t->getY()+t->getHeight();
                vertical=true;
            }
            if(t->getX()+t->getWidth()>Internal::width&&t->getX()+t->getWidth()>atm_biggest_x)
            {
                atm_biggest_x=t->getX()+t->getWidth();
                horizontal=true;
            }
        }
        screen->__setScrollbars(vertical,horizontal);
    }
    ~Scrollbar(){}

    void draw()
    {
        if(getState())
        {
            if(vertical)
            {
                Base::renderFillRect(Style::border_color,Internal::width-15,0,15,Internal::height-15);
                Base::renderFillRect(Style::normal_color,Internal::width-13,2+vertical_v,11,70);

                if(mouse_x>=Internal::width-15&&mouse_x<=Internal::width&&mouse_y>2+vertical_v+70&&mouse_y<=Internal::height-15&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT)
                {
                    if(vertical_v<Internal::height-93)
                    {                  
                        vertical_v+=5;
                        vertical_stepc+=(atm_biggest_y-Internal::height/2)/((Internal::height-93)/5);
                    }
                }
                else if(mouse_x>=Internal::width-15&&mouse_x<=Internal::width&&mouse_y<2+vertical_v&&mouse_y>=0&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT)
                {
                    if(vertical_v>0)
                    {
                        vertical_v-=5;
                        vertical_stepc-=(atm_biggest_y-Internal::height/2)/((Internal::height-93)/5);
                    }   
                }
            }
            if(horizontal)
            {
                Base::renderFillRect(Style::border_color,0,Internal::height-15,Internal::width-15,15);
                Base::renderFillRect(Style::normal_color,2+horizontal_v,Internal::height-13,70,11);

                if(mouse_y>=Internal::height-15&&mouse_y<=Internal::height&&mouse_x>2+horizontal_v+70&&mouse_x<=Internal::width-15&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT)
                {
                    if(horizontal_v<Internal::width-93)
                    {                  
                        horizontal_v+=5;
                        horizontal_stepc+=(atm_biggest_x-Internal::width/2)/((Internal::width-93)/5);
                    }
                }
                else if(mouse_y>=Internal::height-15&&mouse_y<=Internal::height&&mouse_x<2+horizontal_v&&mouse_x>=0&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT)
                {
                    if(horizontal_v>0)
                    {
                        horizontal_v-=5;
                        horizontal_stepc-=(atm_biggest_x-Internal::width/2)/((Internal::width-93)/5);
                    }   
                }
            }
        }
        else
        {
            
        }
    }
    /* TODO: implement
    void setVerticalValue(int v)
    {
        vertical_v=v;
        
    }
    void setHorizontalValue(int v){horizontal_v=v;}
    */
    int getVerticalValue(){return vertical_stepc;}
    int getHorizontalValue(){return horizontal_stepc;}
};

#endif