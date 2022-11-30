#pragma once
#include"template_1.h"

class Application : public Library
{
private:
    static int time;
protected:
    virtual bool Step2()
    {
        std::cout << "2" << std::endl;
        return true;
    }

    virtual void Step4()
    {
        if(time % 2)
            std::cout << "4" << std::endl;
        ++time;
    }
};

int Application::time = 0;