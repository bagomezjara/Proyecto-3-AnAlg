#include <bits/stdc++.h>

using namespace std;

class grafo{// se crea la clase grafo
    int nVertices;// se define en la clase una variable entera nVertices
    list<int> *l;// se define en la lista un arreglo de listas de enteros l
    set<pair<int,int>> aristas;// se define en la clase un set de pares de enteros llamado aristas
    set<int> nodos;// se define en la clase un set de enteros llamados nodos
public:// se definen como variables publicas:
       grafo(int n){// se define el constructor de grafo con parametros enteros
            this->nVertices=n;// se define el valor de nVertices como n
            l=new list<int>[n];// se define l como un nuevo arreglo de listas de enteros de tamaño n

       }
       void agregarArista(int x, int y){// funcion void agregarAristas que recibe como parametros dos enteros, x e y respectivamente
            l[x].push_back(y);// se guarda en la posicion x de la lista de enteros l el valor de y
            l[y].push_back(x);// se guarda en la posicion y de la lista de enteros l el valor de x
            aristas.insert(make_pair(x,y));// se inserta en aristas el par de enteros x e y
            nodos.insert(x);// se inserta x en el set nodos
            nodos.insert(y);// se inserta y en el set nodos
       }
       set<pair<int,int>>getAristas(){// funcion getAtistas que retorna un set de par de enteros
           return aristas;// se retorna el set de par de enteros aristas
       }
       set<int> getNodos(){// funcion getNodos que retorna un set de enteros
           return nodos;// se retorna el set de enteros nodos
       }
       list<int> * getAdjList(){// funcion getAdjList que retorna un arreglo de listas de enteros
           return l;// se retorna el arreglo de listas de enteros
       }
};
void vertexCover(grafo g){// funcion void vertexCover que recibe como parametros una estructura de tipo grafo
     set<pair<int,int>> auxaristas=g.getAristas();// se crea el set de pares de enteros auxaristas y se le da el valor del resultado de la funcion getAristas del grafo g
     list<int> *l=g.getAdjList();// se crea un arreglo de listas de enteros y se le da el valor del resultado de la funcion getAdjList del grafo g
     set<pair<int,int>> aristas=g.getAristas();// se crea el set de pares de enteros aristas y se le da el valor del resultado de la funcion getAristas del grafo g
     set<int> vertices=g.getNodos();// se crea un set de enteros vertices y se le da el valor del resultado de la funcion getNodos del grafo g
     set<int> resultado;// se crea un set de enteros resultado
     for(auto const &it:auxaristas){// se inicia un ciclo for que recorre todo auxaristas
         pair<int,int> p=it;// se crea un par de enteros p y se le da el valor del iterados de auxaristas
         if(vertices.find(p.first)==vertices.end()||vertices.find(p.second)==vertices.end()){// condicion if que se cumple si el vertice ya es tomado en las aristas , se salta la iteracion actual
             continue;
         }
         vertices.erase(p.first);// se elimina el primer valor del pair p del set vertices
         vertices.erase(p.second);// se elimina el segundo valor del pair p del set vertices
         resultado.insert(p.first);// se inserta el primer valor del pair p al set resultado
         resultado.insert(p.second);// se inserta el segundo valor del pair p al set resultado
         for(int aux:l[p.first]){// se inicia un ciclo for que itera por la lista de la posicion del primer valor del pair p
             if(aristas.find(make_pair(p.first,aux))!=aristas.end()||aristas.find(make_pair(aux,p.first))!=aristas.end()){// condicion if que se cumple en el caso de que el par compuesto por el primer valor del par p y el iterador aux, o viceversa, este en el set de pares de enteros aristas
                 aristas.erase(make_pair(p.first,aux));// se elimina el par ,compuesto por el primer valor del par p y el iterador aux, del set de pares de enteros aristas
                 aristas.erase(make_pair(aux,p.first));// se elimina el par ,compuesto por el iterador aux y el primer valor del par p , del set de pares de enteros aristas
             }
         }

     }
     for(auto const &it : resultado){// se inicia un ciclo for que itera por el set de entero resultado
         cout<<"respuesta"<<it<< "   ";// se imprime el iterador it
     }
}
main(){
     int n,x,y;// se crean las variables enteras n, x e y
     cout<<"ingrese el numero de nodos del grafo"<<endl;// mensaje de entrada
     cin>>n;// se guarda la entrada en la variable n
     grafo g(n);// se crea el grafo con parametro inicia n
     while(1){// se inicia un ciclo while que itera indefinidamente
         cout<<"ingrese una arista o ingrese 0 0 para terminar la creacion del grafo"<<endl;// mensaje de entrada de las aristas
         cin>>x>>y;// se guarda el primer valor de entrada en la variable x y luego el segundo valor de entrada en y
         if(x==0&&y==0) break;// condicion que se cumple en el caso de que ambas variables x e y sean 0, en tal caso se rompe el ciclo while
         g.agregarArista(x,y);// se llama a la funcion agregarAristas del grafo g, con parametros iniciales x e y respectivamente
     }

     vertexCover(g);// se llama a la funcion vertexCover con parametro inicial, el grafo g
}

