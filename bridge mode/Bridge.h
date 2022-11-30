#pragma once
#include<string>

class MessagerImp;
class Messager
{
protected:
    MessagerImp* messagerImp;

    Messager(MessagerImp* mimp) : messagerImp(mimp){}
public:
    virtual void Login(std::string username,std::string password) = 0;
    virtual void SendMessage(std::string message) = 0;
    virtual void SendPicture(std::string image) = 0;
    virtual ~Messager(){}
};

class MessagerImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    virtual ~MessagerImp(){}
};

class PCMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {

    }

    virtual void DrawShape()
    {

    }

    virtual void WriteText()
    {

    }

    virtual void Connect()
    {

    }
};

class MobileMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {

    }

    virtual void DrawShape()
    {

    }

    virtual void WriteText()
    {

    }

    virtual void Connect()
    {
        
    }
};

class MessagerLite : public Messager
{
public:
    MessagerLite(MessagerImp* mimp) : Messager(mimp){}

    virtual void Login(std::string username,std::string password)
    {
        messagerImp->Connect();
    }

    virtual void SendMessage(std::string message)
    {
        messagerImp->WriteText();
    }

    virtual void SendPicture(std::string image)
    {
        messagerImp->DrawShape();
    }
};

class MessagerPerfect : public Messager
{
public:
    MessagerPerfect(MessagerImp* mimp) : Messager(mimp){}

    virtual void Login(std::string username,std::string password)
    {
        messagerImp->PlaySound();
        messagerImp->Connect();
    }

    virtual void SendMessage(std::string message)
    {
        messagerImp->PlaySound();
        messagerImp->WriteText();
    }

    virtual void SendPicture(std::string image)
    {
        messagerImp->PlaySound();
        messagerImp->DrawShape();
    }
};

void Process()
{
    MessagerImp* mImp = new PCMessagerImp();
    MessagerPerfect* m = new MessagerPerfect(mImp);
}