#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class nodo{
    private:
        nodo *izq, *der;
        int dato;
        int altura;
    public:
        
        
        
        nodo* crearNodo(int x);
        void insertar(int x);
        void insertarDos(nodo* &a, int x);
        void verArbol(nodo* arbol, int n);
        int alt(nodo* a);
        nodo* getNodoIzq();
        nodo* getNodoDer();
        int getDato();
        int getAltura();
        void buscar(int min, int max);
        void buscarDos(nodo* &hoja, int min, int max);
        void RSI(nodo* &a);
        void RSD(nodo* &a);
        
};

class Arbol{
    private:
        nodo* raiz;
    public:
        nodo* getRaiz();        
        void insertarRaiz(nodo* &a);
        Arbol();
        nodo* cambiarRaiz(nodo* &a);
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

nodo* Arbol::cambiarRaiz(nodo* &a){
    raiz = a;
}

nodo* nodo::getNodoIzq(){
    return izq;
}

nodo* nodo::getNodoDer(){
    return der;
}


int nodo::getDato(){
    return dato;
}

int nodo::alt(nodo* a){
    if(a == NULL){
        return -1;
    }
    else{
        return a -> altura;
    }
}

void nodo::RSI(nodo* &a){
    nodo *b = a -> getNodoIzq();
    a->izq = b -> getNodoDer();
    b -> der = a;
    a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
    b -> altura = 1 + max(alt(b -> izq), a -> altura);
    a = b;
}

void nodo::RSD(nodo* &a){
    nodo *b = a -> getNodoDer();
    a->der = b -> getNodoIzq();
    b -> izq = a;
    a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
    b -> altura = 1 + max(alt(b -> izq), a -> altura);
    a = b;
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
    //Subarbol izquierdo
    else if(x < arbol.getRaiz() -> dato){
          insertarDos(arbol.getRaiz() ->izq, x);
          if (alt(arbol.getRaiz() ->izq) - alt(arbol.getRaiz() ->der) > 1){
            if (x < arbol.getRaiz() ->izq -> dato){
                nodo *nuevo = arbol.getRaiz();
                RSI(nuevo);
                arbol.cambiarRaiz(nuevo);                
                cout << "RSI" << endl;
            }
            else{
                cout << "RDI" << endl;
                RSD(arbol.getRaiz() -> izq);
                nodo *nuevo = arbol.getRaiz();
                RSI(nuevo);
                arbol.cambiarRaiz(nuevo);     
            }
              
          }
          
          
          arbol.getRaiz() -> altura = 1 + max(alt(arbol.getRaiz() -> izq), alt(arbol.getRaiz() -> der));
          cout << arbol.getRaiz() -> altura << endl;
          
     }
     //Subarbol derecho
     else if(x > arbol.getRaiz() -> dato){
        insertarDos(arbol.getRaiz() -> der, x);
        if (alt(arbol.getRaiz() ->der) - alt(arbol.getRaiz() ->izq) > 1){
            if (x > arbol.getRaiz() ->der -> dato){
                nodo *nuevo = arbol.getRaiz();
                RSD(nuevo);
                arbol.cambiarRaiz(nuevo); 
                cout << "RSD" << endl;
            }
            else{
                cout << "RDD" << endl;
                //
            }
        }
        else{
            arbol.getRaiz() -> altura = 1 + max(alt(arbol.getRaiz() -> izq), alt(arbol.getRaiz() -> der));
            cout << arbol.getRaiz() -> altura << endl;
        }
          
     }
}

void nodo::buscarDos(nodo* &hoja, int min, int max){
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


void nodo::buscar(int min, int max){
    if(arbol.getRaiz() != NULL){
        if(arbol.getRaiz() -> dato == min || arbol.getRaiz() -> dato == max){
            cout << arbol.getRaiz() -> dato << endl;
            buscarDos(arbol.getRaiz() ->izq, min, max);
            buscarDos(arbol.getRaiz() ->der, min, max);
        }
        else if(arbol.getRaiz() -> dato > min && arbol.getRaiz() -> dato < max){
            cout << arbol.getRaiz() -> dato << endl;
            buscarDos(arbol.getRaiz() ->izq, min, max);
            buscarDos(arbol.getRaiz() ->der, min, max);
        }
        else if(arbol.getRaiz() -> dato < min){
            buscarDos(arbol.getRaiz() ->der, min, max);
        }
        else if(arbol.getRaiz() -> dato > max){
            buscarDos(arbol.getRaiz() ->izq, min, max);
        }
    }
    else{
        cout << "Arbol vacio" << endl;
    }
}


void preOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->getDato() <<" ";
          preOrden(arbol->getNodoIzq());
          preOrden(arbol->getNodoDer());
     }
}

void enOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->getNodoIzq());
          cout << arbol->getDato() << " ";
          enOrden(arbol->getNodoDer());
     }
}

void postOrden(nodo* arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->getNodoIzq());
          postOrden(arbol->getNodoDer());
          cout << arbol->getDato() << " ";
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
    int min = 8;
    int max = 12;

    cout << "BUSQUEDA" << endl;
    t -> buscar(min, max);
    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol.getRaiz());
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol.getRaiz());
    cout << "\n\n Post Orden :  ";   postOrden(arbol.getRaiz());

    cout << endl << endl;

    system("pause");
    return 0;
}

