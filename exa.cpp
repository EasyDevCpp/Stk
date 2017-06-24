#include "inc/Stk.h"

#include <iostream>

class App: public Stk::Window
{
private:

public:
    App()
    {
        init("Example",Stk::CENTERED,Stk::CENTERED,500,500);

        addScreen(new Stk::Screen());
        getScreen(0)->add(new Stk::Button("Test",40,40,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::CheckButton("Test2",40,100,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::Button3D("Test3",40,160,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::CheckButton3D("Test4",40,220,240,40,Stk::FONT_MEDIUM));

        joinLoop();
    }

    void action()
    {
        
    }

    bool end()
    {
        return getScreen(0)->get(0)->getEvent()==Stk::EVENT_CLICK;
    }
};

int main(int argc,char* argv[])
{
    App app;
    return 0;
}