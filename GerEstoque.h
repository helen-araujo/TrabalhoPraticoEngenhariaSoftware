#pragma once
#include "HCSGE.h"
#include <fstream>

using namespace std;

class GerEstoque
{
	private:
	string arq;
	int font, font1, bot;
	HC* Engine;
	HC_Botao bts[3];
	bool par;
	vector<string>estoquetemp;
	
	public:
	GerEstoque(HC*engine);
	void telaprinc();
	int input();
	void Adicionar();
	void Remover();
	//void exibir()
};
