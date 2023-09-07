#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int match=1,notmatch=1,gap=2;// se crean las variables match, notmatch y gap, de manera global, que representan los valores de los 3 posibles casos al comparar las secuencias
int matrix[50][50];// se define como variable global la matriz caudrada de tamaño 50

int reglas(int n, int m, string s1, string s2){// se crea una funcion entera llamada reglas que tiene todas las variables del main como parametros
    int s;// se crea la variable entera s
    for(int i=0;i<n;i++){// se inicia un ciclo for que itera desde 0 hasta n
            matrix[i][0]=matrix[0][i]=-i*gap;// se le asigna el valor de i*gap a todas las casillas de los bordes de la matriz
    }
    for(int i=1;i<=n;i++){// se inicia un ciclo for que itera desde 1 hasta n
        for(int j=1;j<=m;j++){// se inicia un ciclo for que itera desde 1 hasta m
            if(s1[i-1]==s2[j-1]){// condicion que se cumple en el caso de que el string s1 en su posicion [i-1] tenga el mismo caracter que el string s2 en la posicion [j-1]
                s=match;// s sera igual al valor de match
            }else{// en caso de no cumplir la condicion anterior
                s=-notmatch;// s  toma el valor negativo de notmatch
            }
            matrix[i][j]=max(matrix[i-1][j-1]+s,max(matrix[i-1][j]-gap,matrix[i][j-1]-gap));// la casilla de la matriz en la posicion [i][j] tomara el valor maximo entre la casilla izquierda-arriba mas s, o el maximo entre las casillas vecina menos el valor de gap
        }
    }
    return matrix[n][m];// se retorna el valor de la casilla en la posicion [i][j] de la matriz
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
    cout<<"El mayor puntaje es: "<<reglas(n1,n2,s1,s2)<<endl;// se imprime por pantalla el puntaje maximo, llamando a la funcion reglas, con los parametros indicados
    pair<string,string> op=optimo(n1,n2,s1,s2);// se crea un pair de strings que es igual a la llamada de la funcion optimo con los parametros indicados
    cout<<op.first<<endl<<op.second<<endl;// se imprime el primer pair de la variable op, se hace un salto de linea y luego se imprime el segundo pair de la variable op
}
