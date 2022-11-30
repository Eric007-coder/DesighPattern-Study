#pragma once
#include"ISplitterFactory.h"

class BinarySplitter : public ISplitter
{
public:
    virtual void split()
    {

    }
};

class TxtSplitter : public ISplitter
{
public:
    virtual void split()
    {
        
    }
};

class PictureSplitter : public ISplitter
{
public:
    virtual void split()
    {
        
    }
};

class VideoSplitter : public ISplitter
{
public:
    virtual void split()
    {
        
    }
};

class BinarySplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()
    {
        return new VideoSplitter();
    }
};