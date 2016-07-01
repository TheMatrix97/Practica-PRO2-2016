/** @file GestorTextos.hh
    @brief Especificació de la classe GestorTextos
*/
#ifndef _GestorTextos_HH_
#define _GestorTextos_HH_

#include "text.hh"
#include "GestorCites.hh"



/** @class GestorTextos
    @brief Representa el gestor de textos
	conté els textos ordenats per autor i títol
*/

class GestorTextos{
public: 
	
	//Constructores
/** @brief Creadora

  Permet declarar un contenidor de textos nou.
  \pre <em>cert</em>
  \post El resultat es un contenidor buit.
*/ 
	GestorTextos();
	
	//Modificadores
	  /** @brief Afegir text

      Permet afegir un text nou al gestor de textos
      \pre parametres no buits, el text no existeix al gestor
      \post afegeix un text al gestor de textos
  */ 
	void afegir_text(string autor, string titol, text contingut);
	
	  /** @brief Eliminar text

      Permet eliminar un text del gestor.
      \pre tenim un text seleccionat
      \post s'elimina el text del gestor
  */ 
	void eliminar_text();
	
	  /** @brief Substituir paraules

      Permet substituir la paraula p1 del text per la p2
      \pre tenim un text seleccionat
      \post tot string p1 es substituit per p2
  */ 
	void substitueix(string p1, string p2);
	
	  /** @brief Elegir text

	  Permet escollir un text del gestor mitjançant una o més paraules
      \pre paraules no buides, gestor inicialitzat
      \post obtenim la direcció del text seleccionat, boolea de text triar = true
  */ 
	void triar_text(string paraules);

	//Consultores
	  /** @brief Consultora dels titols dels autors

      Imprimeix els titols escrits per un autor
      \pre autor té com a mínim un titol al gestor
      \post imprimeix els titols escrits pel autor
  */ 
	void consultar_titols_autor(string autor);
	 
	  /** @brief Consultar tots els textos

      Mostra tots els textos enmagatzemats al sistema
      \pre cert
      \post imprimeix tots els textos(titol, autor) ordenats per autor i despres per titol
  */ 
	void mostrar_tots_textos();
	 
	  /** @brief Mostrar tots els autors

      Mostra tots els autors amb textos en el sistema indicant per a cadascun el nombre de textos que hi consten, el nombre total de frases i de paraules del contingut dels seus textos
      \pre tenemos un texto seleccionado
      \post imprimeix els autors + (text = (nparaules_text + frases_text))
  */ 
	void mostrar_tots_autors();
	 
	  /** @brief Mostra informació del text seleccionat

      Imprimeix autor, titol, nombre de frases, nombre de paraules i cites associades al text seleccionat
      \pre text seleccionat 
      \post imprimeix informació del text seleccionat
  */ 
	void info(GestorCites& a);
	
	  /** @brief Consultar autor del text seleccionat

      Imprimeix el autor del text seleccionat
      \pre text seleccionat
      \post imprimeix el autor del text seleccionat
  */ 
	void autor();

		  /** @brief Consultar el contingut del text seleccionat

      Imprimeix el contingut del text seleccionat
      \pre text seleccionat
      \post imprimeix el contingut del text seleccionat
  */ 
	void mostrar_contingut();

	  /** @brief Consultar frases x-y del text seleccionat

      Imprimeix les frases desde x fins a y del text seleccionat
      \pre text seleccionat i 1 <= x <= y <= frases totals del text seleccionat
      \post imprimeix frases dins del interval [x,y]
  */ 
	void mostrar_xy_frases(int x, int y);
	
	  /** @brief Consultar el nombre de frases del text seleccionat

      \pre text seleccionat 
      \post s'ha escrit pel canal estandard de sortida el nombre de frases del text seleccionat
  */ 
	void nombre_frases();
	
	  /** @brief Consultar el nombre de paraules del text seleccionat

      \pre text seleccionat
      \post s'ha escrit pel canal estandard de sortida el nombre de paraules del text seleccionat
  */ 
	void nombre_paraules();
	
		  /** @brief Consultar taula de freqüencies del text seleccionat

      \pre text seleccionat 
      \post s'ha escrit pel canal estandard de sortida la taula de freqüencies del text seleccionat
  */ 
	void taula_frequencies();
	  
	  /** @brief Mostra les frases d'un text seleccionat donada una expressio o una llista de paraules

      El gestor desxifra si es tracta d'una llista de paraules o una expressio booleana
      i crida al text per a que imprimeixi les frases que es requereixen
      \pre text seleccionat
      \post s'han escrit pel canal de sortida les frases que contenen les paraules
      o compleixen l'expressio
  */ 
	void frases(string ordre);

	  /** @brief Afegir cita

	  Crida al gestor de cites i li envia un text que cal citar
      \pre x <= y, text seleccionat
      \post s'ha afegit la cita al GestorCites
  */ 
	void afegeix_cita_text(int x, int y, GestorCites &cites);
	
	  /** @brief Retorna el autorseleccionat

	  Retorna l'autor i el titol text del text seleccionat
      \pre text seleccionat
      \post autor = autorsel i text = titolsel;
  */ 
	bool mostrar_text_autorsel(string &autor,string &text);
	

private:
	map<string, map<string,text> > container; //mapa idexat per string(autor), conté un vector amb tots els textos i titol;
	bool valid;
	string autorsel;
	string titolsel;
};

#endif
