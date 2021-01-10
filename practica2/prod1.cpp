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
int producto1(int m, int n){
	int r = 0;		//r será el resultado final
	while(n > 0){	//mientras n sea mayor que r
		r = r+m;	// ve sumando el valor que tenga m al acumulado que ya tenga r
		n--;
	}
	return r;
}

int main(){
	int m, n, r;		//declaración y lectura de m y n
	cout << "Ingresa m: "; cin >> m;
	cout << "Ingresa n: "; cin >> n;

	r = producto1(m,n);		//llamado a la función para calcular el producto
	cout << "R: " << r << endl;
	return 0;
}