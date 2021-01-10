	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓPUTO
		Anáisis de Algoritmos
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
using namespace std;

int div3(int n, int div){
	if(div>n){									//Condicional, si div es mayor que n se retorna 0
		return 0;
	}else{										//De lo contrario, se regresara 1+ la llamada a la misma función con n=n-div, y div=div
		return 1+div3(n-div,div);				
	}
}

int main(){
	int n, div, res;
	cout<<"Ingrese n\n";						//Se pide n
	cin>>n;
	cout<<"Ingrese div\n";						//Se pide div
	cin>>div;
	res=div3(n,div);							//Se manda a  llamar a la función 
	cout<<"El cociente es: "<<res<<endl;		//Se imprime el cociente
	return 0;
}
