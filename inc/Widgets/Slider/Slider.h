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
#ifndef _StkSlider
#define _StkSlider

class Slider: public Widget
{
private:
    int value;
    Uint32 timer;

public:
    Slider(){}
    Slider(int x,int y,int width,int value=0)
    {
        init(x,y,width,6,false,true);
        this->value=value;
    }
    ~Slider(){}

    void draw()
    {
        if(getState())
        {
            Base::renderFillRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
            Base::renderFillRect(Style::hover_color,getX()+2,getY()+2,((double)(getWidth()-4)*value/100),2);
            Base::renderFillRect(Style::normal_color,getX()-4+((double)getWidth()*value/100),getY()-7,8,20);

            if(mouse_x>=getX()&&mouse_x<=getX()+getWidth()&&mouse_y>=getY()-7&&mouse_y<=getY()+getHeight()+7
                &&SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT)
            {
                if(SDL_GetTicks()-timer>=15)
                {
                    if(mouse_x>=getX()-4+((double)getWidth()*value/100))
                    {
                        value++;
                        timer=SDL_GetTicks();
                    }
                    else if(mouse_x<=getX()-4+((double)getWidth()*value/100))
                    {
                        value--;
                        timer=SDL_GetTicks();
                    }
                }
            }
        }
        else
        {
            Base::renderFillRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
            Base::renderFillRect(Style::disabled_color,getX()+2,getY()+2,getWidth()-4,2);
            Base::renderFillRect(Style::disabled_color,getX()-4+((double)getWidth()*value/100),getY()-7,8,20);
        }
    }

    void setValue(int v)
    {
        value=v;
    }

    int getValue()
    {
        return value;
    }
};

#endif