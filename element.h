#ifndef ELEMENT_H
#define ELEMENT_H
#include <cstdlib>
template<class TYPE>
class Element
{
private:
    Element<TYPE>* pNext;
    Element<TYPE>* pPrev;
    TYPE* pInfo;

public:
    Element();
    ~Element();

    void setNext(Element<TYPE>* pN);
    Element<TYPE>* getNext();

    void setPrev(Element<TYPE>* pP);
    Element<TYPE>* getPrev();

    void setInfo(TYPE* pI);
    TYPE* getInfo();
};

template<class TYPE>
Element<TYPE>::Element()
{
    pNext = NULL;
    pPrev = NULL;
    pInfo = NULL;
}

template<class TYPE>
void Element<TYPE>::setNext(Element<TYPE> *pN)
{
    pNext = pN;
}

template<class TYPE>
Element<TYPE>* Element<TYPE>::getNext()
{
    return pNext;
}

template<class TYPE>
void Element<TYPE>::setPrev(Element<TYPE>* pP)
{
    pPrev = pP;
}

template<class TYPE>
Element<TYPE>* Element<TYPE>::getPrev()
{
    return pPrev;
}

template<class TYPE>
void Element<TYPE>::setInfo(TYPE *pI)
{
    pInfo = pI;
}

template<class TYPE>
TYPE* Element<TYPE>::getInfo()
{
    return pInfo;
}

#endif // ELEMENT_H
