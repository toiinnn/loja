/**
* @file bebida.h
* @brief Cabeçalho da subclasse bebida
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

/**
 * @brief      Class for bebida.
 */
class Bebida : public Produto
{
public:
	Bebida();
	Bebida(string _codigo, string _descricao, float _preco, 
		  int _teor_alcoolico);
	~Bebida();
private:
	int m_teor_alcoolico;
public:
	// getters
	int get_teor_alcoolico();
	// setters
	void set_teor_alcoolico(int teor_alcoolico_);
private:
	ostream& print(ostream &o) const;
	istream& print(istream &i) const;
};

#endif