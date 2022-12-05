<<<<<<< HEAD
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
=======
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
>>>>>>> 3e2fef08c314be36fe3e3714ef8b69883cdd43e6
};