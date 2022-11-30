#pragma once
#include"FileSplitter.h"

class Form
{

};

class MainForm : public Form
{
private:
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* factory)
    {
        this->factory = factory;
    }

    void Button1_Click()
    {
        ISplitter* splitter = factory->CreateSplitter();
        splitter->split();
    }
};