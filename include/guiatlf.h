#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>

using namespace std;

istream & operator>>(istream &is, pair<string, string> &d);

class Guia_Tlf {
private:
    map<string, string> datos; //si admites que haya nombres repetidos tendr�as que usar un
    //multimap

public:
    //Guia_Tlf(){}
    //Guia_Tlf(const Guia_Tlf & gt);
    //~Guia_Tlf(){}
    //Guia_Tlf & operator=(const Guia_Tlf & gt);
    
    typedef typename map<string, string>::iterator iterator;
    typedef typename map<string, string>::const_iterator const_iterator;

    /**
      @brief Acceso a un elemento
      @param nombre: nombre del elemento  elemento acceder
      @return devuelve el valor asociado a un nombre, es decir el teléfono
     */
    string & operator[](const string &nombre);

    /**
     * @brief Consultor del número de teléfono de una persona dada
     * @param nombre El nombre de la persona de la que se quiere el teléfono
     * @return tel El número de teléfono
     */
    string gettelefono(const string & nombre);

    /**
     @brief Insert un nuevo telefono 
     @param nombre: nombre clave del nuevo telefono
     @param tlf: numero de telefono
     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
     */
    pair<iterator, bool> insert(string nombre, string tlf);

    /**
     @brief Insert un nuevo telefono 
     @param p: pair con el nombre y el telefono asociado
		     
     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
     */
    pair<iterator, bool> insert(pair<string, string> p);

    /**
      @brief Borrar un telefono
      @param nombre: nombre que se quiere borrar
      @note: en caso de que fuese un multimap borraria todos con ese nombre
     */
    void borrar(const string &nombre);

    /**
      @brief Borrar un telefono
      @param nombre: nombre que se quiere borrar y telefono asociado
      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
     */
    //con map siempre hay uno con multimap puede existir mas de uno
    void borrar(const string &nombre, const string &tlf);

    /**
      @brief  Numero de telefonos 
      @return el numero de telefonos asociados
     */
    int size()const;

    /**
      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
      @param nombre: nombre sobre el que queremos consultar
      @return numero de telefonos asociados a un nombre
		      
     */
    //al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
    unsigned int contabiliza(const string &nombre);

    /**
      @brief Limpia la guia
     */
    void clear();
    /**
      @brief Union de guias de telefonos
      @param g: guia que se une
      @return: una nueva guia resultado de unir el objeto al que apunta this y g
     */
    Guia_Tlf operator+(const Guia_Tlf & g);

    /**
      @brief Diferencia de guias de telefonos
      @param g: guia que se une
      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
     */
    Guia_Tlf operator-(const Guia_Tlf & g);

    /**
      @brief Escritura de la guia de telefonos
      @param os: flujo de salida. Es MODIFICADO
      @param g: guia de telefonos que se escribe
      @return el flujo de salida
     */
    friend ostream & operator<<(ostream & os, Guia_Tlf & g);

    /**
      @brief Lectura de  la guia de telefonos
      @param is: flujo de entrada. ES MODIFICADO
      @param g: guia de telefonos. ES MODIFICADO
      @return el flujo de entrada
     */
    friend istream & operator>>(istream & is, Guia_Tlf & g);

// -------------------------------- ITERADORES ------------------------------- //
    
    /**
     * @brief Iterador constante
     * @return Iterador constante al inicio de datos
     */
    const_iterator cbegin() const{
        return datos.cbegin();
    }

    /**
     * @brief Iterador constante
     * @return Iterador constante al final de datos
     */
    const_iterator cend() const{
        return datos.cend();
    }

    /**
     * @brief Iterador 
     * @return Iterador al inicio de datos
     */
    iterator begin(){
        return datos.begin();
    }
    
    /**
     * @brief Iterador 
     * @return Iterador al final de datos
     */
    iterator end(){
        return datos.end();
    }

// --------------------------- FUNCIONES AÑADIDAS --------------------------- //
    /**
     * @biref Imprime por pantalla los números de aquellas personas cuyos nombres empiecen por la letra que se pasa por parámetro
     * @param letra Letra por la que deben comenzar los nombres que van a ser impresos
     */
    void imprimirPagina(char letra);
    
    /**
     * @biref Imprime por pantalla el números de la persona cuyo nombre coincida con el que se pasa por parámetro
     * @param nombre Nombre que queremos que se imprima por pantalla
     */
    void imprimirPersona(const string nombre);
    
    /**
     * @biref Busca un nombre en la guia y devuelve un iterador con su posición
     * @param nombre Nombre a buscar en la guia
     * @return @retval true si se ha encontrado el nombre y se devuelve un iterador al mismo o @retval false si no está
     */
    pair<map<string, string>::iterator, bool> buscar(const string nombre);
};
#endif

