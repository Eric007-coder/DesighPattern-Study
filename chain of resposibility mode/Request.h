#pragma once
#include<iostream>
#include<string>

enum class RequestType
{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

class Request
{
private:
    std::string description;
    RequestType reqType;
public:
    Request(const std::string& desc,RequestType type) : description(desc),reqType(type) {}
    RequestType getReqType() const { return reqType; }
    const std::string& getDescription() const { return description; }
};

class ChainHandler
{
private:
    ChainHandler* nextChain;

    void sendRequestToNextHandler(const Request& req)
    {
        if(nextChain != nullptr)
            nextChain->handle(req);
    }
protected:
    virtual bool canHandleRequest(const Request& req) = 0;
    virtual void processRequest(const Request& req) = 0;
public:
    ChainHandler() { nextChain = nullptr; }
    void setNextChain(ChainHandler* next) { nextChain = next; }

    void handle(const Request& req)
    {
        if(canHandleRequest(req))
            processRequest(req);
        else
            sendRequestToNextHandler(req);
    }
};

class Handler1 : public ChainHandler
{
protected:
    virtual bool canHandleRequest(const Request& req)
    {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }

    virtual void processRequest(const Request& req)
    {
        std::cout << "Handler1 is handle request:" << req.getDescription() << std::endl;
    }
};

class Handler2 : public ChainHandler
{
protected:
    virtual bool canHandleRequest(const Request& req)
    {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }

    virtual void processRequest(const Request& req)
    {
        std::cout << "Handler2 is handle request:" << req.getDescription() << std::endl;
    }
};

class Handler3 : public ChainHandler
{
protected:
    virtual bool canHandleRequest(const Request& req)
    {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }

    virtual void processRequest(const Request& req)
    {
        std::cout << "Handler3 is handle request:" << req.getDescription() << std::endl;
    }
};