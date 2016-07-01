#include "GestorTextos.hh"
#include <map>
using namespace std;

GestorTextos::GestorTextos(){
	valid = false;
}
void GestorTextos::afegir_text(string autor, string titol, text contingut){
	map<string, map<string, text> >::iterator it = container.begin();
	it = container.find(autor);
	if(it != container.end()){
		map<string, text>::iterator it2;
		it2 = it->second.find(titol);
		if(it2 == it->second.end()){
			it->second.insert(make_pair(titol,contingut));
		}else cout << "error" << endl;

	}else{
		map<string,text> h;
		h.insert(make_pair(titol,contingut));
		container.insert(make_pair(autor,h));
		}
}

void GestorTextos::triar_text(string paraules){
	map<string, map<string, text> >::iterator it;
	map<string, text>::iterator it2;
	bool found = false;
	bool stop = false;
	for(it = container.begin(); it != container.end() and not stop; ++it){
		for(it2 = it->second.begin(); it2 != it->second.end() and not stop; ++it2){
			if(not found and (it2->second.busqueda_par_tot(paraules,it->first,it2->first))){
				autorsel = it->first;
				titolsel = it2->first;
				found = true;
				valid = true;
			}
			else if(found and (it2->second.busqueda_par_tot(paraules,it->first,it2->first))) stop = true; //hi han 2 textos que cumpleixen la cond, fin y sel = error
			 //busqueda par retorna true si estan totes les paraules al text
			
		}
	}
	if((stop or not found)){
		cout << "error" << endl;
		valid = false;
	}

}

void GestorTextos::eliminar_text(){ //eliminem de l'autor el titol seleccionat
	if(not valid){
		cout << "error" << endl;
	}else{
		container[autorsel].erase(titolsel);
		valid = false;
	}
}
void GestorTextos::substitueix(string p1, string p2){
	if(not valid){
		cout << "error" << endl;
	}else{
		container[autorsel][titolsel].substituir_par(p1,p2);
	}
}

void GestorTextos::consultar_titols_autor(string autor){
	map<string, map<string, text> >::iterator i = container.find(autor);
	if (i != container.end()){
		map<string, text>::iterator it2;
		for(it2 = i->second.begin(); it2 != i->second.end(); ++it2){
			string titol = it2->first;
			char comillas = '"';
			cout << comillas << titol << comillas << endl;
		}
	}
}

void GestorTextos::mostrar_tots_textos(){
	map<string, map<string, text> >::iterator it;
	map<string, text>::iterator it2;
	char comillas = '"';
	for(it = container.begin(); it != container.end(); it++){
		for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
			cout << it->first << ' ' << comillas << it2->first << comillas << endl;
		}
	}
}
void GestorTextos::mostrar_tots_autors(){
	map<string, map<string, text> >::iterator it;
	map<string, text>::iterator it2;
	int contador_text = 0;
	int contador_frases = 0;
	int contador_paraules  = 0;
	if(not container.empty()){
		for(it = container.begin(); it != container.end(); it++){
			if(not it->second.empty()){
				for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
					contador_text++;
					contador_frases += it2->second.consul_frases();
					contador_paraules += it2->second.consul_num_paraules();
				}
				cout << it->first << ' ' << contador_text << ' ' << contador_frases << ' ' << contador_paraules << endl;			
			}
			contador_text = 0;
			contador_frases = 0;
			contador_paraules = 0;
		}
	}
}
	
void GestorTextos::info(GestorCites& a){
	if(not valid) cout << "error" << endl;
	else{
		int frases = container[autorsel][titolsel].consul_frases();
		int numpar = container[autorsel][titolsel].consul_num_paraules();
		char comillas = '"';
		cout << autorsel << ' ' << comillas << titolsel << comillas << ' ' << frases << ' ' << numpar << endl;
		cout << "Cites Associades:" << endl;
		a.mostrar_cites_text(autorsel, titolsel);
	}
}
void GestorTextos::autor(){
	if(not valid) cout << "error" << endl;
	else cout << autorsel << endl;
}
void GestorTextos::mostrar_contingut(){
	if(not valid){
		cout << "error" << endl;
	}else{
		int frases = container[autorsel][titolsel].consul_frases();
		for(int i = 0; i < frases; i++){
			cout << i + 1 << ' ' << container[autorsel][titolsel].mostra_frase(i) << endl;
	}
}
}
void GestorTextos::mostrar_xy_frases(int x, int y){
	if(not valid){
		cout << "error" << endl;
	}else if (1 <= x and x<= y and y <= container[autorsel][titolsel].consul_frases()){
		for(int i = x; i <= y; i++)
			cout << i << ' ' << container[autorsel][titolsel].mostra_frase(i - 1) << endl;
	}else{
		cout << "error" << endl;
	}
}

void GestorTextos::nombre_frases(){
	if(not valid){
		cout << "error" << endl;
	}else{
		cout << container[autorsel][titolsel].consul_frases() << endl;
	}
}
void GestorTextos::nombre_paraules(){
	if(not valid){
		cout << "error" << endl;
	}else{
		cout << container[autorsel][titolsel].consul_num_paraules() << endl;
	}
}
void GestorTextos::taula_frequencies(){
	if(not valid){
		cout << "error" << endl;
	}else{
		container[autorsel][titolsel].imprimir_taula_frec();
	}
}
void GestorTextos::frases(string ordre){
	if(not valid){
		cout << "error" << endl;
	}else{
		if(ordre[0] == '(' or ordre[0] == '{') container[autorsel][titolsel].busqueda_par_express(ordre);
		else container[autorsel][titolsel].busqueda_par(ordre);
	}
}

void GestorTextos::afegeix_cita_text(int x, int y, GestorCites &cites){
	if(not valid){
		cout << "error" << endl;
	}else{
		cites.afegir_cita(x,y,container[autorsel][titolsel],autorsel,titolsel);
	}
}
bool GestorTextos::mostrar_text_autorsel(string &autor,string &t){
	if(valid){
		autor = autorsel;
		t = titolsel;
	}
	return valid;
}
