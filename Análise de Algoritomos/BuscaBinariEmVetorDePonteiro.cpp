//Realiza um busca binaria pelo item de valor x
//em um vetor de ponteiro a,
//para isso é necessário ter um vetor ja ordenado

//Tem uma complexidade de O(lon n)

//Caso não enconte o item retorna -1

#include <iostream>
#define Inf 1000000

using namespace std;


int busca_binaria(int *a, int n, int x){
	int ini=0;
	int fim=n-1;
	int meio;

	while (ini <= fim){
		meio=(ini+fim)/2;

		if (x < a[meio])
			fim=meio-1;
		else if (x > a[meio])
			ini=meio+1;
		else
			return meio+1;
	}

	return -1;
}

int main(){


	int a[]={5,8,10,16,20,22,36,40,48,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf};
	int *pt= &a[0];
	int x;

	x=8;

	cout<< "Resposta: " << busca_binaria(pt, 9, x)<<endl;
}
