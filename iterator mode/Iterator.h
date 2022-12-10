#pragma once

template<typename T>
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
    virtual ~Iterator() {}
};

template<typename T>
class MyCollection
{
public:
    Iterator<T> GetIterator()
    {

    }
};

template<typename T>
class CollectionIterator : public Iterator<T>
{
private:
    MyCollection<T> mc;
public:
    CollectionIterator(const MyCollection<T>& c) : mc(c) { }

    virtual void first()
    {

    }

    virtual void next()
    {

    }

    virtual bool isDone() const
    {

    }

    virtual T& current()
    {
        
    }
};