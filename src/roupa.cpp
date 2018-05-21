#include <iomanip>
#include "roupa.h"

/**
 * @brief      Constructs the object.
 */
Roupa::Roupa() {}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  _codigo     The codigo
 * @param[in]  _descricao  The descricao
 * @param[in]  _preco      The preco
 * @param[in]  _marca      The marca
 * @param[in]  _sexo       The sexo
 * @param[in]  _tamanho    The tamanho
 */
Roupa::Roupa(std::string _codigo, std::string _descricao, float _preco, 
	std::string _marca, std::string _sexo, std::string _tamanho):
	Produto(_codigo, _descricao, _preco), m_marca(_marca), m_sexo(_sexo), m_tamanho(_tamanho) {}

/**
 * @brief      Destroys the object.
 */
Roupa::~Roupa() {}


/**
 * @brief      Gets the marca.
 *
 * @return     The marca.
 */
std::string
Roupa::get_marca(){
	return m_marca;
}

/**
 * @brief      Gets the sexo.
 *
 * @return     The sexo.
 */
std::string
Roupa::get_sexo(){
	return m_sexo;
}

/**
 * @brief      Gets the tamanho.
 *
 * @return     The tamanho.
 */
std::string
Roupa::get_tamanho(){
	return m_tamanho;
}

/**
 * @brief      Sets the marca.
 *
 * @param[in]  _marca  The marca
 */
void
Roupa::set_marca(std::string _marca){
	m_marca = _marca;
}

/**
 * @brief      Sets the sexo.
 *
 * @param[in]  _sexo  The sexo
 */
void 
Roupa::set_sexo(std::string _sexo){
	m_sexo = _sexo;
}

/**
 * @brief      Sets the tamanho.
 *
 * @param[in]  _tamanho  The tamanho
 */
void 
Roupa::set_tamanho(std::string _tamanho){
	m_tamanho = _tamanho;
}
 
/**
 * @brief      	Print the clothe.
 *
 * @param      {ostream}	o  
 *
 * @return      This function returns the clothe in the right format to print
 */
std::ostream& 
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill ('.') << std::setw (15) << m_marca << " | " 
		<< std::setfill (' ') << std::setw (1) << m_sexo << " | " 
		<< std::setfill (' ') << std::setw (2) << m_tamanho;
	return o;
}
