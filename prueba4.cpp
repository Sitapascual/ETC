#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class nodo{
    public:
    int dato;
    nodo *izq, *der;
    int altura;
    nodo* crearNodo(int x);
    void insertar(int x);
    void insertarDos(nodo* &a, int x);
    void verArbol(nodo* arbol, int n);
    int alt(nodo* a);
};

class Arbol{
    private:
        nodo* raiz;
    public:
        nodo* getRaiz();        
        void insertarRaiz(nodo* &a);
        Arbol();
};

Arbol::Arbol(){
    raiz = NULL;
}

Arbol arbol = Arbol();   // creado raiz

nodo* nodo::crearNodo(int x){
    cout << "Creo el nodo" << endl;
    nodo *nuevoNodo = new(class nodo);
    nuevoNodo->dato = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    nuevoNodo -> altura = 0;

    return nuevoNodo;
}

nodo* Arbol::getRaiz(){
    return raiz;
}  

int nodo::alt(nodo* a){
    if(a == NULL){
        return -1;
    }
    else{
        return a -> altura;
    }
} 

void nodo::insertarDos(nodo* &a, int x){
     if(a==NULL){
        a = crearNodo(x);
     }
     else if(x < a->dato){
          insertarDos(a->izq, x);
          a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
          cout << a -> altura << endl;
     }
     else if(x > a->dato){
          insertarDos(a->der, x);
          a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
          cout << a -> altura << endl;
     }
     
}

void Arbol::insertarRaiz(nodo* &a){
    cout << "Asignado";
    raiz = a;
    
}

void nodo::insertar(int x){
    cout << "1" << endl;
    if(arbol.getRaiz() == NULL){

        nodo *nuevo = crearNodo(x);
        cout << "Insertado1: " << nuevo -> dato << endl;
        arbol.insertarRaiz(nuevo);
        cout << "Insertado2" << endl;
    }
    else if(x < arbol.getRaiz() -> dato){
          insertarDos(arbol.getRaiz() ->izq, x);
          arbol.getRaiz() -> altura = 1 + max(alt(arbol.getRaiz() -> izq), alt(arbol.getRaiz() -> der));
          cout << arbol.getRaiz() -> altura << endl;
          
     }
     else if(x > arbol.getRaiz() -> dato){
          insertarDos(arbol.getRaiz() -> der, x);
          arbol.getRaiz() -> altura = 1 + max(alt(arbol.getRaiz() -> izq), alt(arbol.getRaiz() -> der));
          cout << arbol.getRaiz() -> altura << endl;
     }
}

void buscarDos(nodo* &hoja, int min, int max){
    if(hoja != NULL){
        if(hoja -> dato == min || hoja -> dato == max){
            cout << hoja -> dato << endl;
            buscarDos(hoja ->izq, min, max);
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> dato > min && hoja -> dato < max){
            cout << hoja -> dato << endl;
            buscarDos(hoja ->izq, min, max);
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> dato < min){
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> dato > max){
            buscarDos(hoja ->izq, min, max);
        }
    }
}

/*
void buscar(int min, int max){
    if(arbol != NULL){
        if(arbol -> dato == min || arbol -> dato == max){
            cout << arbol -> dato << endl;
            buscarDos(arbol ->izq, min, max);
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> dato > min && arbol -> dato < max){
            cout << arbol -> dato << endl;
            buscarDos(arbol ->izq, min, max);
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> dato < min){
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> dato > max){
            buscarDos(arbol ->izq, min, max);
        }
    }
    else{
        cout << "Arbol vacio" << endl;
    }
}*/


void preOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->dato <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->dato << " ";
          enOrden(arbol->der);
     }
}

void postOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->dato << " ";
     }
}

void nodo::verArbol(nodo* arbol, int n){

     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->dato <<endl;
     verArbol(arbol->izq, n+1);
}





int main()
{
   

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    nodo* t = NULL; 

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        t -> insertar(x);
    }

    cout << "\n Mostrando ABB \n\n";
    t -> verArbol( arbol.getRaiz(), 0);
    int min = 9;
    int max = 12;

    cout << "BUSQUEDA" << endl;
    //buscar(min, max);
    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol.getRaiz());
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol.getRaiz());
    cout << "\n\n Post Orden :  ";   postOrden(arbol.getRaiz());

    cout << endl << endl;

    system("pause");
    return 0;
}

