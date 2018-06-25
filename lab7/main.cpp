/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa para imprimir o número seguinte mais próximo da média
* @since 27/05/2018
* @date 28/05/2018
*/
#include <iostream>
using namespace std;
/** 
	@brief Inclusão da Standart Library Vector
 */
#include <vector>
using std::vector;
#include <stdexcept>

class Teste{
public:
	void outOfRange(int tamanho){
		if(tamanho>=7)
			throw invalid_argument ("-ERROr: tamanho inesperado");
	}
};

/** @brief Template InputIterator closest2mean criando um InputIterator first e InputIterator last */
template<typename InputInterator> InputInterator closest2mean (InputInterator first, InputInterator last)
{
/** @brief parâmetro float */
/** @param media que representa a média dos valores inseridos no vetor v */
	float media=0;
/** @brief criação do vetor com o iterator i apontando pros parâmetros inteiros */
	vector<int>::iterator i;
/** @brief criação de um laço indo de i=first ao i!=last, sempre acrescentando 1 em i */
	for(i = first;i!=last;++i){
/** @brief soma do numero contido naquela memória apontada por i a média */
		media +=(*i);
	}
	cout << endl;
/** @brief dividindo o parâmetro média por 6 */
	media/=6;
/** @brief criação de uma precisão de um número após a vírgula no float */
	cout.precision(2);
	cout << "Média: " << media << endl;
/** @brief criação de um laço indo de i=first ao i!=last, sempre acrescentando 1 em i */
	for(i = first;i!=last;++i){
/** @brief criação de uma condicional para a atribuição  */
		if(media < *i){
			cout << "Número seguinte a média é: " << *i << endl;
			return i;
		}
	}
}

int main(){
/**  
	@brief criação de dois parâmetros int 
	@param i criado para ajudar no laço para implementação do num 
	@param aux criado a atribuição do número do vetor
*/
	int i=0,aux=1;
/**
	@brief criação de um vetor v com os parâmetros do vetor do tipo inteiro
*/
	vector<int> v;
	
	cout << "Digite os 6 números do vetor: " << endl;
	cout << "Logo após, digite '666' para parar indicar o fim do vetor" << endl;
/**
	@brief criação de um laço
	@details enquanto não for digitado o número '666' o programa continua alocando os números digitados
*/
	while(aux != 666){
	cin >> aux;
	v.push_back(aux);
	i++;
	}

	v.pop_back();
	i--;
/**
	@brief criação do condicional
	@details caso a quantidade de números digitados for maior que 6, dê erro
*/
	try{
		Teste t;
		t.outOfRange(v.size());
	}catch(invalid_argument& e){
		cout << e.what() << endl;
		exit(0);
	}


	
/**
	@brief chamada do template closest2mean, no qual recebe os parâmetros v.begin() e v.end()
*/
	closest2mean(v.begin(),v.end());

}
