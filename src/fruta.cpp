/**
* @file fruta.cpp
* @brief Implementação da subclasse fruta
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#include "fruta.h"

/**
 * @brief      Constructs the object.
 */
Fruta::Fruta() {}

Fruta::Fruta(string _codigo, string _descricao, float _preco, 
	string _data, int _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_validade(_validade) {}

/**
 * @brief      Destroys the object.
 */
Fruta::~Fruta() {}



/**
 * @brief      Gets the data lote.
 *
 * @return     The data lote.
 */
string Fruta::getDataLote() {
	return m_data_lote;
}

/**
 * @brief      Gets the validade.
 *
 * @return     The validade.
 */
int 
Fruta::getValidade() {
	return m_validade;
}

/**
 * @brief      Sets the data lote.
 *
 * @param[in]  _data  The data
 */
void 
Fruta::setDataLote(string _data) {
	m_data_lote = _data;
}

/**
 * @brief      Sets the validade.
 *
 * @param[in]  _validade  The validade
 */
void 
Fruta::setValidade(int _validade) {
	m_validade = _validade;
}
 
/**
 * @brief      Print the product
 *
 * @param      &o  
 *
 * @return     Returns the product
 */
ostream& 
Fruta::print(ostream &o) const {
	o << setfill (' ') << setw (10) << m_cod_barras << " | " 
	  << setfill ('.') << setw (20) << m_descricao << " | " 
	  << setfill (' ') << setw (5) << setprecision(5) << m_preco << " | "
	  << setfill (' ') << setw (10) << m_data_lote << " | " 
	  << setfill (' ') << setw (3) << m_validade;
	return o;
}
