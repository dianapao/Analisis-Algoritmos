	/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
		INSTITUTO POLITÉCNICO NACIONAL
		ESCUELA SUPERIOR DE CÓMPUTO
		Análisis de Algoritmos
		GRUPO: 3CV1
		ALUMNOS:
		- De la Cruz Sierra Diana Paola
		- Raya Chávez Samuel Antonio
		TITULO: Práctica 7: Programación dinámica
		PROFESOR: Benjamín Luna Benoso
		FECHA: 23-12-2020
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	*/
#include <iostream>
using namespace std;


void resultado(int n,int I[][25],int Ie){	//impresion del resultado 
	int i,j;
	i=Ie;
	cout<<"Linea "<<i<<", estacion "<<n<<"\n";
	j=n;
	while(j>=2){
		i=I[i][j];
		cout<<"Linea "<<i<<", estacion "<<j-1<<"\n";
		j=j-1;
	}
}


void proceso(int e[],int x[],int a[][25],int t[][24],int n){	//calculo de la funcion con programación dinámmica
	int f[3][30], fe;
	int I[3][25], Ie;
	int j;

	f[1][1]=e[1]+a[1][1];
	f[2][1]=e[2]+a[2][1];
	for (j=2;j<=n;j++){
		if((f[1][j-1]+a[1][j])<=(f[2][j-1]+t[2][j-1]+a[1][j])){
			f[1][j]=f[1][j-1]+a[1][j];
			I[1][j]=1;
		}else{
			f[1][j]=f[2][j-1]+t[2][j-1]+a[1][j];
			I[1][j]=2;
		}

		if((f[2][j-1]+a[2][j])<=(f[1][j-1]+t[1][j-1]+a[2][j])){
			f[2][j]=f[2][j-1]+a[2][j];
			I[2][j]=2;
		}else{
			f[2][j]=f[1][j-1]+t[1][j-1]+a[2][j];
			I[2][j]=1;
		}
	}

	if((f[1][n]+x[1])<=(f[2][n]+x[2])){
		fe=f[1][n]+x[1];
		Ie=1;
	}else{
		fe=f[2][n]+x[2];
		Ie=2;
	}
	resultado(n,I,Ie);
	cout<<"\nCon un tiempo igual a: "<<fe;
}

void peticiones(){	//ingreso de los datos por consola
	int i,j,estaciones,aux,aux1,a[3][25], t[3][24],e[3], x[3];

	cout<<"Ingrese el numero de estaciones de trabajo\n";
	cin>>estaciones;

	cout<<"Ingrese el tiempo de entrada de la linea 1\n";			cin>>e[1];
	cout<<"Ingrese el tiempo de entrada de la linea 2\n";			cin>>e[2];
	cout<<"Ingrese el tiempo de salida de la linea 1\n";			cin>>x[1];
	cout<<"Ingrese el tiempo de salida de la linea 2\n";			cin>>x[2];

	//Fabrica *fabrica = crearFabrica(estaciones);
	aux=estaciones;
	i=1;
	while(aux>0){
		cout<<"Ingrese el tiempo del la estacion de trabajo "<<i<<" de la linea 1\n";		cin>>a[1][i];
		aux--;
		i=i+1;
	}

	aux1=estaciones;
	j=1;
	while(aux1>0){
		cout<<"Ingrese el tiempo del la estacion de trabajo "<<j<<" de la linea 2\n";		cin>>a[2][j];
		aux1--;
		j=j+1;
	}

/*--------------------------Nodo interno 1-------------------------------------*/
	aux=estaciones;
	i=1;
	while(aux>1){
		cout<<"Ingrese el tiempo del nodo interno "<<i<<" de la fila 1\n";		cin>>t[1][i];
		aux--;
		i+=1;
	}

/*--------------------------Nodo interno 2-------------------------------------*/
	aux1=estaciones;
	j=1;
	while(aux1>1){
		cout<<"Ingrese el tiempo del nodo interno "<<j<<" de la fila 2\n";		cin>>t[2][j];
		aux1--;
		j+=1;
	}	

	proceso(e,x,a,t,estaciones);
}


int main(){
	peticiones();	//llamada a la función 
	return 1;
}