#include "inc/Stk.h"

class App: public Stk::Window
{
private:

public:
    App()
    {
        init("Example",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500);

        addScreen(new Stk::Screen());
        //getScreen(0)->add(new Stk::Button());

        joinLoop();
    }

    void action()
    {

    }

    bool end()
    {
        
    }
};

int main(int argc,char* argv[])
{
    App app;
    return 0;
}