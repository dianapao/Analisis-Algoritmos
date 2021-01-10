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
using namespace std;
int div2(int n, int div, int *r){
	int dd=div;
	int q=0;
	*r=n;
	while(dd<=n){							//Un ciclo que har� que dd sea mayor a n
		dd=2*dd;							//Se duplica el termino dd
	}
	while(dd>div){							//Ahora un ciclo que se detendr� cuando el valor modificado dd sea menor/igual a div
		dd=dd/2;							//Se divide sobre 2 el t�rmino dd
		q=2*q;								//Se duplica el t�rmino q(Contador del cociente)
		if(dd<=*r){
			*r=*r-dd;
			q++;							//Se incrementa el valor del cociente
		}
	}
	return q;								//Se regresa el cociente
}

int main(){
	int n, div, *r, i, res;
	cout<<"Ingrese n\n";					//Se pide el dato n
	cin>>n;
	cout<<"Ingrese div\n";					//Se pide el dato div
	cin>>div;
	cout<<"Ingrese r\n";					//Se pide el dato r
	cin>>i;
	
	r=&i;
	res=div2(n,div,r);						//Se manda a llamar a la funci�n
 	cout<<"El cociente es: "<<res<<endl;	//Se imprime el cociente de la divisi�n
	return 0;
}

