/*
    Stk - SDL-based GUI Toolkit
    Copyright (C) 2017 Robin Krause

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
#ifndef _StkWindow
#define _StkWindow

class Window
{
private:
    int x;
    int y;
    int width;
    int height;
    std::string title;
    bool exit=false;
    int screen=0;

    EventLoop loop;

    std::vector<Screen*> screens;

    int vert_v;
    int hori_v;

public:
    Window()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();
    }
    void init(std::string title,int x_pos,int y_pos,int width,int height)
    {
        this->title=title;
        this->x=x_pos;
        this->y=y_pos;
        this->width=width;
        this->height=height;
        Internal::width=width;
        Internal::height=height;

        window=SDL_CreateWindow(title.c_str(),x,y,width,height,SDL_WINDOW_SHOWN);
        render=SDL_CreateRenderer(window,-1,0);

        Style::init();
    }
    ~Window()
    {
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
    }

    virtual void action()=0;
    virtual bool end()=0;

    void joinLoop()
    {
        while(!exit)
        {
            SDL_GetMouseState(&mouse_x,&mouse_y);

            if(loop.loop()||end())
            {
                exit=true;
            }
            
            SDL_SetRenderDrawColor(render,Style::background_color.r,Style::background_color.g,Style::background_color.b,Style::background_color.a);
            SDL_RenderClear(render);
            action();

            if(screens.at(screen)->__getVert())
            {
                vert_v=((Scrollbar*)screens.at(screen)->get(screens.at(screen)->getAll().size()-1))->getVerticalValue();
            }
            if(screens.at(screen)->__getHori())
            {
                hori_v=((Scrollbar*)screens.at(screen)->get(screens.at(screen)->getAll().size()-1))->getHorizontalValue();
            }

            for(Widget* t: screens.at(screen)->getAll())
            {
                if(screens.at(screen)->__getVert())
                {
                    t->setY(t->getOriginalY()-vert_v);
                }
                if(screens.at(screen)->__getHori())
                {
                    t->setX(t->getOriginalX()-hori_v);
                }
                t->draw();
            }
            SDL_RenderPresent(render);
            if(Options::MEDIUM_CPU_USAGE)
            {
                SDL_Delay(5);
            }
            else if(Options::LOW_CPU_USAGE)
            {
                SDL_Delay(10);
            }
            else if(Options::EXTRA_LOW_CPU_USAGE)
            {
                SDL_Delay(50);
            }
        }
    }

    void addScreen(Screen* s)
    {
        screens.push_back(s);
    }

    Screen* getScreen(int index)
    {
        return screens.at(index);
    }

    int getScreenID() {return screen;}
    void setScreenID(int id) {screen=id;}
    int getX() {return x;}
    int getY() {return y;}
    int getWidth() {return width;}
    int getHeight() {return height;}
    std::string getTitle() {return title;}
};

#endif