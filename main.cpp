//codigo guiado de https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/

#include "lista.h"

int main()
{
    Lista<int> lista1;
    lista1.agregar_f(0);
    lista1.agregar_f(5);
    lista1.agregar_f(2);
    lista1.agregar_f(8);
    lista1.agregar_d(4,1);
    lista1.remove(2);
    lista1.mostrar();

}
