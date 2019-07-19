#include <locale.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include"Funcionario.h"
#include"tela.h"

using namespace std;

void inserir(char* arquivo);
void criar(char* arquivo);
void atualizar(char* arquivo);
void listar(char* arquivo);
void exluir(char* arquivo);

int main()
{
    int op;
    char s;

    char* arquivo="empresa.txt";


    do{

        cout<<"1- Criar arquivo inicial"<<endl;
        cout<<"2- Inserir funcionario"<<endl;
        cout<<"3- Listar funcionario"<<endl;
        cout<<"4- Atualizar salario"<< endl;
        cout<<"5- Remover funcionario"<<endl;
        cout<<"0- Sair"<<endl;
        cout <<"\nDigite a opcao desejada: ";
        cin>>op;
        switch(op)
        {
            case 1: criar(arquivo);
                break;
                case 2: inserir(arquivo);
                break;
                case 3: listar(arquivo);
                break;
                case 4: atualizar(arquivo);
                break;
                case 5: exluir(arquivo);
                break;
                case 0: exit(0);
        }

    do{
    cout<<"\nRealizar nova operacao(S-sim/N-nao): ";
    cin>> s;
    }while(s!='s'&& s!='S' && s!='n' && s!='N');
    if(s=='n'||s=='N')
        exit(0);
    system("cls");
    }while(s=='s'||s=='S');
    return 0;
}
