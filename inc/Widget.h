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
#ifndef _StkWidget
#define _StkWidget

class Widget
{
private:
    int x;
    int y;
    int w;
    int h;
    int event=0;
    bool check=false;
    bool active=false;
    bool state=true;

public:
    Widget(){}
    ~Widget(){}

    void init(int x_pos,int y_pos,int width,int height,bool activate,bool w_state)
    {
        x=x_pos;
        y=y_pos;
        w=width;
        h=height;
        check=activate;
        state=w_state;
    }

    virtual void draw()=0;

    int getEvent()
    {
        if(state)
        {
            if(!active)
            {
                if(mouse_x>=x&&mouse_x<=x+w&&mouse_y>=y&&mouse_y<=y+h&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT&&
                    SDL_GetTicks()-mouse_timer>=180)
                {
                    if(check)
                    {
                        active=true;
                    }
                    event=2;
                    mouse_timer=SDL_GetTicks();
                }
                else if(mouse_x>=x&&mouse_x<=x+w&&mouse_y>=y&&mouse_y<=y+h)
                {
                    event=1;
                }
                else
                {
                    event=0;
                }
            }
            else
            {
                if(mouse_x>=x&&mouse_x<=x+w&&mouse_y>=y&&mouse_y<=y+h&&
                    SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT&&
                    SDL_GetTicks()-mouse_timer>=180)
                {
                    active=false;
                    event=2;
                    mouse_timer=SDL_GetTicks();
                }
                else
                {
                    event=0;
                }
            }
        } 
        else 
        {
            event=0;
        }
        return event;
    }

    int getX(){return x;}
    int getY(){return y;}
    int getWidth(){return w;}
    int getHeight(){return h;}
    bool getState(){return state;}
    bool getActive(){return active;}
    void setX(int xp){x=xp;}
    void setY(int yp){y=yp;}
    void setWidth(int width){w=width;}
    void setHeight(int height){h=height;}
    void setState(bool s){state=s;}
    void setActive(bool a){active=a;}
};

#endif