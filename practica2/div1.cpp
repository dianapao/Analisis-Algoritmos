	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLIT�CNICO NACIONAL
		ESCUELA SUPERIOR DE C�MPUTO
		An�lisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Ch�vez Samuel Antonio
		TITULO: Pr�ctica 2: Funciones recursivas vs. iterativas.
		PROFESOR: Benjam�n Luna Benoso
		FECHA: 28-10-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/

#include <iostream>
#include <stdio.h>

int div1(int n, int div, int *r){
	int q=0;
	while(n>=div){					//Se inicia el ciclo, que termina cuando el divisor llegue a ser menor que n
		n=n-div;		
		q++;						//Un contador que devolver� el cociente
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
	res=div1(n,div,r);				//Se manda a llamar a la funci�n
	std::cout<<"El cociente es: "<<res<<std::endl; 	//Se imprime el resultado
	return 0;
}
	
