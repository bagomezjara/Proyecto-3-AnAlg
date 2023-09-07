#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int match=1,notmatch=1,gap=2;// se crean las variables match, notmatch y gap, de manera global, que representan los valores de los 3 posibles casos al comparar las secuencias
int matrix[50][50];// se define como variable global la matriz caudrada de tamaño 50

int reglasrec(int i, int j, string s1, string s2){// se crea una funcion entera llamada reglas que tiene todas las variables del main como parametros
    if(i==0&&j==0) return matrix[i][j]=0;// condicion if que se cumple cuando el valor de i y j es 0, en tal caso se retorna la matriz con el valor 0 en la casilla [i][j]
    if(matrix[i][j]>INT_MIN)  return matrix[i][j];// condicion if que se cumple cuando el valor de la casilla [i][j] es mayor a INT_MIN, en tal caso se retorna la el valor de la matriz en la casilla [i][j]
    if(i==0||j==0){// condicion if que se cumple cuando el valor de i o de j es 0
        if(i>0)return matrix[i][j]=reglasrec(i-1,j,s1,s2)-gap;// condicion if que se cumple si es que el valor de i es mayor a 0, en tal caso se retorna la casilla [i][j] de la matriz cuyo valor sera, la llamada recursiva a la funcion con i-1, menor el valor de gap
        if(j>0)return matrix[i][j]=reglasrec(i,j-1,s1,s2)-gap;// condicion if que se cumple si es que el valor de j es mayor a 0, en tal caso se retorna la casilla [i][j] de la matriz cuyo valor sera, la llamada recursiva a la funcion con j-1, menor el valor de gap
    }
    if(s1[i-1]==s2[j-1]){// condicion if que se cumple cuando el caracter del string s1 en la posicion [i-1] es igual al caracter del string s2 en la posicion [j-]
        int aux= max(reglasrec(i-1,j,s1,s2), reglasrec(i,j-1,s1,s2))-gap;// se crea una variable entera aux con valor igual al maximo entre la llamada recursiva de la funcion con parametro i-1 y llamada recursiva de la funcion con parametro j-1, eso menos el valor de gap
        int aux2=max(reglasrec(i-1,j-1,s1,s2)+match, aux);// se crea una variable entera aux2 con valor igual al maximo entre la llamada recursiva de la funcion con parametro i-1 y j-2, esto mas el valor de match y comparado con el valor de aux
        return matrix[i][j]=aux2;// se retorna el valor de la casilla [i][j] de la matriz con valor aux2
    }
    int aux= max(reglasrec(i-1,j,s1,s2), reglasrec(i,j-1,s1,s2))-gap;// se crea una variable entera aux con valor igual al maximo entre la llamada recursiva de la funcion con parametro i-1 y llamada recursiva de la funcion con parametro j-1, eso menos el valor de gap
    int aux2=max(reglasrec(i-1,j-1,s1,s2)-notmatch, aux);// se crea una variable entera aux2 con valor igual al maximo entre la llamada recursiva de la funcion con parametro i-1 y j-2, esto mas el valor de match y comparado con el valor de aux
    return matrix[i][j]=aux2;// se retorna el valor de la casilla [i][j] de la matriz con valor aux2

}
pair<string,string> optimo(int n, int m, string s1, string s2){// se crea la funcion optimo que retorna un pair de strings
    string a,b;// se crean 2 strings a y b
    stack<char> sa,sb;// se crean 2 stacks de strings sa y sb
    int i=n,j=m;// se crean las variables i y j, y se les asignan el valor de n y m respectivamente
    int s;// se crea la variable entera s
    while(i!=0 || j!=0){// se inicia un ciclo while que itera mientras i o j sean distintos de 0
        if(i==0){// condicion que se cumple si i es igual a 0
            sa.push('-');// se hace push del simbolo - en el stack sa
            sb.push(s2[j-1]);// se jace push del caracter en la posicion [j-1] del string s2
            j--;// se disminuye en 1 la variable j
        }
        else if(j==0){// en caso de no cumplirse la condicion anterior y cumplirse la condicion de que j sea igual a 0 se cumple que...
            sa.push(s1[i-1]);// se hace push del caracter en la posicion [i-1] del string s1 en el stack sa
            sb.push('-');// se hace push del caracter - en el stack sb
            i--;// se disminuye en 1 la variable i
        }else{// en caso de no cumplirse ninguna condicion anterior se hace...
            if(s1[i-1]==s2[j-1]){// condicion que se cumple si es que el caracter en la posicion [i-1] del string s1 es igual al caracter en la posicion [j-1] del string s2
                s=match;// s toma el valor de match
            }else{// si no se cumple la condicion anterior ocurre que...
                s=-notmatch;// s toma el valor negativo de notmatch
            }
            if(matrix[i][j]==matrix[i-1][j-1]+s){// conficion que se cumple si el valor de la casilla en [i][j] es igual a la casilla [i-1][j-1] mas s
                sa.push(s1[i-1]);// se hace push del caracter en la posicion [i-1] del string s1 en el stack sa
                sb.push(s2[j-1]);// se jace push del caracter en la posicion [j-1] del string s2
                i--;j--;// se disminuye en 1 las variables i y j
            }else if(matrix[i-1][j]>matrix[i][j-1]){// si no se cumple la condicion anterior y se cumple que el valor de la casilla en [i-1][j] es mayor que en [i][j-1] ocurre que...
                sa.push(s1[i-1]);// se hace push del caracter en la posicion [i-1] del string s1 en el stack sa
                sb.push('-');// se hace push del caracter - en el stack sb
                i--;// se disminuye en 1 la variable i
            }else{// en caso de no cumplirse ninguna condicion anterior ocurre que...
                sa.push('-');// se hace push del caracter - en el stack sa
                sb.push(s2[j-1]);// se jace push del caracter en la posicion [j-1] del string s2
                j--;// se disminuye en 1 la variable j
            }
        }
    }
    while (!sa.empty()){// se inicia un ciclo while que itera mientras el stack sa no este vacio
        a+=sa.top();// se anade el tope del stack sa al string a
        b+=sb.top();// se anade el tope del stack sb al string b
        sa.pop();// se hace pop al stack sa
        sb.pop();// se hace pop al stack sb
    }
    return make_pair(a,b);// se retorna el pair se string a y b
}
int main(){
    string s1,s2;// se crean 2 strings, s1 y s2
    getline(cin,s1);// se guarda la primera secuencia en el string s1
    getline(cin,s2);// se guarda la segunda secuencia en el string s2
    int n1=s1.size(),n2=s2.size();// se crean las variables n1 y n2 que tiene el valor del tamaño del string s1 y s2 respectivamente
    memset(matrix,-1,sizeof(matrix));// se llena la matriz de -1 usando memset
    for(int i=0;i<50;i++){// se inicia un ciclo for desde 0 hasta 49
            for(int j=0;j<50;j++){// se inicia un ciclo for desde 0 hasta 49
                    matrix[i][j]=INT_MIN;// se le asigna el valor de INT_MIN a la casilla en la posicion [i][j]
            }
    }
    cout<<"El mayor puntaje es: "<<reglasrec(n1,n2,s1,s2)<<endl;// se imprime por pantalla el puntaje maximo, llamando a la funcion reglasrec, con los parametros indicados
    pair<string,string> op=optimo(n1,n2,s1,s2);// se crea un pair de strings que es igual a la llamada de la funcion optimo con los parametros indicados
    cout<<op.first<<endl<<op.second<<endl;// se imprime el primer pair de la variable op, se hace un salto de linea y luego se imprime el segundo pair de la variable op
}
