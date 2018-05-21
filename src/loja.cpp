/**
* @file loja.cpp
* @brief Implementação da loja
* @author Antonio Marcos Oliveira
* @since 13/05/2018
* @date 17/05/2018
*/
#include "loja.h"
#include <typeinfo>
#include <cstring>

/**
 * @brief      Constructs the object.
 */
Loja::Loja() {}

/**
 * @brief      Destroys the object.
 */
Loja::~Loja() {}

/**
 * @brief      Gets the produto.
 *
 * @return     The produto.
 */
vector<shared_ptr<Produto>>
Loja::get_produto()
{
    return mostruario;
}

/**
 * @brief      Add the product on mostruario
 *
 * @param[in]  cod_barras_  The cod barras
 *
 * @return     void function
 */
void 
Loja::add_produto(shared_ptr<Produto> p)
{
    if(mostruario.size() == 0) {mostruario.push_back(p); return;}
    for (auto i = mostruario.begin(); i != mostruario.end(); ++i)
    {
        if(**i == *p)
        {
            cerr << "Produtos com o mesmo código de barra! A operação foi cancelada." << endl;
            return;
        }
    }
    mostruario.push_back(p);
} 

/**
 * @brief      Show product on mostruario
 *
 * @param[in]  no param
 *
 * @return     void function
 */
void 
Loja::mostrar_produtos()
{
        if (mostruario.size() == 0){
            cout << "Sua loja ainda está vazia! Fale com seus fornecedores." << endl;
        }else
        {
            for (auto i = mostruario.begin(); i != mostruario.end(); ++i)
                cout << (**i) << endl;
        }
}

/**
 * @brief      Search the product on mostruario
 *
 * @param[in]  cod_barras_  The cod barras
 *
 * @return     The product or nullptr is mostruario is null
 */
shared_ptr<Produto> 
Loja::procurar_produto(string cod_barras_)  
{
    for(auto i = mostruario.begin(); i != mostruario.end(); ++i)
    {
        if( (**i).getCodBarras().compare(cod_barras_) == 0 )
            return *i;
    }
    cout << "O produto com esse código de barras não foi encontrado no estoque." << endl;
    return nullptr; 
}

/**
 * @brief      Delete the product on mostruario
 *
 * @param[in]  cod_barras_  The cod barras
 *
 * @return     void function
 */
void 
Loja::deletar_produto(string cod_barras_)
{
    for(auto i = mostruario.begin(); i != mostruario.end(); ++i)
    {
        if( (**i).getCodBarras().compare(cod_barras_) == 0 )
        {
            mostruario.erase(i);
            cout << "Produto removido com sucesso." << endl;
            return;
        }
           
    }
     cout << "O produto com esse codigo de barras não foi encontrado. Falha na remoção." << endl;
}

/**
 * @brief      Put the fruits from a .dat file to mostruario
 *
 * @param[in]  
 *
 * @return     void function
 */

void 
Loja::ler_frutas()
{
    ifstream frutas;
    frutas.open("../files/frutas.dat");
    if (frutas.bad()) 
    {
        cerr << "Ops! Há algum problema com o arquivo. Não foi possível abrir." << endl;
        exit(EXIT_FAILURE);
    }


    string linha;      
    while(getline(frutas, linha))
    {
        stringstream aux(linha);
        string cod_barras, descricao, preco, data_lote, validade;

        getline(aux, cod_barras, ';');
        getline(aux, descricao, ';');
        getline(aux, preco, ';');
        getline(aux, data_lote, ';');
        getline(aux, validade, ';');
        
        add_produto(make_shared<Fruta>(cod_barras, descricao, stof(preco), data_lote, stof(validade)));
    }  
}


/**
 * @brief      Put the beverage from a .dat file to mostruario
 *
 * @param[in]  
 *
 * @return     void function
 */
void 
Loja::ler_bebidas()
{
    ifstream bebidas;
    bebidas.open("../files/bebidas.dat");
    if (bebidas.bad()) 
    {
        cerr << "Ops! Há algum problema com o arquivo. Não foi possível abrir." << endl;
        exit(EXIT_FAILURE);
    }

    string linha;    
    while ( getline(bebidas, linha) )
    {
        stringstream aux(linha);
        string cod_barras, descricao, preco, teor_alcoolico;
        
        getline(aux, cod_barras, ';');
        getline(aux, descricao, ';');
        getline(aux, preco, ';');
        getline(aux, teor_alcoolico, ';');
     
        add_produto(make_shared<Bebida>( cod_barras, descricao, stof(preco), stoi(teor_alcoolico)));
    }
}

/**
 * @brief      Put the clothes from a .dat file to mostruario
 *
 * @param[in]  
 *
 * @return     void function
 */
void
Loja::ler_roupas()
{
    ifstream roupa;
    roupa.open("../files/roupas.dat");
    if (roupa.bad()) 
    {
        cerr << "Ops! Há algum problema com o arquivo. Não foi possível abrir." << endl;
        exit(EXIT_FAILURE);
    }

    string linha;    
    while (getline(roupa, linha))
    {
        stringstream aux(linha);
        string cod_barras, descricao, preco, marca, genero, tamanho;

        getline(aux, cod_barras, ';');
        getline(aux, descricao, ';');
        getline(aux, preco, ';');
        getline(aux, marca, ';');
        getline(aux, genero, ';');
        getline(aux, tamanho, ';');      
         
        add_produto(make_shared<Roupa>(cod_barras, descricao, stof(preco), marca, genero, tamanho));
    }
}




