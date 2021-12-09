#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
using namespace std;

template <class T>
class ListaDoble
{
public:
    //Constructor y destructor
    ListaDoble();
    ~ListaDoble();
    
    //Insertar
    void push_front(const T& dato);
    void push_back(const T& dato);
    void insert(size_t p, const T& dato);

    //Tamaño
    size_t size();
    bool empty();

    //Sobrecarga
    ListaDoble& operator<<(const T &dato)
    {
        push_back(dato);
        return *this;
    }
    ListaDoble& operator>>(const T &dato)
    {
        push_front(dato);
        return *this;
    }
    T* operator[](size_t p)
    {
        size_t pos = 0;
        Nodo* temp = head;
        while(temp != nullptr)
        {
            if(p == pos){
                return &temp->dato;
            }
            temp = temp->sig;
            pos++;
        }
        return nullptr;
    }

    //Recorridos
    void print();
    void print_reverse();
    T* front();
    T* back();

    //Buscar
    T* find(const T& dato);

    //Eliminar
    void pop_front();
    void pop_back();
    void erase(size_t p);
    void remove_if(const T& dato); 
private:
    struct Nodo {
        T dato;
        Nodo *sig;
        Nodo *ant;

        Nodo(const T &dato, Nodo *sig = nullptr, Nodo *ant = nullptr)
        : dato(dato), sig(sig), ant(ant) {}
    };

    Nodo *head;
    Nodo *tail;
    size_t cont;
};

template <class T>
ListaDoble<T>::ListaDoble()
{
    head = nullptr;
    tail = nullptr;
    cont = 0;
}

template <class T>
ListaDoble<T>::~ListaDoble()
{
    while(!empty()){
        pop_back();
    }
}

template <class T>
bool ListaDoble<T>::empty()
{
    return cont == 0;
}

template <class T>
void ListaDoble<T>::push_front(const T &dato)
{
    Nodo *nodo = new Nodo(dato, head);
    if (cont == 0) { // empty()
        head = nodo;
        tail = nodo;
    } else {
        head->ant = nodo;
        head = nodo;
    }
    cont++;
}

template <class T>
void ListaDoble<T>::push_back(const T &dato)
{
    Nodo *nodo = new Nodo(dato, nullptr, tail);
    if (cont == 0) {
        head = nodo;
        tail = nodo;
    } else {
        tail->sig = nodo;
        tail = nodo;
    }
    cont++;
}

template <class T>
size_t ListaDoble<T>::size()
{
    return cont;
}

template <class T>
void ListaDoble<T>::print()
{
    Nodo *temp = head;

    if(empty()){
        cout<<"Lista vacia"<<endl;
    } else{
    while (temp != nullptr) 
    {
        cout << temp->dato << endl;
        temp = temp->sig;
    }    
    }
}

template <class T>
void ListaDoble<T>::print_reverse()
{
    Nodo *temp = tail;

    if(empty()){
        cout<<"Lista vacia"<<endl;
    } else{
    while (temp != nullptr)
    {
        cout << temp->dato << endl;
        temp = temp->ant;
    }    
    }
}

template <class T>
T* ListaDoble<T>::front()
{
    if (empty()) {
        return nullptr;
    } else {
        return &head->dato;
    }
}

template <class T>
T* ListaDoble<T>::back()
{
    if (empty()) {
        return nullptr;
    } else {
        return &tail->dato;
    }
}
template <class T>
T* ListaDoble<T>::find(const T& dato)
{
    Nodo* temp = head;
    while(temp != nullptr)
    {
        if(temp->dato == dato){
            return &temp->dato;
        }
        temp = temp->sig;
    }
    return nullptr;
}
template<class T>
void ListaDoble<T>::pop_front()
{
    switch(cont){
        case 0: cout<<"Lista Vacia"<<endl; break;
        case 1: 
              delete head;
              head = nullptr;
              tail = nullptr;
              cont--;
        break;
        default:
              Nodo* temp = head->sig;
              temp->ant = nullptr;
              delete head;
              head = temp;
              cont--;
        break;
    }
}
template<class T>
void ListaDoble<T>::pop_back()
{
    switch(cont){
        case 0: cout<<"Lista Vacia"<<endl; break;
        case 1:
              delete tail;
              head = nullptr;
              tail = nullptr;
              cont--;
        break;
        default:
               Nodo* temp = tail->ant;
               temp->sig = nullptr;
               delete tail;
               tail = temp;
               cont--; 
        break;
    }
}
template<class T>
void ListaDoble<T>::insert(size_t p, const T& dato)
{
    if(p>=cont){
        cout<<"Posicion no valida"<<endl;
    }
    else if(p == 0){
        push_front(dato);
    }
    else{
        Nodo* temp = head->sig;
        size_t pos = 1;
        while(temp != nullptr){
            if(p == pos){
                Nodo* nodo = new Nodo(dato,temp,temp->ant);
                nodo->ant->sig = nodo;
                nodo->sig->ant = nodo;
                cont++;
                break;
            }
            pos++;
            temp = temp->sig;
        }
    }   
}
template<class T>
void ListaDoble<T>::erase(size_t p)
{
    if(p==0){
        pop_front();
    }
    else if(p==cont-1){
        pop_back();
    }
    else{
        Nodo* temp = head->sig;
        size_t pos = 1;
        while(temp != nullptr){
            if(p == pos){
                temp->sig->ant = temp->ant;
                temp->ant->sig = temp->sig;
                delete temp;
                cont--;
                break;
            }
            pos++;
            temp = temp->sig;
        }
    }
}
template<class T>
void ListaDoble<T>::remove_if(const T& dato)
{
    
    Nodo* mov = head;
    Nodo* temp;
    while(mov != nullptr){
        if(head->dato == dato){
           temp = head;
           head = head->sig;
           mov = mov->sig;
           delete temp;
           cont--;
           if(tail->dato == dato){
               temp == tail;
               tail = tail->ant;
               mov = mov->sig;
               delete temp;
               cont--;
           }
        }
        else {
            if(mov->sig != nullptr && mov->sig->dato == dato){
                temp = mov->sig;
                mov->sig = mov->sig->sig;
                temp->sig->ant = mov;
                delete temp;
                cont--;
            }
            else {
                mov = mov->sig;
            }
        }
    }
}
#endif