	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 3: Complejidades temporales polinomiales y no polinomiales.
		PROFESOR: Benjamín Luna Benoso
		FECHA: 06-11-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;

void fiboLineal(int n){
	int x=0, y=1, z;
	for(int i=1; i<=n; i++){
		z = x+y;	//este es el resultado a mostrar y es el valor de x + y (osea los 2 anteriores)
		x = y;		//ahora x toma un valor despues del que tenia (valor de y)
		y = z;		//igualmente y avanza un numero mas en la sucesión (ahora vale z )
		cout << z << " - ";
	}
}

int main(){
	int n;
	cout << "Digitos a ver: ";	// ingre el total de términos a ver de la suceción fibonacci
	cin >> n;
	cout << "0 - ";	 //a parte del 0
	fiboLineal(n);		//con una sola llamada imprime todos
	cout << endl;
	return 0;
}