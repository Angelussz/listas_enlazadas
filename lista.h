#include "nodo.h"
#include <iostream>

template<class T>
class Lista
{
    private:
        Nodo<T> *cabeza;
        int tamano;
    public:
        Lista();
        ~Lista();
        
        
        void agregar_f(T);
        void agregar_d(T,int);

        

        void remove_front();
        void remove_back();
        void remove(int);
        void mostrar();
};


template<class T>
Lista<T>::Lista():cabeza(NULL),tamano(0)
{
}    

template<class T>
void Lista<T>::agregar_f(T dato)
{
    Nodo<T>* aux =  new Nodo<T>(dato);
    
    if(cabeza==NULL)
        cabeza = aux;

    else
    {
        Nodo<T>* ptr = cabeza;
        while(ptr->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        ptr->setSiguiente(aux);
    }
    tamano++;
}


template<class T>
void Lista<T>::agregar_d(T dato,int n)
{
    if(n>tamano) return;

    Nodo<T>* aux =  new Nodo<T>(dato); 
    
    if(cabeza==NULL)
        cabeza = aux;
    else if(n==0)
    {
        aux->setSiguiente(cabeza);
        cabeza = aux;
    }
    else
    {
        int count = 0;
        Nodo<T>* puntero = cabeza ;
        while(count < (n-1))
        {
            puntero = cabeza->getSiguiente();
            count++;
        }
        aux->setSiguiente(puntero->getSiguiente());
        puntero->setSiguiente(aux);
    }
    tamano++;
}

template<class T>
void Lista<T>::remove_front()
{
    if(tamano ==0) return ;
    Nodo<T>* eliminar = cabeza;
    cabeza = cabeza->getSiguiente();
    delete eliminar;
    tamano--;
}


template<class T>
void Lista<T>::remove_back()
{
    if(tamano ==0) return ;
    if(tamano ==1) 
        remove_front();
    else
    {
        Nodo<T>* ptr = cabeza;
        while(ptr->getSiguiente()->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        Nodo<T>* eliminar = ptr->getSiguiente();
        ptr->setSiguiente(NULL);
        delete eliminar;
        tamano--;
    }
}

template <class T>
void Lista<T>::remove(int n)
{
    if(n >= tamano) return ;
    if(n == 0) 
        remove_front();
    else
    {
        Nodo<T>* ptr = cabeza;
        int count = 0;
        while(count < (n-1) )
        {
            ptr = ptr->getSiguiente();
            count++;
        }
        Nodo<T>* eliminado = ptr->getSiguiente();
        ptr->setSiguiente(eliminado->getSiguiente());
        delete eliminado;
        tamano--;
    }
}

template<class T>
void Lista<T>::mostrar()
{
    Nodo<T>* ptr = cabeza;
    for(int i =0 ; i<tamano ; i++)
    {
        std::cout << ptr->getDato() << ' ';
        ptr = ptr->getSiguiente();
    }
    std::cout << std::endl;
}

template<class T>
Lista<T>::~Lista()
{
    for(int i =0 ; i<tamano ; i++)
    {
        Nodo<T>* eliminado = cabeza;
        cabeza = cabeza->getSiguiente();
        delete eliminado;
    }
    std::cout << "Memoria liberada" << std::endl;
}

