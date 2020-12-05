#include "guiatlf.h"

using namespace std;

//typedef typename map<string, string>::iterator iterator;
//typedef typename map<string, string>::const_iterator const_iterator;

string & Guia_Tlf::operator[](const string &nombre) {
    return datos[nombre];
}

string Guia_Tlf::gettelefono(const string & nombre) {
    iterator it = datos.find(nombre);
    if (it == datos.end())
        return string("");
    else return it->second;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(string nombre, string tlf) {
    pair<string, string> p(nombre, tlf);
    pair <iterator, bool> ret;

    ret = datos.insert(p);
    return ret;

}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(pair<string, string> p) {

    pair <iterator, bool> ret;

    ret = datos.insert(p);
    return ret;

}

void Guia_Tlf::borrar(const string &nombre) {
    iterator itlow = datos.lower_bound(nombre); //el primero que tiene dicho nombre
    iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
    datos.erase(itlow, itupper); //borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre, const string &tlf) {
    iterator itlow = datos.lower_bound(nombre); //el primero que tiene dicho nombre
    iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
    iterator it;
    bool salir = false;
    for (it = itlow; it != itupper && !salir; ++it) {
        if (it->second == tlf) {
            datos.erase(it);
            salir = true;
        }
    }

}

int Guia_Tlf::size()const {
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre) {
    return datos.count(nombre);
}

void Guia_Tlf::clear() {
    datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g) {
    Guia_Tlf aux(*this);
    const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it) {
        aux.insert(it->first, it->second);
    }
    return aux;

}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g) {
    Guia_Tlf aux(*this);
    const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it) {
        aux.borrar(it->first, it->second);
    }
    return aux;

}

ostream & operator<<(ostream & os, Guia_Tlf & g) {
        map<string, string>::iterator it;
        for (it = g.datos.begin(); it != g.datos.end(); ++it) {
            os << it->first << "\t" << it->second << endl;
        }
        return os;
    }

istream & operator>>(istream & is, Guia_Tlf & g) {
        pair<string, string> p;
        Guia_Tlf aux;

        while (is >> p) {
            aux.insert(p);
        }
        g = aux;
        return is;
    }

istream & operator>>(istream &is, pair<string, string> &d) {

    getline(is, d.first, '\t');
    getline(is, d.second);
    return is;
}

// --------------------------- FUNCIONES AÑADIDAS --------------------------- //
    
 void Guia_Tlf::imprimirPagina(char letra){
     iterator it;
     bool out = false;                                                          // Para que no tengamos que recorrer el bucle entero
     pair<string,string> p;
     
     if(islower(letra))
         letra = toupper(letra);
     
     cout << "\nPágina " << letra << ":" << endl;
     
     for(it = datos.begin(); it != datos.end() && !out ; it++){
         p = (*it);                                                             // Obtenemos un nombre y su número
         if(letra == p.first.at(0)){                                            // Si la primera letra coincide, lo sacamos por pantalla
             cout << p.first << "\t" << p.second << endl;
         } else if (letra < p.first.at(0))                                      // Si nos hemos pasado de letra, para el bucle
             out = true;
     }
 }
 
 void Guia_Tlf::imprimirPersona(const string nombre){
            pair<iterator,bool> search = buscar(nombre);
            iterator it = search.first;
            
            if(search.second)
                cout << (*it).first << "\t" << (*it).second << endl;
            else
                cout << "\nNo existe ninguna persona llamada " << nombre << " en la guia." << endl;
 }
    
 pair<map<string,string>::iterator, bool> Guia_Tlf::buscar(const string nombre){
     pair<iterator,bool> p;
     
     if(contabiliza(nombre) != 0){
         p.first = datos.find(nombre);
         p.second = true;
     } else{
         p.first = datos.end();
         p.second = false;
     }
         
        return p;
 }
    