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

int producto2(int m, int n){
	int r = 0;		//r será el resultado final 
	while(n > 0){	//mientras n sea mayor que 0
		if(n&1)		// si n es impar (ingresa cuando el bit menos significativo esté en 1)
			r = r+m;	//suma el valor de m a lo que ya tenga acumulado r
		m = 2*m;	//el valor de m se multiplica por 2
		n = n/2;	//el valor de n se divide entre 2
	}
	return r;
}

int main(){
	int m, n, r;
	cout << "Ingresa m: "; cin >> m;
	cout << "Ingresa n: "; cin >> n;

	r = producto2(m,n);
	cout << "R: " << r << endl;
	return 0;
}