/*
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		ESTRUCTURAS DE DATOS
		GRUPO: 3CV1
		ALUMNOS: 
		- De la Cruz Sierra Diana Paola
		- Raya Chavez Samuel Antonio
		TITULO: Practica 2: Funciones recursivas vs iterativas
		PROFESOR: Benjamín Luna Benoso
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		FECHA: 24-10-2020
	*/
#include<bits/stdc++.h>
using namespace std;
int producto3(int a, int b){	
	if(b == 1)		//si b vale 1, regresa el valor de a (equivalente a multiplicar por 1)
		return a;
	else			// si no al valor de a se irá sumando prod3(a, b-1), luego b-2 y asi sucesivamente hasta llegar a b=1
		return a + producto3(a, b-1);
}

int main(){
	int a, b, r;
	cout << "Ingresa a: "; cin >> a;
	cout << "Ingresa b: "; cin >> b;

	r = producto3(a,b);
	cout << "R: " << r << endl;
	return 0;
}