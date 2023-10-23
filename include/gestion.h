#ifndef __GESTION_H__
#define __GESTION_H__

#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define nombre_archivo "../data/database.csv"

class Gestion {
private:
  int cantidadTotal;
  int cantidadTotalDif;
  char separador;
  std::unordered_map<std::string, std::vector<std::string>> mapaProdutos;

public:
  Gestion(char);
  ~Gestion();
  void leerArchivo();
  void total_art();
  void total_art_dif();
};

// Revisar mas tarde
Gestion::Gestion(char _separador) : separador(_separador) {}

/*
 * Destructor
 */
Gestion::~Gestion() {}

/*
 * Lee el archivo y lo guarda en un mapa
 * @param separador caracter que separa las columnas
 */
void Gestion::leerArchivo() {
  std::ifstream archivo(nombre_archivo);
  std::string celda, linea;
  std::string tmp;
  std::vector<std::string> propiedadesProducto;

  try {
    if (!archivo.is_open()) {
      throw 404;
    }
  } catch (int e) {
    std::cout << "Error " << e << ": No se pudo abrir el archivo" << std::endl;
  }

  unsigned int celda_actual;

  std::getline(archivo, linea);

  while (std::getline(archivo, linea)) {
    std::stringstream s(linea);
    celda_actual = 0;
    while (std::getline(s, celda, separador)) {
      if (!celda.empty() && celda_actual >= 1) {
        if (celda_actual == 1) {
          tmp = celda;
        } else {
          propiedadesProducto.push_back(celda);
          mapaProdutos[tmp] = propiedadesProducto;
        }
      }
      celda_actual++;
    }
    std::cout << std::endl;
  }
}

/*
 * Calcula la cantidad total de articulos
 */
void total_art() {}

#endif // __GESTION_H__