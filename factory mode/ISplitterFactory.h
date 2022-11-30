#pragma once
class ISplitter
{
public:
    virtual void split() = 0;
    virtual ~ISplitter(){}
};

class SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter() = 0;
    virtual ~SplitterFactory(){}
};