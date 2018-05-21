/**
* @file produto.cpp
* @brief Implementação da subclasse fruta
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#include <iostream>
#include "produto.h"

/**
 * @brief      Constructs the object.
 */
Produto::Produto() {}

/**
 * @brief      Destroys the object.
 */
Produto::~Produto(){}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  _codigo     The codigo
 * @param[in]  _descricao  The descricao
 * @param[in]  _preco      The preco
 */
Produto::Produto(std::string _codigo, std::string _descricao, float _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}

/**
 * @brief      Gets the cod barras.
 *
 * @return     The cod barras.
 */
std::string 
Produto::getCodBarras() {
	return m_cod_barras;
}
	
/**
 * @brief      Gets the descricao.
 *
 * @return     The descricao.
 */
std::string 
Produto::getDescricao() {
	return m_descricao;
}

/**
 * @brief      Gets the preco.
 *
 * @return     The preco.
 */
float 
Produto::getPreco() {
	return m_preco;
}
	
/**
 * @brief      Sets the cod barras.
 *
 * @param[in]  _codigo  The codigo
 */
void 
Produto::setCodBarras(std::string _codigo) {
	m_cod_barras = _codigo;
}

/**
 * @brief      Sets the descricao.
 *
 * @param[in]  _descricao  The descricao
 */
void 
Produto::setDescricao(std::string _descricao) {
	m_descricao = _descricao;
}

/**
 * @brief      Sets the preco.
 *
 * @param[in]  _preco  The preco
 */
void 
Produto::setPreco(float _preco) {
	m_preco = _preco;
}

/**
 * @brief      Overloading the operator +
 *
 * @param      p     get a product to add to each other
 *
 * @return     the price of twice products
 */
int 
Produto::operator+ (Produto &p)
{
	return this->m_preco + p.getPreco();
}

/**
 * @brief      Overloading the operator -
 * @param      p     get a product to subtract to each other
 *
 * @return     the diference price of twice products
 */
int 
Produto::operator- (Produto &p)
{
	return this->m_preco - p.getPreco();
}

/*
 * @brief      Overloading the operator ==
 * @param      p     compare the codebar between two products
 *
 * @return     if they are equals or not (bool function)
 */
bool
Produto::operator== (Produto &p)
{
	return this->m_cod_barras.compare(p.getCodBarras()) == 0;
}

std::ostream& operator<< (std::ostream &o, Produto const &p) {
	return p.print(o);
}


