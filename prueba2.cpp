#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


struct nodo{
     int nro;
     struct nodo *izq, *der;
     int altura;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB arbol = NULL;   // creado Arbol

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     nuevoNodo -> altura = 0;

     return nuevoNodo;
}

int alt(ABB a){
    if(a == NULL){
        return -1;
    }
    else{
        return a -> altura;
    }
} 

void insertarDos(ABB &a, int x)
{
     if(a==NULL)
     {
           a = crearNodo(x);
     }
     else if(x < a->nro){
          insertarDos(a->izq, x);
          a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
          cout << a -> altura << endl;
     }
     else if(x > a->nro){
          insertarDos(a->der, x);
          a -> altura = 1 + max(alt(a -> izq), alt(a -> der));
          cout << a -> altura << endl;
     }
}


void insertar(int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro){
          insertarDos(arbol->izq, x);
          arbol -> altura = 1 + max(alt(arbol -> izq), alt(arbol -> der));
          cout << arbol -> altura << endl;
     }
     else if(x > arbol->nro){
          insertarDos(arbol->der, x);
          arbol -> altura = 1 + max(alt(arbol -> izq), alt(arbol -> der));
          cout << arbol -> altura << endl;
     }
}

void buscarDos(ABB &hoja, int min, int max){
    if(hoja != NULL){
        if(hoja -> nro == min || hoja -> nro == max){
            cout << hoja -> nro << endl;
            buscarDos(hoja ->izq, min, max);
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> nro > min && hoja -> nro < max){
            cout << hoja -> nro << endl;
            buscarDos(hoja ->izq, min, max);
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> nro < min){
            buscarDos(hoja ->der, min, max);
        }
        else if(hoja -> nro > max){
            buscarDos(hoja ->izq, min, max);
        }
    }
}

void buscar(int min, int max){
    if(arbol != NULL){
        if(arbol -> nro == min || arbol -> nro == max){
            cout << arbol -> nro << endl;
            buscarDos(arbol ->izq, min, max);
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> nro > min && arbol -> nro < max){
            cout << arbol -> nro << endl;
            buscarDos(arbol ->izq, min, max);
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> nro < min){
            buscarDos(arbol ->der, min, max);
        }
        else if(arbol -> nro > max){
            buscarDos(arbol ->izq, min, max);
        }
    }
    else{
        cout << "Arbol vacio" << endl;
    }
}


void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;
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

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar(x);
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);
    int min = 9;
    int max = 12;

    cout << "BUSQUEDA" << endl;
    buscar(min, max);
    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
}