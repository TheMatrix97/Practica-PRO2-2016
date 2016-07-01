#include "GestorCites.hh"
using namespace std;

GestorCites::GestorCites(){

}


void crear_referencia(string &ref, string autor, int num){ 
	istringstream iss(autor);
	string b,a;
	while(iss >> a){
		b.push_back(a[0]);
	}
	string c = std::to_string(num);
	b = b + c;
	ref = b;
}
string inicials(string autor){
	istringstream iss(autor);
	string b,a;
	while(iss >> a){
		b.push_back(a[0]);
	}
	return b;
}

void GestorCites::afegir_cita(int x, int y, text t, string autor, string titol){
	cita c;
	bool cont = c.afegir_cita(t,x,y,autor,titol);
	string b;
	b = inicials(autor);
	if(cont){
		map<string, cita>::iterator it;
		int i = 0;
		int contador = 1;
		bool found = false;
		while(i < referencies.size() and not found){
			string aux = referencies[i];
			aux.pop_back();
			if(aux == b){
				contador++;
				it = cites.find(referencies[i]);
				if(it != cites.end()){
					int ix,iy;
					it->second.retorna_x_y(ix,iy);
					found = (ix == x) and (iy == y) and (it->second.mostrar_autor() == autor) and (it->second.mostrar_titol() == titol);
				}
			}
			i++;
		}
		if(found) cout << "error" << endl;
		else{
			string ref;
			crear_referencia(ref,autor,contador);
			referencies.push_back(ref);
			cites.insert(make_pair(ref,c));
		}
	}else cout << "error" << endl;
}

void GestorCites::mostrar_cites_autor(string autor){
	map<string, cita>::iterator it;
	string ini = inicials(autor);
	char comillas = '"';
	for(it = cites.begin(); it != cites.end(); it++){
		string aux = it->first;
		aux.pop_back();
		if(aux == ini and it->second.mostrar_autor() == autor){
			cout << it->first << endl;
			it->second.imprimir_contingut();
			cout << comillas << it->second.mostrar_titol() << comillas << endl;
		}
	}
	
}

bool GestorCites::mostrar_cites_text(string autor, string titol){
	map<string, cita>::iterator it = cites.begin();
	string ref;
	bool b = false;
	for(it = cites.begin(); it != cites.end(); it++){
		if(it->second.mostrar_autor() == autor and it->second.mostrar_titol() == titol){
			cout << it->first << endl;
			it->second.imprimir_contingut();
			b = true;
		}
	}
	return b;
	
}

void GestorCites::mostrar_totes_cites(){
	map<string,cita>::iterator it;
	for(it = cites.begin(); it != cites.end(); it++){
		cout << it->first << endl;
		it->second.imprimir_contingut();
		it->second.imprimir_autor_titol();
	}
}

void GestorCites::eliminar_cita(string ref){
	map<string,cita>::iterator it;
	it = cites.find(ref);
	if(it != cites.end()){
		cites.erase(it);
	}else cout << "error" << endl;
}

void GestorCites::info_cita(string ref){
	map<string,cita>::iterator  it;
	it = cites.find(ref);
	char comillas = '"';
	if(it != cites.end()){
		int x, y;
		cites[ref].retorna_x_y(x,y);
		cout << cites[ref].mostrar_autor() << ' ' << comillas << cites[ref].mostrar_titol() << comillas << endl;
		cout << x << '-' << y << endl;
		cites[ref].imprimir_contingut();
	}else cout << "error" << endl;
}
