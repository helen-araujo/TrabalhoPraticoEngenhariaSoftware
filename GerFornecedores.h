#pragma once
#include "HCSGE.h"
#include<iostream>



class GerFornecedor{
	private:
	string arq;
	int font, font1, bot;
	HC* Engine;
	HC_Botao botao[3];
	bool par;
	vector<string>listaFornecedor;
	
	public:
	GerFornecedor(HC*engine);
	void telaprinc();
	int input();
	void Adicionar();
	void Remover();
	void Exibir();
	//void exibir()
};