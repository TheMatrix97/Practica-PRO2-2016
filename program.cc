/**
 * @mainpage Practica de lab, gestio de textos i cites
 
	Practica de PRO2 que consisteix en la creacio d'un <em>Gestor de textos i cites</em>.
	* S'utilitzen les clases GestorCites i GestorTextos per emmagatzemar els textos escrits per autors i cites als ja mencionats textos
	* el program.cc conte el tractament de comandes d'entrada i les crides a les diferents funcions de GestorTextos i GestorCites
	* 
*/

/** @file program.cc
    @brief Programa principal de la practica <em>Gestió de textos y cites</em>.
    comentaris. Aquest programa nomes gestiona les crides principals als 2 gestors, no s'encarrega de gestionar els errors, aquests són gestionats per les clases
*/

#include "GestorTextos.hh"
#include "GestorCites.hh"

int main(){
	GestorTextos gest_textos;
	GestorCites gest_cites;
	string comanda;
while(getline(cin,comanda) and comanda != "sortir"){
		cout << comanda << endl;
		istringstream iss(comanda);
		string operacio;
		iss >> operacio;
		if(operacio == "afegir"){
			string objecte;
			iss >> objecte;
			if(objecte  == "text"){
				int size = comanda.size();
				string titol = comanda.substr(13,size - 1 - 13);
				string autor, autor_line;
				getline(cin, autor_line);
				istringstream iss2(autor_line);
				string comanda_autor;
				iss2 >> comanda_autor;
				if(comanda_autor == "autor"){
					string autor = autor_line.substr(7,autor_line.size() - 2 - 6);
					text cont;
					cont.llegir();
					gest_textos.afegir_text(autor,titol,cont);
				}else{
					string basura;
					while(getline(cin, basura) and basura != "****");
				}
			}
			else if(objecte == "cita"){
                int x, y;
				iss >> x;
				iss >> y;
                gest_textos.afegeix_cita_text(x,y,gest_cites);
			}
		}	
		else if(operacio == "triar"){ 
			string objecte;
			iss >> objecte;
			if(objecte == "text"){
				string paraules = comanda.substr(12, comanda.size() - 1 - 12);
				gest_textos.triar_text(paraules);
			}
		}
		else if(operacio == "eliminar"){
			string objecte;
			iss >> objecte;
			if(objecte == "text") gest_textos.eliminar_text();
			else if(objecte == "cita"){
				string ref;
				iss >> ref;
				ref.erase(ref.begin());
				ref.erase(ref.size() - 1);
				gest_cites.eliminar_cita(ref);
			}
		}
		else if(operacio == "substitueix"){
			string par1,per,par2;
			iss >> par1;
			iss >> per;
			iss >> par2;
			if(per == "per" and not par1.empty() and not par2.empty()){
				par1.erase(par1.begin());
				par2.erase(par2.begin());
				par1.erase(par1.end() - 1);
				par2.erase(par2.end() - 1);
				gest_textos.substitueix(par1,par2);
			}
			
		}
		//consultores
		else if(operacio == "textos"){
			string objecte;
			iss >> objecte;
			if(objecte == "autor"){
				string autor = comanda.substr(14,comanda.size() - 3 - 14);
				gest_textos.consultar_titols_autor(autor);
			}
		}
		else if(operacio == "tots" and comanda[comanda.size() - 1] == '?'){
			string objecte;
			iss >> objecte;
			if(objecte == "textos"){ //mostra tots els textos del sistema
				gest_textos.mostrar_tots_textos();
			}
			else if(objecte == "autors"){//instruccio mostrar tots els autors amb textos
				gest_textos.mostrar_tots_autors();
			}
			
		}
		else if(operacio == "info" and comanda[comanda.size() - 1] == '?'){ //mostrar info text sel
			string objecte;
			iss >> objecte;
			if(objecte == "cita"){
				string referencia = comanda.substr(11,comanda.size() - 3 - 11);
				gest_cites.info_cita(referencia);
			}
			else gest_textos.info(gest_cites);//info del text seleccionat
		}
		else if(operacio == "autor" and comanda[comanda.size() - 1] == '?'){
			gest_textos.autor();
			} //mostrar autor text sel
		else if(operacio == "contingut" and comanda[comanda.size() - 1] == '?'){
			gest_textos.mostrar_contingut();
			} //mostra contingut text sel
		else if(operacio == "frases" and comanda[comanda.size() - 1] == '?'){
            if(comanda[7] == '(' or comanda[7] == '{'){ //expressio;
				string expressio = comanda.substr(7,comanda.size() - 9);
				gest_textos.frases(expressio);
			}
			else if(comanda[7] == '"'){
				string par = comanda.substr(8,comanda.size() - 11);
				gest_textos.frases(par);
				//crida frases pasant les paraules
			}
            else {
                int x, y;
				iss >> x;
                iss >> y;
                gest_textos.mostrar_xy_frases(x,y);
			}
		}
		else if(operacio == "cites" and comanda[comanda.size() - 1] == '?'){
			string objecte;
			iss >> objecte;
			if(objecte == "autor"){
				string par = comanda.substr(13,comanda.size()- 3 - 13);
				gest_cites.mostrar_cites_autor(par);
			}
			else{
				string titol, autor;
				bool v = gest_textos.mostrar_text_autorsel(autor,titol);
				if(v){
					if (gest_cites.mostrar_cites_text(autor, titol))
						cout << autor << ' ' << '"' << titol << '"' << endl;
				}else cout << "error" << endl;
				
				//mostra cites text triat
			}
		}
		else if(operacio == "totes" and comanda[comanda.size() - 1] == '?'){
			string objecte;
			iss >> objecte;
            if(objecte == "cites") gest_cites.mostrar_totes_cites(); //mostrar totes les cites
		}
		else if(comanda == "nombre de frases ?") gest_textos.nombre_frases();
		else if(comanda == "nombre de paraules ?") gest_textos.nombre_paraules();
		else if(comanda == "taula de frequencies ?") gest_textos.taula_frequencies();
	}
}
		 

