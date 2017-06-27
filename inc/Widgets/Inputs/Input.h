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
#ifndef _StkInput
#define _StkInput

class Input: public Widget
{
private:
    SDL_Texture* text;
    int text_w;
    int text_h;
    int fmode;
    int cursor;

public:
    Input(){}
    Input(std::string widgetText,int x,int y,int width,int height,int font_mode)
    {
        init(x,y,width,height,false,true);
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
        cursor=0;
        fmode=font_mode;
    }
    ~Input()
    {
        SDL_DestroyTexture(text);
    }

    void draw()
    {
        if(getState())
        {
            if(getEvent()==0)
            {
                Base::renderFillRect(Style::normal_color,getX(),getY(),getWidth(),getHeight());
            }
            else
            {
                Base::renderFillRect(Style::hover_color,getX(),getY(),getWidth(),getHeight());
            }
            Base::renderDrawRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
            Base::renderCopyEx(text,getX()+getWidth()/2-text_w/2,getY()+getHeight()/2-text_h/2,text_w,text_h);
        }
        else
        {
            Base::renderFillRect(Style::disabled_color,getX(),getY(),getWidth(),getHeight());
            Base::renderDrawRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
            Base::renderCopyEx(text,getX()+getWidth()/2-text_w/2,getY()+getHeight()/2-text_h/2,text_w,text_h);
        }
    }

    void setText(std::string widgetText,int font_mode)
    {
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],widgetText.c_str(),Style::text_color));
        TTF_SizeText(Style::font[font_mode],widgetText.c_str(),&text_w,&text_h);
    }
};

#endif