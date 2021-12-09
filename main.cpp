#include<iostream>
using namespace std;
#include "pila.h"
#include "cola.h"
int main(){

    Cola<int> cola;

    cola.push(-1);                  // encolar
    cola.push(0);                   // encolar
    cola.push(1);                   // encolar
    cola.push(2);                   // encolar
    cola.push(3);                   // encolar

    cout << *cola.front() << endl;  // frente de la cola
    cout << *cola.back() << endl;   // final de la cola

    cola.pop();                     // desencolar

    cout << cola.size() << endl;    // imprimir la candidad de elementos en la cola

    Pila<int> pila;

    while (!cola.empty())           // ciclo para desencolar los elementos
    {
        int *e = cola.front();      // respaldo del frente de la cola
        if (e != nullptr) {         // si no es un puntero a nulo
            pila.push(*e);          // apilamos el entero 
        }

        cola.pop();                 // desencolar
    }
    
    pila.push(10);                  // apilar

    cout << pila.size() << endl;    // imprimir la candidad de elementos en la pila

    while (!pila.empty())           // ciclo para desapilar los elementos
    {
        int *e = pila.top();        // respaldo del tope de la pila
        if (e != nullptr) {         // si no es un puntero nulo
            cout << *e << endl;     // imprime el tope de la pila
        }

        pila.pop();                 // desapilar
    }
    
    cout << pila.size() << endl;    // imprimir la candidad de elementos en la pila
    return 0;
}