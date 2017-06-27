#include "inc/Stk.h"

class App: public Stk::Window
{
private:

public:
    App()
    {
        init("Example",Stk::CENTERED,Stk::CENTERED,500,500);

        addScreen(new Stk::Screen());
        getScreen(0)->add(new Stk::Button("Quit",40,40,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::CheckButton("Try Me!",40,100,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::Button3D("Try Me!",40,160,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::CheckButton3D("Try Me!",40,220,240,40,Stk::FONT_MEDIUM));
        getScreen(0)->add(new Stk::ClickLabel("Label1",40,280,Stk::FONT_BIG));

        addScreen(new Stk::Screen());
        getScreen(1)->add(new Stk::Checkbox("Box1",40,40,Stk::FONT_MEDIUM));
        getScreen(1)->add(new Stk::CheckLabel("Label1",40,100,Stk::FONT_MEDIUM));
        getScreen(1)->add(new Stk::Slider(40,160,420,35));
        getScreen(1)->add(new Stk::Input("Username",40,220,360,40,Stk::FONT_MEDIUM));

        joinLoop();
    }

    void action()
    {
        if(getScreenID()==0)
        {
            if(getScreen(0)->get(2)->getEvent()==Stk::EVENT_CLICK)
            {
                ((Stk::Button3D*)getScreen(0)->get(2))->setText("Hello World!",Stk::FONT_MEDIUM);
            }
            if(getScreen(0)->get(4)->getEvent()==Stk::EVENT_CLICK)
            {
                setScreenID(1);
            }
        }
    }

    bool end()
    {
        return getScreenID()==0&&getScreen(0)->get(0)->getEvent()==Stk::EVENT_CLICK;
    }
};

int main(int argc,char* argv[])
{
    App app;
    return 0;
}