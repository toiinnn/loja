/**
* @file bebida.cpp
* @brief Implementação da subclasse bebida
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#include <iomanip>
#include "bebida.h"


/**
 * @brief      Constructs the object.
 */
Bebida::Bebida() {}

Bebida::Bebida(std::string _codigo, std::string _descricao, float _preco, 
	int _teor_alcoolico):
	Produto(_codigo, _descricao, _preco), m_teor_alcoolico(_teor_alcoolico) {}

/**
 * @brief      Destroys the object.
 */
Bebida::~Bebida() {}

/**
 * @brief      Gets the teor alcoolico.
 *
 * @param[in]  teor_alcoolico_  The teor alcoolico
 */
int Bebida::get_teor_alcoolico(){
	return m_teor_alcoolico;
}


/**
 * @brief      Sets the teor alcoolico.
 *
 * @param[in]  teor_alcoolico_  The teor alcoolico
 */
void Bebida::set_teor_alcoolico(int teor_alcoolico_){
	m_teor_alcoolico = teor_alcoolico_;
}
 
/**
 * @brief      Print the beverage
 *
 * @param[in]  ostream &o  The product
 */
std::ostream& 
Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (3) << m_teor_alcoolico;
	return o;
}