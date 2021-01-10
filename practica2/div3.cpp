	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLIT�CNICO NACIONAL
		ESCUELA SUPERIOR DE C�PUTO
		An�isis de Algoritmos
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
using namespace std;

int div3(int n, int div){
	if(div>n){									//Condicional, si div es mayor que n se retorna 0
		return 0;
	}else{										//De lo contrario, se regresara 1+ la llamada a la misma funci�n con n=n-div, y div=div
		return 1+div3(n-div,div);				
	}
}

int main(){
	int n, div, res;
	cout<<"Ingrese n\n";						//Se pide n
	cin>>n;
	cout<<"Ingrese div\n";						//Se pide div
	cin>>div;
	res=div3(n,div);							//Se manda a  llamar a la funci�n 
	cout<<"El cociente es: "<<res<<endl;		//Se imprime el cociente
	return 0;
}
