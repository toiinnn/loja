/**
* @file loja.h
* @brief Cabeçalho da loja
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#ifndef _LOJA_H_
#define _LOJA_H_

#include "bebida.h"
#include "fruta.h"
#include "roupa.h"

/**
 * @brief      Class for loja.
 */
class Loja
{
private:
	vector<shared_ptr<Produto>> mostruario;

public:
	Loja();
	~Loja();

	vector<shared_ptr<Produto>> get_produto();
	void add_produto(shared_ptr<Produto> p);
	void mostrar_produtos();
	shared_ptr<Produto> procurar_produto(string cod_barras_);
	void deletar_produto(string cod_barras_);
	void ler_frutas();
	void ler_roupas();
	void ler_bebidas();


};

#endif