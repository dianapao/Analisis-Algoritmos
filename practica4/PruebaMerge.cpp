#include <bits/stdc++.h>
using namespace std;

void Merge(int *A, int p, int q, int r) { 
	int n1=q-p+1; 
	int n2=r-q; 
	int L[n1],R[n2];
	cout << "\t n1="<< n1 <<" ,n2=" << n2 << endl;  
	int i,j,k;
	for (i=0;i<n1;i++){ 
		L[i]= A[p+i]; 
	}
	cout << "\t L = [ ";
	for (i=0;i<n1;i++){ 
		cout << L[i] << "  ";
	}cout << "]" << endl;
	for (j=0;j<n2;j++){
		R[j]= A[q+1+j]; 
	}
	cout << "\t R: [ ";
	for (j=0;j<n2;j++){
		cout << R[j] << "  ";
	} cout << "]" << endl;
	i=0;	
	j=0;
	cout << "\t i="<< i <<" , j=" << j << endl << " \t FOR: " << endl;
	for(k=p;k<r;k++){
		cout << "\t \t k="<< k << endl;
		if(L[i]<=R[j]){
			A[k]=L[i];
			cout << "\t \t (L["<<i<<"]<=R["<<j<<"])  =>   ";
			cout << "A["<<k<<"]=L["<<i<<"],  =>   i="<<(i+1)<<endl;
			i++;
		}else{
			cout << "\t \t (L["<<i<<"]>R["<<j<<"])  =>   ";
			cout << "A["<<k<<"]=R["<<j<<"],  =>   j="<<(j+1)<<endl;
			A[k]=R[j];
			j++;
		}
	}cout << "\t endFor" << endl;
//pa' que i y j lleguen a n1 y n2 respectivamente
	cout << "\t WHILE(i<n1): "<< endl;
	while(i<n1){ 
		cout << "\t \t "<< "(" << i << "<" << n1 << ")  =>  ";
		A[k]=L[i]; 
		cout << "A["<< k << "]=" << L[i] << " ,  =>  i="<< (i+1) << " , k=" << (k+1) << endl;
		i++; 
		k++; 
	} cout << "\t EndWhile-1" << endl;
	cout << "\t WHILE(j<n2): " << endl;
	while(j<n2){ 
		cout << "\t \t "<< "(" << j << "<" << n2 << ")  =>  ";
		A[k]=R[j]; 
		cout << "A["<< k << "]=" << R[j] << " ,  =>  j=" << (j+1) << " , k=" << (k+1) << endl;
		j++; 
		k++; 
	} cout << "\t EndWhile-2"<<endl;
	cout << "\t FINAL A = [ ";
	for(int z=0; z<=r; z++){
		cout << A[z]<< "  ";
	}cout << "] "<<endl;
	
} 

void imprimeCad(int A[], int tam) { 
	int i; 
	for (i=0;i<tam;i++){ 
		printf("%d ", A[i]); 
	}
	printf("\n"); 
} 

void MergeSort(int *A, int p, int r){ 
	cout << endl << "MergeSort(A,"<<p<<","<<r<<") "<< endl;
	if (p<r){ 
		cout << "IF"<< endl;
		int q=(p+r)/2; 
		cout << "q: " << q << endl;
		cout << "MergeSortIzquierda: MergeSort(A," << p << "," << q << ") " << endl; 
		MergeSort(A,p,q); 

		cout << "MergeSortDerecha: MergeSort(A," << (q+1) <<","<< r <<") " << endl;
		MergeSort(A,q+1,r); 

		cout << "Merge(A,"<< p <<"," << q << "," << r << ") : " << endl;
		Merge(A,p,q,r); 
	} 
} 

int main(){ 
	int num,i,cadena[50];
	printf("Ingrese la longitud de la cadena:\n");
	scanf("%d",&num);
	cout << "Ingrese elementos: ";
	for(i=0;i<num;i++){
		cin>>cadena[i];
	}
	
	cout << endl << endl;
	MergeSort(cadena,0,num-1); 	
	printf("\nArreglado \n"); 
	imprimeCad(cadena, num); 
	return 1; 
	} 