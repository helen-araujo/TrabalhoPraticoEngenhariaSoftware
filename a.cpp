#include "HCSGE.h"
using namespace std;

bool rodando=true;
HC Engine;
HC_Botao b1;
void render();
void input();
int sans, sans1;

int main()
{
	Engine.CriarJanela(1280, 680, "lorem ipsum");
	sans=Engine.AbrirFonte("Sans.ttf", 10);
	sans1=Engine.AbrirFonte("Sans.ttf", 20);
	b1=Engine.CriarBtn(100, 100);
	b1.setDest(640, 340);
	while (rodando)
	{
		Engine.SetBackground(255, 255, 255, 255);
		render();
		input();
		//update();
	}
	return 0;
}

void render()
{
	Engine.Desenhar(true, 100, 100, 640, 340, 255, 0, 0, 255);
	Engine.Desenhar("Lorem Ipsum", sans, 600, 300, 0, 0, 0);
	Engine.Commit(60);
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
				break;
			case 1://caso um botao tenha sido apertado
				break;
			case 2://caso um botão tenha sido solto
				break;
			case 3://caso seja clique
				if((asc[1]==1)&&b1.Sobre())
					cout<<"clique!"<<endl;					
				break;
		}
	}while(asc[0]!=0);
}
