	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Algoritmo de Euclides para M.c.d.
		PROFESOR: Benjamín Luna Benoso
		FECHA: 20-10-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <iostream>

int main(){
	int n, m, constante, mod1, mod=1, nCopia, mCopia;
 
  	std::cout<<"Ingrese el valor de m\n";
  	std::cin>>m;
	std::cout<<"Ingrese el valor de n\n";
	std::cin>>n;
	
	nCopia=n;
	mCopia=m;
   	
	while(n!=0){
  		mod=m % n;
  		m=n; 					//n=m*division+mod
  		n=mod;	
  	}

  printf("El maximo comin divisor de %d y %d es %d",mCopia, nCopia, m);
	return 1;
}
