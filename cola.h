#ifndef COLA_H
#define COLA_H

#include "listadoble.h"
template<class T>
class Cola
{
    ListaDoble<T> list;

public:
      Cola();
      void push(const T& data);
      void pop();
      T* front();
      T* back();
      size_t size();
      bool empty();
};

template<class T>
Cola<T>::Cola(){}

template<class T>
void Cola<T>::push(const T& data)
{
    list.push_back(data);
}

template<class T>
void Cola<T>::pop()
{
    list.pop_front();
}

template<class T>
T* Cola<T>::front()
{
    return list.front();
}

template<class T>
T* Cola<T>::back()
{
    return list.back();
}

template<class T>
size_t Cola<T>::size()
{
    return list.size();
}

template<class T>
bool Cola<T>::empty()
{
    return list.empty();
}
#endif