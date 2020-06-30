#include <iostream>
#include <algorithm> 
#define Valores 4
using namespace std;

bool ordem (int i,int j) { return (i>j); }

void calculaTroco(int* valores, int troco){

	sort(valores, valores+Valores, ordem);

	cout<< endl << "O troco sera dado por: ";

	for (int i = 0; i < Valores; ++i){

		while(valores[i] <= troco){
			troco -= valores[i];
			cout<<valores[i]<<", ";
		}
		if(troco == 0) break;
	}
	if(troco > 0){
		cout<<"Nao foi possivel completar o restante de: "<<troco<<" reais\n";
	}
}


int main(){
	int valores[] = {100,70,30,7};

	calculaTroco(valores, 397);


	return 0;
}