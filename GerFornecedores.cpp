#include "HCSGE.h"
#include<iostream>
#include "GerFornecedores.h"
using namespace std;

GerFornecedor::GerFornecedor(HC* engine)
{
	par=true;
	Engine=engine;
	font=Engine->AbrirFonte("Sans.ttf", 20);
	font1=Engine->AbrirFonte("Sans.ttf", 12);
}


void GerFornecedor::telaprinc()
{
	while(1)
	{
		Engine->SetBackground(255, 255, 255, 255);
	
		botao[0]=Engine->CriarBtn(120, 50);
		botao[0].setDest(580, 200);
		Engine->Desenhar(true, 120, 50, 580, 200, 255, 0, 0, 255);
		Engine->Desenhar("Adicionar Fornecedor", font1, 582, 220, 255, 255, 255);
		
		botao[1]=Engine->CriarBtn(120, 50);
		botao[1].setDest(580, 255);
		Engine->Desenhar(true, 120, 50, 580, 255, 255, 0, 0, 255);
		Engine->Desenhar("Excluir Fornecedor", font1, 582, 275, 255, 255, 255);

        botao[2]=Engine->CriarBtn(120, 50);
		botao[2].setDest(580, 315);
		Engine->Desenhar(true, 120, 50, 580, 315, 255, 0, 0, 255);
		Engine->Desenhar("Exibir", font1, 582, 317, 255, 255, 255);
	
		Engine->Commit(60);

		while(par)
			bot=input();
		par=true;
        
		switch(bot)
		{
			case -1:
				return;
				break;
			case 0:
				Adicionar();
				break;
			case 1:
				Remover();
				break;
            case 2:
				Exibir();
				break;    
		}
    }
}

void GerFornecedor::Adicionar()
{
	Engine->SetBackground(255, 255, 255, 255);
	Engine->Desenhar("Informe o CNPJ e o nome do Fornecedor", font, 340, 240, 0, 0, 0);
	Engine->Commit(60);
	double cnpj;
	string nome;
	cin>>cnpj>>nome;
	listaFornecedor.push_back(to_string(cnpj)+nome);
}

void GerFornecedor::Remover()
{
	Engine->SetBackground(255, 255, 255, 255);
	Engine->Desenhar("Informe a posicao na lista do CNPJ a ser excluido", font, 440, 240, 0, 0, 0);
	Engine->Commit(60);
	int aux;
	cin>>aux;
	listaFornecedor.erase(listaFornecedor.begin()+(aux-1));
}


void GerFornecedor::Exibir()
{
	Engine->SetBackground(255, 255, 255, 255);
	Engine->Desenhar("(clique para voltar)", font1, 440, 40, 0, 0, 0);
	for(int i=0; i<listaFornecedor.size(); i++)
		Engine->Desenhar(listaFornecedor[i], font, 440, 140+(20*i), 0, 0, 0);
	Engine->Commit(60);
	while (1)
		if (input()==3)
			break;
}


int GerFornecedor::input()
{
	vector<int>asc;
	do
	{
		asc=Engine->HaInput();
		switch(asc[0])//qual o tipo de evento
		{
			case -1://caso seja fechar
				par=false;
				return -1;
				break;
			case 1://caso um botao tenha sido apertado
				break;
			case 2://caso um botão tenha sido solto
				break;
			case 3://caso seja clique
				if((asc[1]==1)&&botao[0].Sobre())
				{
					par=false;
					return 0;
				}
				
				else if((asc[1]==1)&&botao[1].Sobre())
				{
					par=false;
					return 1;
				}
				
				else if((asc[1]==1)&&botao[2].Sobre())
				{
					par=false;
					return 2;
				}
				else return 3;
				break;
		}
	}while(asc[0]!=0);
	return -1;
}