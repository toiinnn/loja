/**
* @file fruta.h
* @brief Cabeçalho da subclasse roupa
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

/**
 * @brief      Class for fruta.
 */
class Fruta : public Produto
{
public:
	Fruta();
	Fruta(string _codigo, string _descricao, float _preco, 
		  string _data, int _validade);
	~Fruta();
private:
	string m_data_lote;
	int m_validade;
public:
	// getters
	string getDataLote();
	int getValidade();
	// setters
	void setDataLote(string _data);
	void setValidade(int _validade);
private:
	ostream& print(ostream &o) const;
};

#endif