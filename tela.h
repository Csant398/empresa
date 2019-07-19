#include <locale.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include"Funcionario.h"

using namespace std;

void criar(char* arquivo)
{
    funcionario func= {0, "", "", ' ', "", 0.00};
    char* aquivo="empresa.txt";

    ofstream empresa;
    empresa.open(arquivo);
    if (empresa.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    for (int i = 0; i < 100; i++)
        empresa.write((const char *)(&func),sizeof(funcionario));

    cout<<"\nArquivo criado com sucesso"<<endl;

    empresa.close();
}

void inserir(char* arquivo)
{
    int buscaid;
    char op;
    funcionario func;

    fstream empresa;
    empresa.open(arquivo, ios::in | ios:: out | ios::ate);
    if (empresa.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    cout<<"\n====================="<<endl;
    cout<<" INSERIR FUNCIONARIO"<<endl;
    cout<<"====================="<<endl;

    do
    {
        cout << "\nEntre com o numero do ID de 1 a 100 (0 termina) ";
        cin >> buscaid;


            empresa.seekp((buscaid - 1) * sizeof(funcionario));
            empresa.read((char *)(&func), sizeof(funcionario));

            if(func.id==buscaid)
                cout<<"\nFuncionario ja cadastrado"<<endl;

            else
            {
                func.id=buscaid;

                if(func.id>0 && func.id<= 100)
                {
                    cout << "Informe o nome do funcionario: ";
                    cin >> func.nome;
                    cout << "Informe o cargo do funcionario: ";
                    cin>> func.cargo;
                    cout << "Informe o sexo do funcionario (M/F): ";
                    cin>> func.sexo;
                    while(func.sexo!='m' && func.sexo!='f')
                    {
                        cout << "Informe o sexo do funcionario (M/F): ";
                        cin>> func.sexo;
                    }
                    cout << "Informe o local do funcionario: ";
                    cin>> func.local;
                    cout << "Informe o salario do funcionario: ";
                    cin>> func.salario;

                    empresa.seekp((func.id - 1) * sizeof(funcionario));
                    empresa.write((const char *)(&func),sizeof(funcionario));

                    cout<<"\nFuncionario cadastrado com sucesso"<<endl;
                }
            }
        do
        {
            cout <<"\nDeseja cadastrar um novo funcionario?(S-sim/N-nao): ";
            cin >> op;
        }
        while(op!='s'&& op!='n');

    }
    while(op=='s'||op=='s');

    empresa.close();
}

void listar(char* arquivo)
{
    funcionario func;
    ifstream empresa;
    empresa.open(arquivo);
    if (empresa.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    cout<<"\n========================="<<endl;
    cout<<" FUNCIONARIOS CADASTRADOS"<<endl;
    cout<<"=========================="<<endl;

    cout<< setiosflags(ios::left)
        <<setw(5)<<"Id"
        <<setw(15)<<"nome"
        <<setw(15)<<"cargo"
        <<setw(5)<<"sexo"
        <<setw(15)<<"local"
        << resetiosflags(ios::left)
        <<setw(10)<<"salario"<<endl;
    empresa.read((char *)(&func), sizeof(funcionario));

    cout<<"\n";
    while(empresa && ! empresa.eof())
    {
        if((func.id!=0))
        {
            cout<< setiosflags(ios::left)
                <<setw(5)<<func.id
                <<setw(15)<<func.nome
                <<setw(15)<<func.cargo
                <<setw(5)<<func.sexo
                <<setw(15)<<func.local
                <<setw(10)<<setprecision (2) << resetiosflags(ios::left)
                <<setiosflags(ios::fixed | ios::showpoint)<<func.salario<<endl;

        }
        empresa.read((char *)(&func), sizeof(funcionario));
    }
    empresa.close();
    getch();
}

void atualizar(char* arquivo)
{
    int buscaid;
    funcionario func;
    fstream empresa;
    empresa.open(arquivo,ios::in|ios::out|ios::ate);
    if (empresa.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    cout<<"\n================="<<endl;
    cout<<" ALTERAR SALARIO"<<endl;
    cout<<"================="<<endl;
    cout<<"\nQual o ID voce gostaria de alterar o salario?";
    cin>> buscaid;
    empresa.seekp((buscaid - 1) * sizeof(funcionario));
    empresa.read((char *)(&func), sizeof(funcionario));

    if(func.id!=0)
    {
        func.id=buscaid;
        cout<<"Qual o novo Salario do "<< func.nome <<"?"<< endl;
        cin>> func.salario;

        empresa.seekp((func.id - 1) * sizeof(funcionario));
        empresa.write((const char *)(&func),sizeof(funcionario));
        empresa.close();
        cout<<"\nSalario alterado com sucesso\n"<<endl;
    }
    else
        cout<<"\nID nao cadastrado"<<endl;
}

void exluir(char* arquivo)
{
    int buscaid;
    char n;
    funcionario func;

    fstream empresa;
    empresa.open(arquivo,ios::in|ios::out|ios::ate);
    if (empresa.fail( ))
    {
        cout << "A abertura do arquivo de saida falhou.\n";
        exit(1);
    }

    cout<<"\n====================="<<endl;
    cout<<" EXCLUIR FUNCIONARIO"<<endl;
    cout<<"====================="<<endl;

    cout<<"Qual o ID voce gostaria de excluir?";
    cin>> buscaid;
    empresa.seekp((buscaid - 1) * sizeof(funcionario));
    empresa.read((char *)(&func), sizeof(funcionario));

    if(func.id!=0)
    {
        funcionario funcvazio= {0, "", "", ' ', "", 0.00};
        empresa.seekp((func.id - 1) * sizeof(funcionario));
        empresa.write((const char *)(&funcvazio),sizeof(funcionario));
        cout<<"\nFuncionario excluido com sucesso"<<endl;
    }
    else
        cout<<"\nID nao cadastrado"<<endl;

    empresa.close();
}
