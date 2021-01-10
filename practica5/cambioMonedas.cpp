	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 5: Algoritmos Greedy
		PROFESOR: Benjamín Luna Benoso
		FECHA: 8-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include<bits/stdc++.h>
using namespace std;

vector<int> devolverCambio(int cantidad, vector<int> monedas){
	int n = monedas.size();
	vector<int> cambio(n,0);
	for(int i=0; i<=n-1; i++){
		while(monedas[i] <= cantidad){
			cantidad = cantidad - monedas[i];
			cambio[i] = cambio[i] + 1;
		} 
	};
	return cambio;
}

int main(){
	int n, cambio;
	cout << "Ingrese la cantidad de monedas: ";
	cin >> n;
	vector<int> monedas(n);
	cout << " Ingrese las n monedas en orden decreciente: ";
	for(int i=0; i<n; i++){
		cin >> monedas[i];
	}
	cout << "Ingrese cantidad de cambio: ";
	cin >> cambio;

	vector<int> ans(n);
	ans = devolverCambio(cambio, monedas);
	cout << "Respuesta: ";
	for(int i=0; i<n; i++){
		cout << ans[i] << " ";
	} cout << endl;
	cout << "Cambio devuelto en monedas: ";
	for(int i=0; i<n; i++){
		if(ans[i] == 0) continue;
		cout << "$"<<monedas[i] << "x" << ans[i] << " + ";
	} cout << endl;

	return 0;
}