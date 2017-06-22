#include "inc/Stk.h"

#include <iostream>

class App: public Stk::Window
{
private:

public:
    App()
    {
        init("Example",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500);

        addScreen(new Stk::Screen());
        getScreen(0)->add(new Stk::Button("Test",40,40,240,40,1));

        joinLoop();
    }

    void action()
    {

    }

    bool end()
    {
        return getScreen(0)->get(0)->getEvent()==2;
    }
};

int main(int argc,char* argv[])
{
    App app;
    return 0;
}