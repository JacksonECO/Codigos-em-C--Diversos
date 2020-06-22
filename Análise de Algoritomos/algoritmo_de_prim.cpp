///Algoritmo de arvore geradora minima

#include <iostream>
#define Inf 1000000
#define Size 6

using namespace std;

//Fiz este bool para controle
//Caso seja para ser feito com letras apenas altere para false seu valor

bool numeros_como_resposta = true;

void prim(int ini, int grafo[6][6]){
	int custo[Size];
	int ant[Size];
	bool close[Size];

	int vcm=-1;
	int custo_total=0;
	bool imp = false;

	for (int i = 0; i < Size; ++i){
		custo[i] = Inf;
		ant[i] = -1;
		close[i] = false;
	}

	custo[ini]=0;


	while(true){
		vcm = -1;
		for (int i = 0; i < Size; ++i)
			if((!close[i]) && ((vcm == -1 ) || (custo[i] < custo[vcm])))
				vcm = i;

		if(vcm<0) break;
		close[vcm] = true;
		
		if(imp && numeros_como_resposta)//Usar Números
			cout<<"( "<<ant[vcm]<<"-"<<vcm<<" ) ";//Usar Números

		if(imp && !numeros_como_resposta)//Usar Letras
			printf("( %c-%c )", ant[vcm]+65, vcm+65 );//Usar Letras
		imp=true;

		custo_total += custo[vcm];



		for (int i = 0; i < Size; ++i){
			if((grafo[vcm][i] !=0 ) && (custo[i] > grafo[vcm][i])){
				custo[i] = grafo[vcm][i];
				ant[i] = vcm;
			}
		}

	}
	cout<<"\nCusto total: " << custo_total <<endl;
}

int main(int argc, char const *argv[]){

//grafo em formato matriz de adjacencia.
	int mat[6][6]={
		0,5,6,4,0,0,
		5,0,1,2,0,0,
		6,1,0,2,5,3,
		4,2,2,0,0,4,
		0,0,5,0,0,4,
		0,0,3,4,4,0,
	};

	prim(0,mat);

	return 0;
}