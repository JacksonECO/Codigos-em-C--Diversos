//Criado por Jackson Galdino, aluno de ECO.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
  int cont=0, prof=0, test;
  bool linha=false, ok=false, tu=false;
  string line, turma="";

  //Coloque o nome do arquivo dentro dos paremetros a abaixo
  //Recomendo a utilização de arquivos no formato .txt ou .html
  //Deve ser pego o codigo fonte da paginha participantes de qualquer disciplina no sigaa;

  ifstream myfile ("organizacao.html");

  if (myfile.is_open()){
    while (!myfile.eof()){
      getline (myfile,line);

      for (int i = 0;; ++i){

        if(turma==""){
          if(line[i]=='i' && line[i+1]=='d' && line[i+4]=='l' && line[i+6]=='n' && line[i+8]=='N'){
            for (int x = i;line[x]!='<'; ++x){
              if(line[x-1]=='>')
                tu=true;
              if(tu)
                turma+=line[x];
            }
          }

        }

        if(prof==0){
          if(line[i]=='(' && line[i+2]==')' && line[i-2]=='s' && line[i-4]=='t'){
            test=line[i+1];
            if(test>=48 && test<=57){
              prof=test-48;
            }
          }
          if(prof!=0){
            cout<<"E-mail "<<(prof>1?"dos ":"do ")<<(prof>1?"professores:":"professor:")<<endl;
          }
        }

        if(i>=11 && line[i]=='>' && line[i-11]=='E' && line[i-10]=='-'){
          i++;
          cont++;
          ok=true;
          linha=true;
        }

        if(ok){
          if(line[i+1]=='<'){
            ok=false;
          }
          if(line[i]!=' ')
            cout<<line[i];
        }

        if(line[i+1] == '\0'){
          ok=false;
          break;
        }
      }

      if(linha && cont!=prof){
        cout << endl;
        linha=false;
      }
      if(linha && cont==prof){
        cout << endl << endl << "E-mail dos Alunos:"<<endl;
        linha=false;
      }
    }

    cout<<endl<<"Na Tuma de "<< turma <<" tem "<<cont-prof<<" alunos e "<<prof<< " professor"<<(prof>1?"es.":".")<<endl<<endl;
    myfile.close();
  }

  else {
  	cout << endl << " :: Nao foi possivel abrir o arquivo." << endl << endl;
  	cout << " * Verifique se o nome e o formato do arquivo esta igual (recomendo o formato .txt ou .html);" << endl;
  	cout << " * E se o arquivo se encontre no mesmo diretorio onde esta salvo este arquivo;" <<endl<<endl; 
  }


  return 0;
}