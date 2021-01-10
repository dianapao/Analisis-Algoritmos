	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 2: Funciones recursivas vs. iterativas.
		PROFESOR: Benjamín Luna Benoso
		FECHA: 28-10-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <iostream>
#include <stdio.h>

int div1(int n, int div, int *r){
	int q=0;
	while(n>=div){					//Se inicia el ciclo, que termina cuando el divisor llegue a ser menor que n
		n=n-div;		
		q++;						//Un contador que devolverá el cociente
	}
	*r=n;							
	return q;						//Se devuelve el cociente
}

int main(){
	int n,div,*r,i,res;
	std::cout<<"Ingrese n\n";		//Se pide el dato n
	std::cin>>n;
	std::cout<<"Ingrese div\n";		//Se pide el dato div
	std::cin>>div;
	std::cout<< "Ingrese r\n";		//Se pide el dato r
	std::cin>>i;

	r=&i;
	res=div1(n,div,r);				//Se manda a llamar a la función
	std::cout<<"El cociente es: "<<res<<std::endl; 	//Se imprime el resultado
	return 0;
}
	
