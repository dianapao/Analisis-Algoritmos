	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 7: Programación dinámica
		PROFESOR: Benjamín Luna Benoso
		FECHA: 23-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;

/*1 flecha de lado
  2.- ^ flecha para arriba
  3.- <- flecha acostada */

void printLCS(vector<vector<int>> b, string X, int i, int j, int &length){	//Imprime la LCS
	if(i==0 || j==0) 	//si alguna de las cadenas no tiene caracteres
		return;
	if(b[i][j] == 1){	//flecha inclinada 
		printLCS(b,X,i-1,j-1, length);
		cout << X[i-1];
		length++;	//aumentamos esta variable para obtener la longitud de LCS
	}else if(b[i][j] == 2){		//flecha hacia arriba
		printLCS(b,X,i-1,j, length);
	}else{			//flecha horizontal
		printLCS(b,X,i,j-1, length);
	}
}

int LCSLength(string X, string Y){	//funcion para llenar las tablas C y b
	int m = X.size();
	int n = Y.size();
	int length = 0;
	vector<vector<int>> b(m+1);
	vector<vector<int>> c(m+1);

	b[0].resize(n+1);	
	c[0].resize(n+1);
	
	for(int i=1; i<=m; i++){
		b[i].resize(n+1), c[i].resize(n+1);		//asignamos tamaño n+1 a cada columna
		c[i][0] = 0, b[i][0] = 0;
	}

	for(int j=0; j<=n; j++){
		c[0][j] = 0, b[0][j] = 0;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(X[i-1] == Y[j-1]){	//si los caracteres son iguales
				c[i][j] = c[i-1][j-1] + 1;	//sumamos 1 en la posicion actual al vecino superior izquierdo
				b[i][j] = 1;		//indicamos flecha inclinada
			}else if(c[i-1][j] >= c[i][j-1]){	//si el vecino superior es >=
				c[i][j] = c[i-1][j];
				b[i][j] = 2;	//indicamos flecha hacia arriba
			}else{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;	//indicamos flecha horizontal 
			}
		}
	}

	cout << "LCS: ";
	printLCS(b,X,m,n, length);
	cout << endl << endl;
	return length;
}


int main(){
	string original="", prueba="", nameFile1, nameFile2;
	char c;
	cout << "Nombre del archivo original: "; cin >> nameFile1;
	cout << "Nombre del archivo prueba: "; cin >> nameFile2;
	nameFile1 += ".txt";
	nameFile2 += ".txt";

	ifstream ifs(nameFile1);
	if (!ifs.is_open()) {		//Si no se puede abrir el archivo de texto
    	cout << "No se puede encontrar el archivo original :c" << endl;
	}else{
		while(ifs >> c)	//mientras lea un caracter
			original += c;	//concatena el caracter a la cadena original
	}

	ifstream ifs2(nameFile2);// si no se puede abrir el archivo de texto para el archivo prueba
	if (!ifs2.is_open()) {
    	cout << "No se puede encontrar el archivo prueba :c" << endl;
	}else{
		while(ifs2 >> c)	//mientras lea un caracter
			prueba += c;
	}cout << endl;

	int length = LCSLength(original, prueba);
	double similar = (100*(double)length)/(double)original.size();
	cout << "similar: " << fixed << setprecision(2) << similar << "%" << endl;	//imprime solamente 2 decimales

	return 0;
}