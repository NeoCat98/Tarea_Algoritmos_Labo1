#include <iostream>
#define SIZE 3
using namespace std;

void SumaMatrices(int A [][SIZE],int B [][SIZE], int C [][SIZE],int valorN,int valorM){
	if(valorN == 0 and valorM == 0){
		C[valorN][valorM] = A[valorN][valorM] + B[valorN][valorM];
	}
	else if(valorN == 0){
		C[valorN][valorM] = A[valorN][valorM] + B[valorN][valorM];
		SumaMatrices(A,B,C,SIZE,valorM-1);
	}
	else{
		C[valorN][valorM] = A [valorN][valorM] + B[valorN][valorM];
		SumaMatrices(A,B,C,valorN-1,valorM);
	}
}

void MostrarMatriz(int C[][SIZE],int n){
	for(int i=0;i<n;i++){
		cout<<"[";
		for(int j=0;j<n;j++){
			cout<< C[i][j] <<" ";
		}
		cout<<"]"<<endl;
	}
}


int Exponencial(int x,int n){
	if(n==1){
		return x;
	}
	else{
		return x*Exponencial(x,n-1);
	}
}

int MenorNumero(int A[],int n){
	if(n==1){
		return A[n-1];
	}
	else{
		int sig = MenorNumero(A,n-1);
		if(A[n-1]>sig){
			return sig;
		}else{
			return A[n-1];
		}
	}
}


int main(){
	//Suma De Matrices
	int matrizA [3][3] = {{1,1,1},{2,2,2},{3,3,3}};
	int matrizB [3][3] = {{1,2,3},{2,3,4},{3,4,5}};
	int matrizC [3][3];
	SumaMatrices(matrizA,matrizB,matrizC,SIZE,SIZE);
	MostrarMatriz(matrizC,SIZE);
	//El Resultado de la Operación X**N
	cout<<Exponencial(2,3)<<endl;
	//Menor Numero de Un Arreglo
	int A2[] = {130,20,310,40,35};
	cout<<MenorNumero(A2,5)<<endl;
}
