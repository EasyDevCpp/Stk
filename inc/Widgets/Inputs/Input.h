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
    int id;
    Uint32 blink_timer;
    bool blink=false;

public:
    Input(){}
    Input(std::string defaultText,int x,int y,int width,int height,int font_mode)
    {
        init(x,y,width,height,true,true);
        text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[font_mode],defaultText.c_str(),Style::border_color));
        TTF_SizeText(Style::font[font_mode],defaultText.c_str(),&text_w,&text_h);
        cursor=0;
        fmode=font_mode;
        Internal::text_input.push_back("");
        Internal::text_active.push_back(false);
        Internal::text_update.push_back(false);
        Internal::text_cursor.push_back(0);
        id=Internal::text_input.size()-1;
    }
    ~Input()
    {
        SDL_DestroyTexture(text);
    }

    void draw()
    {
        if(getState())
        {
            if(getEvent()==EVENT_CLICK)
            {
                if(!Internal::text_active.at(id))
                {
                    for(int i=0;i<Internal::text_active.size();i++)
                    {
                        Internal::text_active.at(i)=false;    
                    }
                    Internal::text_active.at(id)=true;
                }
                else
                {
                    Internal::text_active.at(id)=false;
                }
            }
            else if(SDL_MOUSEBUTTONDOWN&&SDL_BUTTON(SDL_GetMouseState(&mouse_x,&mouse_y))==SDL_BUTTON_LEFT&&
                    SDL_GetTicks()-mouse_timer>=180)
            {
                Internal::text_active.at(id)=false;
                setActive(false);
                mouse_timer=SDL_GetTicks();
            }

            if(getActive())
            {
                Base::renderFillRect(Style::hover_color,getX(),getY(),getWidth(),getHeight());
                Base::renderFillRect(Style::normal_color,getX()+1,getY()+1,getWidth()-2,getHeight()-2);

                if(Internal::text_update.at(id))
                {
                    text=SDL_CreateTextureFromSurface(render,TTF_RenderText_Blended(Style::font[fmode],Internal::text_input.at(id).c_str(),Style::text_color));
                    TTF_SizeText(Style::font[fmode],Internal::text_input.at(id).c_str(),&text_w,&text_h);
                    Internal::text_update.at(id)=false;
                }
            }
            else
            {
                Base::renderFillRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
                Base::renderFillRect(Style::normal_color,getX()+1,getY()+1,getWidth()-2,getHeight()-2);
            }

            Base::renderCopyEx(text,getX()+8,getY()+getHeight()/2-text_h/2,text_w,text_h);
        }
        else
        {
            Base::renderFillRect(Style::border_color,getX(),getY(),getWidth(),getHeight());
            Base::renderFillRect(Style::disabled_color,getX()+1,getY()+1,getWidth()-2,getHeight()-2);
            Base::renderCopyEx(text,getX()+8,getY()+getHeight()/2-text_h/2,text_w,text_h);
        }
    }
};

#endif