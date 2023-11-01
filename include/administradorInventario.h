#ifndef __ADMINISTRADOR_H__
#define __ADMINISTRADOR_H__

#include <iostream>
#include <unordered_map>

#include "../include/archivo.h"

class Administrador {
private:
  Archivo archivo;
  std::unordered_map<std::string, Articulo> mapaArticulos;

public:
  Administrador(std::string);

  void print();

  void total_art_diff();

  void total_art();

  void min_stock(int);

  void min_stock_2(int, int);

  void stock(std::string);

  void stock_2(std::string, int);

  void max_stock(int);
};

/*
 * Constructor de la clase Administrador
 * @param path Ruta del archivo CSV
 */
Administrador::Administrador(std::string path) {
  archivo.setPath(path);
  archivo.leerCSV();
  mapaArticulos = archivo.getMapaArticulos();
}

/*
 * Muestra el contenido del archivo CSV
 */
void Administrador::print() {
  std::unordered_map<std::string, Articulo>::iterator itr;

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    std::cout << itr->second.getGrupoArticulo() << " - "
              << itr->second.getNombreArticulo() << " - "
              << itr->second.getQRArticulo() << " - "
              << itr->second.getStockArticulo() << " - ";

    for (int i = 0; i < itr->second.getDepositosArticulo().size(); i++) {
      std::cout << itr->second.getDepositosArticulo()[i] << " ";
    }

    std::cout << "\n";
  }
}

/*
 * Muestra el total de artículos diferentes
 */
void Administrador::total_art_diff() {
  std::cout << "Total de artículos diferentes: "
            << archivo.getTotalArticulosDiferentes() << "\n";
}

/*
 * Muestra el total de artículos
 */
void Administrador::total_art() {
  std::cout << "Total de artículos: " << archivo.getTotalArticulos() << "\n";
}

/*
 * Muestra los artículos con stock menor a n unidades
 * @param n Cantidad de unidades
 */
void Administrador::min_stock(int n) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  std::cout << "Artículos con stock igual o menor a " << n << " unidades:\n\n";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getStockArticulo() <= n) {
      std::cout << "\t " << itr->second.getNombreArticulo()
                << " - Stock en depósitos: " << itr->second.getStockArticulo()
                << '\n';
    }
  }
}

/*
 * Muestra los artículos con stock menor a n unidades en el depósito
 * @param n Cantidad de unidades
 * @param deposito Número de depósito
 */
void Administrador::min_stock_2(int n, int deposito) {}

/*
 * Muestra el stock de un artículo
 * @param nombre_articulo Nombre del artículo
 */
void Administrador::stock(std::string nombre_articulo) {}

/*
 * Muestra el stock de un artículo en el depósito
 * @param nombre_articulo Nombre del artículo
 * @param deposito Número de depósito
 */
void Administrador::stock_2(std::string nombre_articulo, int deposito) {}

/*
 * Muestra los artículos con stock mayor a n unidades
 * @param n Cantidad de unidades
 */
void Administrador::max_stock(int n) {}

#endif // __ADMINISTRADOR_H__