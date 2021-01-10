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
/*Ejemplo: 
fibo(6) = fibo(5) + fibo(4) = 5 + 3 = 8
fibo(5) = fibo(4) + fubo(3) = 3 + 2 = 5
fibo(4) = fibo(3) + fibo(2) = 2 + 1 = 3
fibo(3) = fibo(2) + fibo(1) = 1 + 1 = 2
fibo(2) = fibo(1) + fibo(0) = 1 + 0 = 1 ^    */
int fiboRecursivo(int n){	//va a calcular hasta el n-esimo término de la sucesión
	int x=0, y=1;
	if(n<=1) 	//si llega a los límites 1 regresa 1 y si llega a 0 regresa 0
		return n;
	else
		return fiboRecursivo(n-1)+fiboRecursivo(n-2); //suma los 2 números anteriores correspondientes
}

int main(){
	int n, cont=1;
	cout << "Digitos a ver: ";
	cin >> n;		//ingresa el total de términos en la sucesión fibonaci
	cout << "0 - ";	//a parte del 0
	for(int i=1; i<=n; i++){	//llama a la función n veces para poder mostrar el número que le corresponde
		cout << fiboRecursivo(i) << " - ";
	}
	cout << endl;
	return 0;
}