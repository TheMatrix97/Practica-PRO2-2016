/** @file cita.hh
    @brief Especificacio de la classe cita 
*/

#ifndef _CITA_HH_
#define _CITA_HH_

#include "text.hh"



/** @class cita
    @brief Representa una cita de les frases d'un text
*/

class cita{
	public:
	//Constructores
	/** @brief Creadora per defecte

      crea una cita buida 
      \pre cert
      \post genera una cita buida
  */
		cita();
	
	//Modificadores
	/** @brief Es modifiquen els parametres de la cita

      \pre El parametre implicit es una cita buida
      \post es fa la cita sobre el text t, entre les linies x i y, i es guarda l'autor i el titol
  */
		bool afegir_cita(text t,int x, int y, string autor, string titol);
		
	//Consultores
	/** @brief Consultar l'autor de la cita 
     
      \pre cita no buida
      \post retorna l'autor del text citat
  */
		string mostrar_titol();
		
	/** @brief Consultar el titol de la cita 
     
      \pre cita no buida
      \post retorna el titol del text citat
  */
		string mostrar_autor();
		
	/** @brief Imprimir contingut de la cita 
     
      \pre cita no buida
      \post escriu el contingut de la cita pel canal estandard de sortida
  */
		void imprimir_contingut();
	/** @brief consultora inici i final cita al text original
     
      \pre parametres privats de la clase x i y no buits
      \post ix = x & iy = y
  */
		void retorna_x_y(int &ix, int &iy);
	/** @brief Imprimir pel canal de sortida l'autor i el titol de la cita
     
      \pre cita conte els parametres autor i titol no buits
      \post imprimeix l'autor i el titol de la cita
  */
		void imprimir_autor_titol();

private:
	vector<string>contingut;
	int x, y;
	string autor;
	string titol;
};
#endif
	
	
