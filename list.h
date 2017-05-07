#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "element.h"

using std::cout;
using std::endl;

template<class TYPE>
class List
{
private:
    Element<TYPE>* pFirst;
    Element<TYPE>* pCurrent;
public:
    List();
    ~List();
    void initialize();
    void clear();
    bool addElement(Element<TYPE>* pElement);
    bool addInfo(TYPE* pInfo);
    void listInfos();
    Element<TYPE>* getFirst();
    Element<TYPE>* getCurrent();
};

template<class TYPE>
List<TYPE>::List( )
{
    initialize();
}

template<class TYPE>
List<TYPE>::~List ( )
{
    clear();
}

template<class TYPE>
void List<TYPE>::initialize()
{
     pFirst = NULL;
     pCurrent = NULL;
}

template<class TYPE>
void List<TYPE>::clear()
{
     Element<TYPE>* paux1;
     Element<TYPE>* paux2;

     paux1 = pFirst;
     paux2 = paux1;

     while (paux1 != NULL)
     {
         paux2 = paux1->getNext();
         //delete (paux1->getInfo())
         delete (paux1);
         paux1 = paux2;
     }

     pFirst = NULL;
     pCurrent    = NULL;
}

template<class TYPE>
bool List<TYPE>::addElement ( Element<TYPE>* pElement )
{
    if (NULL != pElement)
    {

       if (NULL == pFirst)
       {
          pFirst = pElement;
          pFirst->setPrev ( NULL );
          pFirst->setNext ( NULL );
          pCurrent = pFirst;
      }
      else
      {
          pElement->setPrev ( pCurrent );
          pElement->setNext ( NULL );
          pCurrent->setNext ( pElement );
          pCurrent = pCurrent->getNext ( );
      }
      return true;
    }
    else
    {
        cout << "Erro, Element nulo na List." << endl;
        return false;
    }
}

template<class TYPE>
bool List<TYPE>::addInfo( TYPE *pInfo )
{
     if (NULL != pInfo)
     {
          Element<TYPE>* pElement;
          pElement = new Element<TYPE>();
          //pElement->setNome (nome);
          pElement->setInfo (pInfo);
          addElement (pElement);
          return true;
     }
     else
     {
          printf ( "Erro, Element (informação) nulo(a) na List. \n" );
          return false;
     }
}

template<class TYPE>
void List<TYPE>::listInfos()
{
    Element<TYPE>* paux;
    paux = pFirst;

    if (NULL != pFirst)
    {
         while (NULL != paux)
         {
              printf ( "Element na List %s \n", paux->getNome() );
              paux = paux->getNext();
         }
    }
}
template<class TYPE>
Element<TYPE>* List<TYPE>::getFirst()
{
    return pFirst;
}
template<class TYPE>
Element<TYPE>* List<TYPE>::getCurrent()
{
    return pCurrent;
}

#endif // LIST_H
