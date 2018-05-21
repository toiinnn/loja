/**
* @file produto.h
* @brief Cabeçalho da superclasse produto
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief      Class for produto.
 */
class Produto
{
public:
	Produto();
	Produto(string _codigo, string _descricao, float _preco);
	virtual ~Produto();
protected:
	string m_cod_barras;
	string m_descricao;
	float m_preco;		
public:
	// getters
	string getCodBarras();
	string getDescricao();
	float getPreco();
	// setters
	void setCodBarras(string _codigo);
	void setDescricao(string _descricao);
	void setPreco(float _preco);

	bool operator== (Produto &p);
	int operator- (Produto &p);
	int operator+ (Produto &p);
	
	friend ostream& operator<< (ostream &o, Produto const &t);
private:
	virtual ostream& print(ostream&) const = 0;
};
 
#endif
