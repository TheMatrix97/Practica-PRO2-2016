/** @file GestorCites.hh
    @brief Especificació de la classe GestorCites
*/
#ifndef _GESTORCITES_HH_
#define _GESTORCITES_HH_

#include "text.hh"
#include "cita.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#endif

/** @class GestorCites
    @brief Representa el gestor de cites
	conté les cites associades als diferents textos
*/

class GestorCites{
public: 
	
	//Constructores
/** @brief Creadora

  Permet declarar un contenidor de cites nou.
  \pre <em>cert</em>
  \post El resultat es un contenidor buit.
*/ 
	GestorCites();
	
	
	//Modificadores
	/** @brief Afegir cita

      Permet afegir una cita al gestor de cites.
      \pre GestorTextos ens envia un text, i dos nombres tal que 1 <= x <= y <= num. frases
      \post s'ha afegit la cita en el paràmetre implícit
  */ 
	void afegir_cita(int x, int y, text t, string autor, string titol);
	
	//Consultores
	  /** @brief Mostra totes les cites del autor seleccionat

      Imprimeix les cites del autor a escollir
      \pre autor no esta buit
      \post imprimeix cites de l'autor
  */ 
	void mostrar_cites_autor(string autor);
	  
	  /** @brief Mostra les cites amb titol i autor rebuts.

      GestorTextos té un text seleccionat i ens envia el titol i l'autor
      \pre autor i titol no estan buits
      \post s'ha escrit pel canal estandard de sortida el contingut de les frases
      de les cites, ordenades per referencia
  */ 

	bool mostrar_cites_text(string autor, string titol);
	  
	  /** @brief Mostra totes les cites del sistema

      Imprimeix totes les cites del sistema
      \pre cert
      \post imprimeix totes les cites, retorna false en cas que no imprimeixi res 
  */ 
	void mostrar_totes_cites();
	  
	  /** @brief Elimina la cita que conté la referencia desitjada
		
	  Elimina la cita desitjada del sistema
      \pre ref no es buit
      \post elimina la cita referencia = ref, 
      si ref no existeix escriu "error"
  */
	void eliminar_cita(string ref);
	
	/** @brief Mostra informacio sobre un cita		

      \pre ref no es buit
      \post s'ha escrit pel canal de sortida tota la informacio que conte
      la cita (frases, titol, autor, etc), si ref no existeix esctiu "error"
  */
	void info_cita(string ref);

private:
    vector<string> referencies;
	map<string,cita> cites;//map cites indexat referencia
};

#endif
