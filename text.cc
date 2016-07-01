#include <sstream>
#include <iostream>
#include "text.hh"
#include <algorithm>
using namespace std;
text::text(){
	npar = 0;

}

bool mifunc(taulafreq a, taulafreq b){
	if(a.freq == b.freq){
		if (a.paraula.length() == b.paraula.length()){
			return a.paraula < b.paraula;
		} else return a.paraula.length() < b.paraula.length();
	} else{
		return a.freq > b.freq;
	}
}

void text::llegir(){
	string s, s2, a;
	while(getline(cin,s) and s != "****"){
		istringstream iss(s);
		while(iss >> a){
			if (a[a.size() - 1] == '.' or a[a.size() - 1] == '?' or a[a.size() - 1] == '!'){
				s2.insert(s2.size(), a);
				t.push_back(s2);
				s2 = "";
				a.erase(a.end() - 1);
				if (not a.empty()){
					afegir_paraula_taula(taula,a);
					npar++;
				}
			}else {
				s2.insert(s2.size(), a + " ");
				if (a[a.size() - 1] == ',' or a[a.size() - 1] == ';' or a[a.size() - 1] == ':') a.erase(a.end() - 1);
				afegir_paraula_taula(taula,a);
				npar++;
			}
		}
	}
	sort(taula.begin(),taula.end(),mifunc);
}

int text::consul_num_paraules(){
	return npar;
}

int text::consul_frases(){
	return t.size();
}

bool esta_a_la_frase(string frase, string par){
	istringstream iss(frase);
	string s;
	while (iss >> s){
		if (s[s.size() - 1] == ',' or s[s.size() - 1] == ';' or s[s.size() - 1] == ':' or  s[s.size() - 1] == '.' or s[s.size() - 1] == '?' or s[s.size() - 1] == '!')
			s.erase(s.end()-1);
		if (s == par) return true;
	} return false;
}

void text::i_busqueda_par_express(string e, int &p, vector<bool>& v){
	int n = t.size();
	if (e[p] == '{'){
		++p;
		int lon1 = e.size() - p;
		string s1 = e.substr(p,lon1);
		istringstream iss(s1);
		string lpar, par;
		getline(iss,lpar,'}');
		p += lpar.size();
		istringstream iss2(lpar);
		while(iss2 >> par){
			for(int i = 0; i < n; ++i){
				if(v[i]){
					v[i] = esta_a_la_frase(t[i],par);
				}
			}
		}
	} else{
		vector<bool> op1(n,true);
		vector<bool> op2(n,true);
		++p;
		string exp = e;
		i_busqueda_par_express(exp,p,op1);
		while(e[p] != '|' and e[p] != '&'){
			++p;
		}
		char c = e[p];
		while(e[p] != '{' and e[p] != '('){
			++p;
		}
		i_busqueda_par_express(exp,p,op2);
		++p;
		if(c == '&') {
			for(int i = 0; i < n; ++i){
				v[i] = op1[i] and op2[i];
			}
		} else {
			for(int i = 0; i < n; ++i){
				v[i] = op1[i] or op2[i];
			}
		}
	}
}

void text::busqueda_par_express(string expr){
	int n = t.size();
	string exp = expr;
	int p = 0;
	vector<bool> v(n,true);
	i_busqueda_par_express(exp, p,v);
	for (int i = 0; i < n; ++i){
		if (v[i]) cout << i + 1 << " " << t[i] << endl;
	}
}

void text::busqueda_par(string paraules){
	for (int k = 0; k < t.size(); ++k){
		istringstream iss(paraules);
		istringstream isstext (t[k]);
		bool f = false;
		string s, scopia;
		iss >> s;
		vector<string> vpar;
		vector<string> vtext;
		while(iss >> scopia) vpar.push_back(scopia);
		while(isstext >> scopia) vtext.push_back(scopia);
		int i = 0;
		while(not f and i < vtext.size()){
			if (vtext[i][vtext[i].size() - 1] == ',' or vtext[i][vtext[i].size() - 1] == ';' or vtext[i][vtext[i].size() - 1] == ':' or  vtext[i][vtext[i].size() - 1] == '.' or vtext[i][vtext[i].size() - 1] == '?' or vtext[i][vtext[i].size() - 1] == '!')
                vtext[i].pop_back();
			if (s == vtext[i]){
				int j = 1;
				int count = 0;
				while(count == j - 1 and j - 1 < vpar.size() and i + j < vtext.size()){
					if (vtext[i+j][vtext[i+j].size() - 1] == ',' or vtext[i+j][vtext[i+j].size() - 1] == ';' or vtext[i+j][vtext[i+j].size() - 1] == ':' or  vtext[i+j][vtext[i+j].size() - 1] == '.' or vtext[i+j][vtext[i+j].size() - 1] == '?' or vtext[i+j][vtext[i+j].size() - 1] == '!')
                        vtext[i+j].pop_back();
					if (vpar[j-1] == vtext[j+i]) ++count;
					++j;
				}
				if (count == vpar.size()) f = true;
			}
			++i;
		}
		if (f) cout << k + 1 << " " << t[k] << endl;
	}
}

string text::mostra_frase(int i){
	return t[i];
}

void text::imprimir_taula_frec(){
	for (int i = 0; i < taula.size(); ++i){
		cout << taula[i].paraula << ' ' << taula[i].freq << endl;
	}	
}

void convierte_string_vect(string a, vector<string> &b){
	istringstream iss(a);
	string c;
	vector<string> aux(b.size());
	while(iss >> c){
		if(c[c.size() - 1] == ',' or c[c.size() - 1] == ';' or  c[c.size() - 1] == ':' or c[c.size() - 1] == '.' or c[c.size() - 1] == '?' or c[c.size() - 1] == '!') c.pop_back();
		aux.push_back(c);
	}
	b = aux;
}

bool text::busqueda_par_tot(string sparaules, string stitol ,string sautor){
	bool found = false;
	int contador = 0;
	vector<string> paraules, autor, titol;
	string aux;
	convierte_string_vect(sparaules, paraules);
	convierte_string_vect(stitol, titol);
	convierte_string_vect(sautor, autor);
	
	for(int i = 0; i < paraules.size(); i++){
		for(int j = 0; j < taula.size() and not found; j++){
			if(paraules[i] == taula[j].paraula){
				contador++;
				found = true;
			}
		}
		if(not found){
			for(int k = 0; k < autor.size() and not found; k++){
				if(paraules[i] == autor[k]){
					found = true;
					contador++;
					}
				}

			for(int p = 0; p < titol.size() and not found; p++){
				if(paraules[i] == titol[p]){
					found = true;
					contador++;
				}
			}
		}
		found = false;
	}
	if(paraules.size() == contador) return true;
	else return false;
}

void text::substituir_par(string p1, string p2){
	size_t found;
	bool f = false;
	for(int i = 0; i < t.size(); i++){
		found = 0;
		istringstream iss(t[i]);
		string stext;
		while(iss >> stext and found < t[i].size()){
			bool e = false;
			if (stext[stext.size() - 1] == ',' or stext[stext.size() - 1] == ';' or stext[stext.size() - 1] == ':' or  stext[stext.size() - 1] == '.' or stext[stext.size() - 1] == '?' or stext[stext.size() - 1] == '!'){
				e = true;
				stext.erase(stext.end()-1);
			}
			if (stext == p1){
				t[i].replace(found,p1.size(),p2);
				found += p2.size() + 1;
				f = true;
			}else {
				found += stext.size() + 1;
			}
				if (e) ++found;
		}
	}
	if (f){
		int i = 0, num = 0;
		bool p1f = false, p2f = false;
		while(i < taula.size() and (not p1f or not p2f)){
			if(taula[i].paraula == p1){
				num += taula[i].freq;
				taula.erase(taula.begin() + i);
				--i;
				p1f = true;
			}
			else if (taula[i].paraula == p2){
				num += taula[i].freq;
				taula.erase(taula.begin() + i);
				p2f = true;
				--i;
			}
			++i;
		}
		taulafreq n;
		n.paraula = p2;
		n.freq = num;
		bool g = false;
		i = 0;
		while(i < taula.size() and not g){
			if (num > taula[i].freq) {
				taula.insert(taula.begin() + i,n);
				g = true;
			}else if (num == taula[i].freq){
				if (p2.length() < taula[i].paraula.length()) {
					taula.insert(taula.begin() + i,n);
					g = true;
				}else if (p2.length() == taula[i].paraula.length()){
					if (p2 < taula[i].paraula) {
						taula.insert(taula.begin() + i,n);
						g = true;
					}
				}
			}
		++i;
		}
		if (not g) taula.push_back(n);		
	}
}

void text::afegir_paraula_taula(vector<taulafreq> &tau, string par){
	bool found = false;
	int i = 0;
	while(i < tau.size() and not found){
		if(tau[i].paraula == par){
			 ++tau[i].freq;
			 found = true;
		 }
		 ++i;
	}
	if(not found){
		taulafreq n;
		n.paraula = par;
		n.freq = 1;
		tau.push_back(n);
	}
}
