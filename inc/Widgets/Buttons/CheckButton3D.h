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
#ifndef _StkCheckButton3D
#define _StkCheckButton3D

class CheckButton3D: public Widget
{
private:
    SDL_Texture* text;
    int text_w;
    int text_h;
    Uint32 ani_timer;
    int ani_pos;

public:
    CheckButton3D(){}
    CheckButton3D(std::string widgetText,int x,int y,int width,int height,int font_mode)
    {
        init(x,y,width,height,true,true);
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        ani_pos=0;
    }
    ~CheckButton3D()
    {
        SDL_DestroyTexture(text);
    }

    void draw()
    {
        if(getState())
        {
            if(!getActive())
            {
                if(getEvent()==0)
                {
                    Base::renderFillRect(Style::normal3d_color2,getX(),getY()+10,getWidth(),getHeight());
                    Base::renderFillRect(Style::normal3d_color1,getX(),getY()+ani_pos,getWidth(),getHeight());
                    if(SDL_GetTicks()-ani_timer>=25)
                    {
                        if(ani_pos>0)
                        {
                            ani_pos--;
                            ani_timer=SDL_GetTicks();
                        }
                    }
                }
                else if(getEvent()==1)
                {
                    Base::renderFillRect(Style::hover3d_color2,getX(),getY()+10,getWidth(),getHeight());
                    Base::renderFillRect(Style::hover3d_color1,getX(),getY()+ani_pos,getWidth(),getHeight());
                    if(SDL_GetTicks()-ani_timer>=25)
                    {
                        if(ani_pos<7)
                        {
                            ani_pos++;
                            ani_timer=SDL_GetTicks();
                        }
                    }
                }
                else if(getEvent()==2)
                {
                    Base::renderFillRect(Style::hover3d_color2,getX(),getY()+10,getWidth(),getHeight());
                    Base::renderFillRect(Style::hover3d_color1,getX(),getY()+7,getWidth(),getHeight());
                }
                Base::renderCopyEx(text,getX()+getWidth()/2-text_w/2,getY()+ani_pos+getHeight()/2-text_h/2,text_w,text_h);
            }
            else 
            {
                getEvent();
                Base::renderFillRect(Style::active3d_color2,getX(),getY()+10,getWidth(),getHeight());
                Base::renderFillRect(Style::active3d_color1,getX(),getY()+7,getWidth(),getHeight());
                Base::renderCopyEx(text,getX()+getWidth()/2-text_w/2,getY()+7+getHeight()/2-text_h/2,text_w,text_h);
            }
        }
        else
        {
            Base::renderFillRect(Style::disabled3d_color2,getX(),getY()+10,getWidth(),getHeight());
            Base::renderFillRect(Style::disabled3d_color1,getX(),getY()+ani_pos,getWidth(),getHeight());
            Base::renderCopyEx(text,getX()+getWidth()/2-text_w/2,getY()+ani_pos+getHeight()/2-text_h/2,text_w,text_h);
            if(SDL_GetTicks()-ani_timer>=25)
            {
                if(ani_pos>0)
                {
                    ani_pos--;
                    ani_timer=SDL_GetTicks();
                }
            }
        }
    }
};

#endif