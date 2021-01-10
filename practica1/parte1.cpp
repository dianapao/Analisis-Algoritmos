/*
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		ESTRUCTURAS DE DATOS
		GRUPO: 3CV1
		ALUMNOS: 
		- De la Cruz Sierra Diana Paola
		- Raya Chavez Samuel Antonio
		TITULO: Practica 1: Determinacion experimental de la complejidad temporal de un algoritmo.
		PROFESOR: Benjamín Luna Benoso
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		FECHA: 20-10-2020
	*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Suma(vector<int> A, vector<int> B, int r){		//parametros: vector A,B y su tamaño r
	bool HayCarry = false;			//variable booleana para indicar si hay un acarreo o no. Inicia en false por que no hay.
	vector<int> C(r);
	for(int i=r-1; i>=0; i--){		//leeremos todos los digitos de ambos vectores
		if(HayCarry){				//En caso de haber acarreo
			if(A[i] == 0){			
				if(B[i] == 0){		
					C[i] = 1; 
					HayCarry = false;	// Como A[i]=0 y en B tambien, sumamos unicamente el 1 que se acarrea e indicamos que el acarreo termina
				}
				else C[i]=0;		//si B[i]=1 + 1 de acarreo se suman (resultado=0) y por ende sigue existiendo acarreo
			}else{
				if(B[i] == 0) C[i]=0;	
				else C[i]=1;		//Aquí es porque A[i]=1 + 1 de acarreo se suman y por ende sigue existiendo acarreo
			}
		}else{						//En caso de no haber acarreo
			if(A[i] == 0){
				if(B[i] == 0) C[i]=0;   	//0 + 0 = 0
				else C[i]=1;				//0 + 1 = 0
			}else{
				if(B[i] == 0) C[i]=1;		//1 + 0 = 1
				else{
					C[i] = 0;				//1 + 1 = 0
					HayCarry = true;		//indicamos que se tiene un acarreo
				}
			}
		}
	}
	if(HayCarry) C.insert(C.begin(), 1);	//si al terminar de sumar todos los digitos aun existe acarreo se inserta 1 al inicio del vector C
	return C;
}


int main(){
	int r;
	cout << "Ingrese r: "; cin >> r;		//pedimos r para el tamaño de ambos arreglos
	vector<int> A(r), B(r), C;
	cout << "Ingrese A en binario separando cada digito por espacios: ";
	for(int i=0; i<r; i++)
		cin >> A[i];
	cout << "Ingrese B en binario separando cada digito por espacios: ";		//pedimos ambos arreglos A y B
	for(int i=0; i<r; i++)
		cin >> B[i];

	C = Suma(A, B, r);		//en el vector C se almacena el resultado del llamado a la funcion Suma

	cout << "C: ";			//Imprimimos el resultado de C
	for(int i=0; i<C.size(); i++)
		cout << C[i] << " ";

	return 0;
}