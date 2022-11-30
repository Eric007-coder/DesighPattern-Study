#pragma once
#include"prototype.h"
#include<string>

class BinarySplitter : public ISplitter
{
private:
    std::string m_filePath;
    int m_fileNumber;
public:
    BinarySplitter(std::string filePath,int fileNumber) : m_filePath(filePath),m_fileNumber(fileNumber) {}

    BinarySplitter(BinarySplitter* prototype)
    {
        this->m_filePath = prototype->m_filePath;
        this->m_fileNumber = prototype->m_fileNumber;
    }

    virtual void split()
    {

    }

    virtual ISplitter* clone()
    {
        return new BinarySplitter(*this);
    }
};

class TxtSplitter : public ISplitter
{
private:
    std::string m_filePath;
    int m_fileNumber;
public:
    TxtSplitter(std::string filePath,int fileNumber) : m_filePath(filePath),m_fileNumber(fileNumber) {}

    TxtSplitter(TxtSplitter* prototype)
    {
        this->m_filePath = prototype->m_filePath;
        this->m_fileNumber = prototype->m_fileNumber;
    }

    virtual void split()
    {

    }
    
    virtual ISplitter* clone()
    {
        return new TxtSplitter(*this);
    }
};

class PictureSplitter : public ISplitter
{
private:
    std::string m_filePath;
    int m_fileNumber;
public:
    PictureSplitter(std::string filePath,int fileNumber) : m_filePath(filePath),m_fileNumber(fileNumber) {}

    PictureSplitter(PictureSplitter* prototype)
    {
        this->m_filePath = prototype->m_filePath;
        this->m_fileNumber = prototype->m_fileNumber;
    }

    virtual void split()
    {

    }
    
    virtual ISplitter* clone()
    {
        return new PictureSplitter(*this);
    }
};

class VideoSplitter : public ISplitter
{
private:
    std::string m_filePath;
    int m_fileNumber;
public:
    VideoSplitter(std::string filePath,int fileNumber) : m_filePath(filePath),m_fileNumber(fileNumber) {}

    VideoSplitter(VideoSplitter* prototype)
    {
        this->m_filePath = prototype->m_filePath;
        this->m_fileNumber = prototype->m_fileNumber;
    }

    virtual void split()
    {

    }
    
    virtual ISplitter* clone()
    {
        return new VideoSplitter(*this);
    }
};