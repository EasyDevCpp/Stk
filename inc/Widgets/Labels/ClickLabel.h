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
#ifndef _StkClickLabel
#define _StkClickLabel

class ClickLabel: public Widget
{
private:
    SDL_Texture* text;
    int text_w;
    int text_h;
    int ani_pos;
    Uint32 ani_timer;

public:
    ClickLabel(){}
    ClickLabel(std::string widgetText,int x,int y,int font_mode)
    {
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        init(x,y,text_w,text_h,false,true);

        ani_pos=0;
    }
    ~ClickLabel()
    {
        SDL_DestroyTexture(text);
    }

    void draw()
    {
        Base::renderCopyEx(text,getX(),getY(),text_w,text_h);
        if(getState())
        {
            if(getEvent()!=0)
            {
                if(SDL_GetTicks()-ani_timer>=30)
                {
                    if(ani_pos<3)
                    {
                        ani_pos++;
                        ani_timer=SDL_GetTicks();
                    }
                }
            }
            else
            {
                if(SDL_GetTicks()-ani_timer>=30)
                {
                    if(ani_pos>0)
                    {
                        ani_pos--;
                        ani_timer=SDL_GetTicks();
                    }
                }
            }
            Base::renderFillRect(Style::hover_color,getX(),getY()+text_h+4,text_w,ani_pos);
        }
    }

    void setText(std::string widgetText,int font_mode)
    {
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        setWidth(text_w);
        setHeight(text_h);
    }
};

#endif