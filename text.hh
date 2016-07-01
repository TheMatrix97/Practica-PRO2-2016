/** @file text.hh
    @brief Especificacio de la classe text 
*/

#ifndef _TEXT_HH_
#define _TEXT_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#endif

/** @class text
    @brief Representa un text d'un autor 
	disposa d'una taula de freq per paraula, el contingut del text ordenat per frases i el num de paraules
*/

struct taulafreq{
	int freq;
	string paraula;
};

class text{
public:
	//Constructores
	/** @brief Creadora per defecte

      crea un text buit 
      \pre cert
      \post genera un text buit, amb taula de freqüencies buida i 0 paraules
  */
	text();
	
	//Modificadores
	/** @brief Llegir un text

      \pre cert
      \post El paràmetre implicit conte un text llegit del canal estandard d'entrada i
       el nombre de paraules i la taula de freqüencies estan actualitzats
  */
	void llegir();
	
	//Consultores
		/** @brief Consultar nombre de paraules

      \pre cert
      \post retorna el nombre de paraules del text
  */
	int consul_num_paraules();
	
	/** @brief Consultar nombre de frases

      \pre cert
      \post retorna el nombre de frases del text
  */
	int consul_frases();
	
	/** @brief Busca de frases mitjançant expressio

      \pre exp es una expressio booleana
      \post mostra les frases que compleixen l'expressio
  */
	void busqueda_par_express(string exp);
	
	/** @brief Busca de frases mitjançant paraules

      \pre paraules es una string de paraules
      \post mostra les frases que contenen les paraules consecutives
  */
	void busqueda_par(string paraules); 
	
	/** @brief Mostrar la frase i-essima

      \pre 0 <= i < mida del text
      \post retorna la i-essima frase del text
  */
	string mostra_frase(int i);
	
	/** @brief Imprimir taula de freqüencies

      \pre cert
      \post s'ha escrit el contingut de la taula de freqüencies pel canal estandard de sortida
  */
	void imprimir_taula_frec();	
	/** @brief Busca paraules en un text

      \pre paraules, autor i titol no buits
      \post retorna true si el text conté totes les paraules
  */
	bool busqueda_par_tot(string paraules, string autor, string titol);
	/** @brief Substitueix tot p1 per p2 del text

      \pre p1,p2 no buit
      \post substitueix p1 per p2 a tot vector t i actualitza la taula de freqüencies
  */
	void substituir_par(string p1, string p2);
private:
	void i_busqueda_par_express(string e, int &p, vector<bool> &v);
	void afegir_paraula_taula(vector<taulafreq> &tau, string par);
	vector<taulafreq> taula; //taula de frequencies;
	vector<string> t;
	int npar;
};

#endif


