#pragma once

class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;
    virtual ~Stream(){}
};

class FileStream : public Stream
{
public:
    virtual char Read(int number)
    {

    }

    virtual void Seek(int position)
    {

    }

    virtual void Write(char data)
    {

    }
};


class NetworkStream : public Stream
{
public:
    virtual char Read(int number)
    {

    }

    virtual void Seek(int position)
    {

    }

    virtual void Write(char data)
    {

    }
};

class MemoryStream : public Stream
{
public:
    virtual char Read(int number)
    {

    }

    virtual void Seek(int position)
    {

    }

    virtual void Write(char data)
    {

    }
};

class DecoratorStream : public Stream
{
protected:
    Stream* stream;

    DecoratorStream(Stream* stm) : stream(stm)
    {

    }
};

class CryptoStream : public DecoratorStream
{
public:
    CryptoStream(Stream* stm) : DecoratorStream(stm)
    {

    }

    virtual char Read(int number)
    {
        stream->Read(number);
    }

    virtual void Seek(int position)
    {
        stream->Seek(position);
    }

    virtual void Write(char data)
    {
        stream->Write(data);
    }
};

class BufferedStream : public DecoratorStream
{
public:
    BufferedStream(Stream* stm) : DecoratorStream(stm)
    {

    }

    virtual char Read(int number)
    {
        stream->Read(number);
    }

    virtual void Seek(int position)
    {
        stream->Seek(position);
    }

    virtual void Write(char data)
    {
        stream->Write(data);
    }
};

void Process()
{
    FileStream* s1 = new FileStream();
    CryptoStream* s2 = new CryptoStream(s1);
    BufferedStream* s3 = new BufferedStream(s1);
    BufferedStream* s4 = new BufferedStream(s2);
}