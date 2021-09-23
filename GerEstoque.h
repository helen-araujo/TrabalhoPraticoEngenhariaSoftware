#pragma once
#include "HCSGE.h"
#include <fstream>

using namespace std;

class GerEstoque
{
	private:
	int font, font1, bot;
	HC* Engine;
	HC_Botao bts[3];
	bool par;
	vector<string>estoquetemp;
	
	public:
	GerEstoque(HC*engine);
	~GerEstoque();
	void telaprinc();
	int input();
	void Adicionar();
	void Remover();
	void Exibir();
<<<<<<< HEAD
};
=======
};
>>>>>>> c8d0f23dd6c7c6d21cb0643bdc5e4904535ff211
