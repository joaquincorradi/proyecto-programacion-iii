#ifndef __ARCHIVO_H__
#define __ARCHIVO_H__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../include/articulo.h"

class Archivo {
private:
  char separador;   // Separador de las celdas del archivo CSV
  std::string path; // Ruta del archivo CSV

  /* Mapa de artículos para rápido acceso (clave: nombre del artículo, valor:
   * objeto Articulo) */
  std::unordered_map<std::string, Articulo> mapaArticulos;

  // Variables temporales para almacenar los datos del archivo CSV
  std::string tmpGrupoArticulo, tmpNombreArticulo, tmpQRArticulo;
  std::vector<int> tmpDepositosArticulo;

  // Contadores para almacenar la cantidad de artículos
  int stock;
  int total_art;
  int total_art_dif;

public:
  Archivo();

  int contarColumnas();

  void leerCSV();

  std::unordered_map<std::string, Articulo> getMapaArticulos();

  int getTotalArticulos();
  int getTotalArticulosDiferentes();

  void setPath(std::string);
};

/*
 * Constructor por defecto de la clase Archivo
 */
Archivo::Archivo() {}

/*
 * Cuenta la cantidad de columnas del archivo CSV por si se agregan más en el
 * futuro
 * @return Cantidad de columnas
 */
int Archivo::contarColumnas() {
  std::ifstream archivo(path);
  std::string linea, tmp;
  int cantidadColumnas = 0; // Contador de columnas
  separador = ',';

  // Verificar que el archivo se haya abierto correctamente
  try {
    if (!archivo.is_open()) {
      throw 404;
    }
  } catch (int e) {
    std::cout << "Error " << e << ": no se pudo abrir el archivo " << path
              << '\n';
  }

  std::getline(archivo, linea);
  std::stringstream stream(linea);

  while (std::getline(stream, tmp, separador)) {
    ++cantidadColumnas;
  }

  archivo.close();
  return cantidadColumnas;
}

/*
 * Lee el archivo CSV y lo almacena en el mapa de artículos
 */
void Archivo::leerCSV() {
  std::ifstream archivo(path);
  std::string linea, tmpCelda;

  separador = ',';

  total_art = 0;
  total_art_dif = 0;

  // Verificar que el archivo se haya abierto correctamente
  try {
    if (!archivo.is_open()) {
      throw 404;
    }
  } catch (int e) {
    std::cout << "Error " << e << ": no se pudo abrir el archivo " << path
              << '\n';
    exit(1);
  }

  // Saltar la primera línea del archivo
  std::getline(archivo, linea);

  while (std::getline(archivo, linea)) {
    std::stringstream stream(linea);

    for (int i = 0; i < contarColumnas(); ++i) {
      std::getline(stream, tmpCelda, separador);

      // Si la celda está vacía, se le asigna un valor por defecto
      if (tmpCelda.empty()) {
        tmpCelda = "0";
      }

      // Se almacenan los datos en variables temporales
      switch (i) {
      case 0: // Primera columna - grupo
        if (tmpCelda == "0") {
          break;
        } else {
          tmpGrupoArticulo = tmpCelda;
          break;
        }
      case 1: // Segunda columna - nombre
        tmpQRArticulo = tmpCelda;
        break;
      case 2: // Tercera columna - QR
        tmpNombreArticulo = tmpCelda;
        break;
      default: // Cuarta columna en adelante - stock
        try {
          int tmpInt = std::stoi(tmpCelda);
          tmpDepositosArticulo.push_back(tmpInt);
          stock += tmpInt;
        } catch (std::invalid_argument &e) {
          std::cout << "Error: " << e.what() << " ";
          std::cout << tmpCelda << '\n';
        }
        break;
      }
    }

    ++total_art;

    /* Instanciar un objeto Articulo con los datos almacenados en las
     * variables temporales */
    Articulo articulo(tmpGrupoArticulo, tmpQRArticulo, tmpNombreArticulo,
                      tmpDepositosArticulo, stock);

    /* Limpiar el vector temporal de depositos para almacenar los datos del
     * siguiente artículo */
    tmpDepositosArticulo.clear();

    stock = 0;

    if (mapaArticulos.find(tmpNombreArticulo) != mapaArticulos.end()) {
      ++total_art_dif;
      // Convertir total_art_dif a string para agregarlo al nombre del artículo
      mapaArticulos.insert(make_pair(tmpNombreArticulo + " (" +
                                         std::to_string(total_art_dif) + ")",
                                     articulo));
    } else {
      // Almacenar el artículo en el mapa de artículos
      mapaArticulos.insert(make_pair(tmpNombreArticulo, articulo));
    }
  }

  total_art_dif = total_art - total_art_dif;
  archivo.close();
}

/*
 * Obtiene el mapa de artículos
 * @return Mapa de artículos
 */
std::unordered_map<std::string, Articulo> Archivo::getMapaArticulos() {
  return mapaArticulos;
}

/*
 * Obtiene la cantidad total de artículos
 * @return Cantidad total de artículos
 */
int Archivo::getTotalArticulos() { return total_art; }

/*
 * Obtiene la cantidad total de artículos distintos
 * @return Cantidad total de artículos distintos
 */
int Archivo::getTotalArticulosDiferentes() { return total_art_dif; }

/*
 * Establece la ruta del archivo CSV
 */
void Archivo::setPath(std::string path) { this->path = path; }

#endif // __ARCHIVO_H__