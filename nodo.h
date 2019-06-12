#include <iostream>

template<class T>
class Nodo
{
	private:
    	T dato;
		Nodo<T>* sgt; 
	public:
		Nodo(T);

		void setSiguiente(Nodo<T>*);
		void setDato(T);
		
		Nodo<T>* getSiguiente();
		T getDato();
};

template<class T>
Nodo<T>::Nodo(T dato) :sgt(NULL)
{
    this->dato = dato;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* sig) {sgt = sig;}

template<class T>
void Nodo<T>::setDato(T dato) {this->dato = dato;}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {return sgt;}

template<class T>
T Nodo<T>::getDato() { return dato;}

