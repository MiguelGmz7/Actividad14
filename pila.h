#ifndef PILA_H
#define PILA_H

#include "listadoble.h"
template<class T>
class Pila
{
    ListaDoble<T> list;
public:
    Pila();
    void push(const T& data);
    void pop();
    T* top();
    size_t size();
    bool empty();
};

template<class T>
Pila<T>::Pila()
{

}

template<class T>
void Pila<T>::push(const T& data)
{
    list.push_back(data);
}

template<class T>
void Pila<T>::pop()
{
    list.pop_back();
}

template<class T>
T* Pila<T>::top()
{
    return list.back();
}

template<class T>
size_t Pila<T>::size()
{
    return list.size();
}

template<class T>
bool Pila<T>::empty()
{
    return list.empty();
}
#endif