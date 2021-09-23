#include "HCSGE.h"
#include "GerEstoque.h"
#include "GerFornecedores.h"


using namespace std;

bool rodando=true, aux=true;
HC_Botao bts[4];
HC Engine;

void input();

int main()
{
	Engine.CriarJanela(1280, 680, "Lorem Ipsum");
	int font1=Engine.AbrirFonte("Sans.ttf", 12);

	while (rodando)
	{
	aux=true;
	Engine.SetBackground(255, 255, 255, 255);
	
	bts[0]=Engine.CriarBtn(120, 50);
	bts[0].setDest(580, 200);
	Engine.Desenhar(true, 120, 50, 580, 200, 255, 0, 0, 255);
	Engine.Desenhar("Gerir estoque", font1, 582, 220, 255, 255, 255);
	
	bts[1]=Engine.CriarBtn(120, 50);
	bts[1].setDest(580, 255);
	Engine.Desenhar(true, 120, 50, 580, 255, 255, 0, 0, 255);
	Engine.Desenhar("Gerir funcionarios", font1, 582, 275, 255, 255, 255);
	
	bts[2]=Engine.CriarBtn(120, 50);
	bts[2].setDest(580, 310);
	Engine.Desenhar(true, 120, 50, 580, 310, 255, 0, 0, 255);
	Engine.Desenhar("Gerir fornecedores", font1, 582, 330, 255, 255, 255);
	
	bts[3]=Engine.CriarBtn(120, 50);
	bts[3].setDest(580, 365);
	Engine.Desenhar(true, 120, 50, 580, 365, 255, 0, 0, 255);
	Engine.Desenhar("Fazer venda", font1, 582, 390, 255, 255, 255);
	
	Engine.Commit(60);
	
	while(aux)
		input();
	}
	return 0;
}

void input()
{
	vector<int>asc;
	do
	{
		asc=Engine.HaInput();
		switch(asc[0])//qual o tipo de evento
		{
			case -1://caso seja fechar
				rodando=false;
				aux=false;
				break;
			case 1://caso um botao tenha sido apertado
				break;
			case 2://caso um botão tenha sido solto
				break;
			case 3://caso seja clique
				if((asc[1]==1)&&bts[0].Sobre())
				{
					GerEstoque TelaEstoque(&Engine);
					TelaEstoque.telaprinc();
					aux=false;
				}
				
				else if((asc[1]==1)&&bts[1].Sobre())
				{
					return;
				}
				
				else if((asc[1]==1)&&bts[2].Sobre())
				{
					GerFornecedor TelaFornecedor(&Engine);
					TelaFornecedor.telaprinc();
					aux=false;
				}
				else if((asc[1]==1)&&bts[3].Sobre())
				{
					return;
				}
				break;
		}
	}while(asc[0]!=0);
}