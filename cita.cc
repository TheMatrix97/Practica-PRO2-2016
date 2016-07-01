#include "cita.hh"

cita::cita(){
	x = y = -1;
	autor = "error";
	titol = "error";
}

bool cita::afegir_cita(text t,int x, int y, string autor, string titol){
	this->autor = autor;
	this->titol = titol;
	this->x = x;
	this->y = y;
	if(y <= t.consul_frases() and 1 <= x and x <= y){
		for (int i = x - 1; i < y; ++i){
			contingut.push_back(t.mostra_frase(i));
		}
		return true;
	}else return false;
}

string cita::mostrar_titol(){
	return titol;
}

string cita::mostrar_autor(){
	return autor;
}

void cita::imprimir_contingut(){
	int a = x;
	for (int i = 0; i < contingut.size(); ++i){
		cout << a << " " << contingut[i] << endl;
		++a;
	}
}
void cita::retorna_x_y(int &ix, int &iy){
	ix = x;
	iy = y;
}
	
void cita::imprimir_autor_titol(){
	char comillas = '"';
	cout << autor << ' ' << comillas << titol << comillas << endl;
}
