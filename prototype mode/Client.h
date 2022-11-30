#pragma once
#include"ConcretePrototype.h"
class Form
{

};

class MainForm : public Form
{
private:
    ISplitter* prototype;
public:
    MainForm(ISplitter* prototype)
    {
        this->prototype = prototype;
    }

    void Button_Click()
    {
        ISplitter* splitter = prototype->clone();
        splitter->split();
    }
};