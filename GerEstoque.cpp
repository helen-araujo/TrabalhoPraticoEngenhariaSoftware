#include <iostream>
#include "GerEstoque.h"

GerEstoque::GerEstoque(HC* engine)
{
	par=true;
	Engine=engine;
	font=Engine->AbrirFonte("Sans.ttf", 20);
	font1=Engine->AbrirFonte("Sans.ttf", 12);
	ifstream file;
	file.open("estoque.txt");
	string t;
	while (getline(file, t))
		arq += t + '\n';
	file.close();
}

void GerEstoque::telaprinc()
{
	while(1)
	{
		Engine->SetBackground(255, 255, 255, 255);
	
		bts[0]=Engine->CriarBtn(120, 50);
		bts[0].setDest(580, 200);
		Engine->Desenhar(true, 120, 50, 580, 200, 255, 0, 0, 255);
		Engine->Desenhar("Adicionar ao estoque", font1, 582, 220, 255, 255, 255);
		
		bts[1]=Engine->CriarBtn(120, 50);
		bts[1].setDest(580, 255);
		Engine->Desenhar(true, 120, 50, 580, 255, 255, 0, 0, 255);
		Engine->Desenhar("Remover do estoque", font1, 582, 275, 255, 255, 255);
	
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
		}
	}
}

void GerEstoque::Adicionar()
{
	Engine->SetBackground(255, 255, 255, 255);
	Engine->Desenhar("Informe a quantidade e o nome no terminal separados por espaco", font, 340, 240, 0, 0, 0);
	Engine->Commit(60);
	int quant;
	string nome;
	cin>>quant>>nome;
	estoquetemp.push_back(to_string(quant)+nome);
}

void GerEstoque::Remover()
{
	Engine->SetBackground(255, 255, 255, 255);
	Engine->Desenhar("Informe o numero da entrada a ser apagada", font, 440, 240, 0, 0, 0);
	Engine->Commit(60);
	int aux;
	cin>>aux;
	estoquetemp.erase(estoquetemp.begin()+(aux-1));
}

int GerEstoque::input()
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
				if((asc[1]==1)&&bts[0].Sobre())
				{
					par=false;
					return 0;
				}
				if((asc[1]==1)&&bts[1].Sobre())
				{
					par=false;
					return 1;
				}
				break;
		}
	}while(asc[0]!=0);
	return -1;
}
