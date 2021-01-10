	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 6: Algoritmos Dinámicos
		PROFESOR: Benjamín Luna Benoso
		FECHA: 18/12/2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/


#include <iostream>
using namespace std ;

void prueba(int peso[], int beneficio[], int j, int c, int g[][50]){
	if(j>0){
		if(c<peso[j])
			prueba(peso, beneficio, j-1,c, g);
		else{
			if((g[j-1][c-peso[j]]+beneficio[j])>g[j-1][c]){
				//cout<<"\n((g[j-1][c-peso[j]]+beneficio[j])>g[j-1][c]) ";cout<<g[j-1][c-peso[j]]+beneficio[j]<<">"<<g[j-1][c];
				prueba(peso, beneficio, j-1, c-peso[j], g);
				cout<<"\nGuardar objeto "<<j<<"\n";
			}else
				//cout<<"\n((g[j-1][c-peso[j]]+beneficio[j])<=g[j-1][c]) ";cout<<(g[j-1][c-peso[j]]+beneficio[j])<<"<="<<g[j-1][c];
				prueba(peso, beneficio,j-1,c, g);
		}
	}
}

void mochila(int peso[], int beneficio[], int pesoM, int cosas){
	int c,j,g[50][50];

	for(c=0; c<=pesoM; c++)
		g[0][c]=0;
	for(j=1; j<=cosas; j++)
		g[j][0]=0;
	cout<<"\n";
	for(j=1; j<=cosas; j++){
		for(c=1; c<=pesoM; c++){
			if(c<peso[j])
				g[j][c]=g[j-1][c];
			else{
				if(g[j-1][c]>=g[j-1][c-peso[j]]+beneficio[j])
					g[j][c]=g[j-1][c];
				else
					g[j][c]=(g[j-1][c-peso[j]]+beneficio[j]);
			}
		}
	}

	j=j-1;
	c=c-1;
	prueba(peso, beneficio, j, c, g);
}


void peticiones(){
	int peso[50], beneficio[50], peso_Mochila, cosas, peso_objeto, beneficio_objeto, i=1, aux;
	cout<<"Ingrese el peso de la mochila\n";
	cin>>peso_Mochila;
	cout<<"Ingrese el numero de objetos a tomar en cuenta\n";
	cin>>cosas;
	aux=cosas;
	while(aux>0){
		cout<<"Ingrese el peso del objeto "<<i<<": ";		cin>>peso_objeto;
		cout<<"Ingrese el beneficio del objeto "<<i<<": ";	cin>>beneficio_objeto;	
		peso[i]=peso_objeto;
		beneficio[i]=beneficio_objeto;		
		aux--;
		i=i+1;
	}
	mochila(peso, beneficio, peso_Mochila, cosas);
}

int main(){
	peticiones();
	return 0;
}
