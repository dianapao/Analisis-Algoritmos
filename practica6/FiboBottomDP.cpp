	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 6: Algoritmos Greedy.Programación dinámica
		PROFESOR: Benjamín Luna Benoso
		FECHA: 16-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;

int calcFibo(int n, vector<int> &fibo){
	if(n <= 1){
		return 1;
	}else{
		fibo[0] = 0;
		fibo[1] = 1;
		for(int i=2; i<=n; i++){
			fibo[i] = fibo[i-1] + fibo[i-2];
		}
		return fibo[n];
	}
}

int main(){
	int n;
	cout << "Posicion de fibonacci: "; 
	cin >> n;
	vector<int> fibo(n,0);

	int ans = calcFibo(n-1, fibo);
	cout <<endl<< "fibo = " << ans << endl;
	return 0;
}