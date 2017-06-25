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
#ifndef _StkCheckbox
#define _StkCheckbox

class Checkbox: public Widget
{
private:
    SDL_Texture* text;
    int text_w;
    int text_h;

public:
    Checkbox(){}
    Checkbox(std::string widgetText,int x,int y,int font_mode)
    {
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        init(x,y,text_h,text_h,true,true);
    }
    ~Checkbox()
    {
        SDL_DestroyTexture(text);
    }

    void draw()
    {
        if(getState())
        {
            if(getEvent()==0)
            {
                Base::renderFillRect(Style::border_color,getX(),getY(),text_h,text_h);
                Base::renderFillRect(Style::normal_color,getX()+3,getY()+3,text_h-6,text_h-6);
            }
            else
            {
                Base::renderFillRect(Style::hover_color,getX(),getY(),text_h,text_h);
                Base::renderFillRect(Style::normal_color,getX()+3,getY()+3,text_h-6,text_h-6);
            }
            if(getActive())
            {
                Base::renderFillRect(Style::active_color,getX(),getY(),text_h,text_h);
                Base::renderFillRect(Style::normal_color,getX()+3,getY()+3,text_h-6,text_h-6);
            }
            Base::renderCopyEx(text,getX()+text_h+6,getY(),text_w,text_h);
        }
        else
        {
            Base::renderFillRect(Style::border_color,getX(),getY(),text_h,text_h);
            Base::renderFillRect(Style::disabled_color,getX()+3,getY()+3,text_h-6,text_h-6);
            Base::renderCopyEx(text,getX()+text_h+6,getY(),text_w,text_h);
        }
    }

    void setText(std::string widgetText,int font_mode)
    {
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        setWidth(text_h);
        setHeight(text_h);
    }
};

#endif