#pragma once

class NetworkState
{
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;
    virtual ~NetworkState(){}
};

class OpenState : public NetworkState
{
private:
    static NetworkState* m_instance;
    OpenState(){}
    OpenState(const OpenState& other){}
public:
    static NetworkState* getInstance()
    {
        if(m_instance == nullptr)
            m_instance = new OpenState();
        return m_instance;
    }

    virtual void Operation1()
    {
        pNext = CloseState::getInstance();
    }

    virtual void Operation2()
    {
        pNext = ConnectState::getInstance();
    }

    virtual void Operation3()
    {
        pNext = OpenState::getInstance();
    }
};

class CloseState : public NetworkState
{
private:
    static NetworkState* m_instance;
    CloseState(){}
    CloseState(const CloseState& other){}
public:
    static NetworkState* getInstance()
    {
        if(m_instance == nullptr)
            m_instance = new CloseState();
        return m_instance;
    }

    virtual void Operation1()
    {
        pNext = ConnectState::getInstance();
    }

    virtual void Operation2()
    {
        pNext = OpenState::getInstance();
    }

    virtual void Operation3()
    {
        pNext = CloseState::getInstance();
    }
};

class ConnectState : public NetworkState
{
private:
    static NetworkState* m_instance;
    ConnectState(){}
    ConnectState(const ConnectState& other){}
public:
    static NetworkState* getInstance()
    {
        if(m_instance == nullptr)
            m_instance = new ConnectState();
        return m_instance;
    }

    virtual void Operation1()
    {
        pNext = OpenState::getInstance();
    }

    virtual void Operation2()
    {
        pNext = CloseState::getInstance();
    }

    virtual void Operation3()
    {
        pNext = ConnectState::getInstance();
    }
};

class NetworkProcessor
{
private:
    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState)
    {
        this->pState = pState;
    }

    void Operation1()
    {
        pState->Operation1();
        pState = pState->pNext;
    }

    void Operation2()
    {
        pState->Operation2();
        pState = pState->pNext;
    }

    void Operation1()
    {
        pState->Operation2();
        pState = pState->pNext;
    }
};