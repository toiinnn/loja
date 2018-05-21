#include "loja.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Loja mercadinho_da_esquina;
	cout << "Estamos abastecendo nosso estoque..." << endl;
	mercadinho_da_esquina.ler_frutas();
	mercadinho_da_esquina.ler_bebidas();
	mercadinho_da_esquina.ler_roupas();

	cout << "Agora sim, bem vindo ao mercadinho da esquina!" << endl;
	cout << "Bem, esse são os produtos disponíveis:" << endl;
	mercadinho_da_esquina.mostrar_produtos();

	cout << "Se você está procurando por algo específico, pode usar nossa busca:" << endl;
	auto pesquisa = mercadinho_da_esquina.procurar_produto("001002003-01");
	if(pesquisa != nullptr) 
		cout << "Olha ele bem aqui! " << endl <<  *pesquisa << endl;

	auto produtos = mercadinho_da_esquina.get_produto();
	cout << "Vamos testar a calculadora do mercadinho?" << endl;
	cout << "Essa é a soma de dois produtos do nosso mercado: "
	 	 << *produtos.at(0) + *produtos.at(5) << " reais." << endl;
	cout << "Essa é a diferença entre os dois produtos do nosso mercado: "
		 << *produtos.at(produtos.size() - 6) - *produtos.at(produtos.size() - 4) << " reais." << endl;

	cout << "Eita! A jaqueta do Original Alecrim deu sold out! Precisamos deletar ela do mostruário." << endl;
	mercadinho_da_esquina.deletar_produto("033012017-15");
	
	cout << "Mas será que ele foi excluído mesmo? Hum... vamos verificar!" << endl;
	auto pesquisa2 = mercadinho_da_esquina.procurar_produto("033012017-15");
	if(pesquisa2 != nullptr) 
		cout << "Ops! Algo de errado não deu certo." << endl << *pesquisa2 << endl;


	return 0;
}