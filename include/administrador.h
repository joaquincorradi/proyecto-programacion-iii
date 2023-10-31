#ifndef __ADMINISTRADOR_H__
#define __ADMINISTRADOR_H__

#include <iostream>

#include "../include/archivo.h"

class Administrador {
private:
  Archivo archivo;

public:
  Administrador();
  ~Administrador();

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
 */
Administrador::Administrador() {}

/*
 * Destructor de la clase Administrador
 */
Administrador::~Administrador() {}

/*
 * Muestra el total de artículos diferentes
 */
void Administrador::total_art_diff() {
  std::cout << "Total de artículos diferentes: " << archivo.getTotalArtDif()
            << "\n";
}

/*
 * Muestra el total de artículos
 */
void Administrador::total_art() {
  std::cout << "Total de artículos: " << archivo.getTotalArt() << "\n";
}

/*
 * Muestra los artículos con stock menor a n unidades
 * @param n Cantidad de unidades
 */
void Administrador::min_stock(int n) {
  std::cout << "Artículos con stock menor a " << n << " unidades:\n";
  for (auto it = archivo.getMapaArticulos().begin();
       it != archivo.getMapaArticulos().end(); ++it) {
    if (it->second.getStockArticulo() < n) {
      std::cout << "Nombre: " << it->first << "\n";
      std::cout << "QR: " << it->second.getQRArticulo() << "\n";
      std::cout << "Grupo: " << it->second.getGrupoArticulo() << "\n";
      std::cout << "Stock: " << it->second.getStockArticulo() << "\n\n";
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