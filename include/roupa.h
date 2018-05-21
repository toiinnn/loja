/**
* @file roupa.h
* @brief Cabeçalho da subclasse roupa
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

/**
 * @brief      Class for roupa.
 */
class Roupa : public Produto
{
public:
	Roupa();
	Roupa(string _codigo, string _descricao, float _preco, 
		  string _marca, string _sexo, string _tamanho);
	~Roupa();
private:
	string m_marca;
	string m_sexo;
	string m_tamanho;
public:
	// getters
	string get_marca();
	string get_sexo();
	string get_tamanho();
	// setters
	void set_marca(string _marca);
	void set_sexo(string _sexo);
	void set_tamanho(string _tamanho);
private:
	ostream& print(ostream &o) const;
};

#endif