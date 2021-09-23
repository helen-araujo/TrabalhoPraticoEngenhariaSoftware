#include "HCSGE.h"
#include "GerEstoque.h"

int main()
{
	HC Engine;
	Engine.CriarJanela(1280, 680, "Lorem Ipsum");
	GerEstoque TelaEstoque(&Engine);
	TelaEstoque.telaprinc();
	return 0;
}
