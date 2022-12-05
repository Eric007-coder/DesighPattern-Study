#pragma once

class ISubject
{
public:
    virtual void process();
};

class SubjectProxy : public ISubject
{
public:
    virtual void process()
    {

    }
};

class ClienApp
{
    ISubject* subject;
public:
    ClienApp()
    {
        subject = new SubjectProxy();
    }

    void DoTask()
    {
        subject->process();
    }
};