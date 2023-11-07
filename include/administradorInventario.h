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
  void printArticulo(std::string);
  std::string printQRData(std::string);

  void total_art_diff();

  void total_art();

  void min_stock(int);

  void min_stock_2(int, int);

  void max_stock(int);

  void max_stock_2(int, int);

  void stock(std::string);

  void stock_2(std::string, int);
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
 * Muestra el contenido de un artículo
 * @param nombre_articulo Nombre del artículo
 */
void Administrador::printArticulo(std::string nombre_articulo) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getNombreArticulo() == nombre_articulo) {
      std::cout << "\n\t- Nombre del artículo: "
                << itr->second.getNombreArticulo()
                << "\n\t- Grupo del artículo: "
                << itr->second.getGrupoArticulo()
                << "\n\t- QR del artículo: " << itr->second.getQRArticulo()
                << "\n\t- Stock del artículo: "
                << itr->second.getStockArticulo()
                << "\n\t- Stock en depósitos del artículo: \n";

      for (int i = 0; i < itr->second.getDepositosArticulo().size(); i++) {
        std::cout << "\t\tDepósito " << i + 1 << ": "
                  << itr->second.getDepositosArticulo()[i] << " unidades. \n";
      }

      std::cout << "\n";
    }
  }
}

/*
 * Devuelve el contenido de un artículo para ser impreso en un código QR
 * @param nombre_articulo Nombre del artículo
 */
std::string Administrador::printQRData(std::string nombre_articulo) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getNombreArticulo() == nombre_articulo) {
      std::string QRData;

      QRData += itr->second.getNombreArticulo() + "\n";
      QRData += "Grupo: " + itr->second.getGrupoArticulo() + "\n";
      QRData += "Depositos:\n";

      for (int i = 0; i < itr->second.getDepositosArticulo().size(); i++) {
        QRData += std::to_string(itr->second.getDepositosArticulo()[i]) + " ";
      }

      return QRData;
    }
  }
}

/*
 * Muestra el total de artículos diferentes
 */
void Administrador::total_art_diff() {
  std::cout << "\n\tTotal de artículos diferentes (se ignoran artículos "
               "repetidos): "
            << archivo.getTotalArticulosDiferentes() << " unidades\n\n";
}

/*
 * Muestra el total de artículos
 */
void Administrador::total_art() {
  std::cout << "\n\tTotal de artículos (no se ignoran artículos repetidos): "
            << archivo.getTotalArticulos() << " unidades.\n\n";
}

/*
 * Muestra los artículos con stock menor a n unidades
 * @param n Cantidad de unidades
 */
void Administrador::min_stock(int n) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  try {
    if (n < 0) {
      throw n;
    }
  } catch (int n) {
    std::cout << "\n\tError: el número ingresado debe ser positivo.\n\n";
    return;
  }

  std::cout << "\n\tArtículos con stock igual o menor a " << n
            << " unidades:\n\n";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getStockArticulo() <= n) {
      std::cout << "\t\t- " << itr->second.getNombreArticulo() << ": "
                << itr->second.getStockArticulo() << " unidades.\n";
    }
  }
}

/*
 * Muestra los artículos con stock menor a n unidades en el depósito
 * @param n Cantidad de unidades
 * @param deposito Número de depósito
 */
void Administrador::min_stock_2(int n, int deposito) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  try {
    if (n < 0 || deposito <= 0 ||
        deposito >
            mapaArticulos.begin()->second.getDepositosArticulo().size()) {
      throw n;
    }
  } catch (int n) {
    std::cout << "\n\tError: los números ingresados deben ser positivos o el "
                 "depósito no existe.\n\n";
    return;
  }

  std::cout << "\n\tArtículos con stock igual o menor a " << n
            << " unidades en el depósito " << deposito << ":\n\n";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getDepositosArticulo()[deposito - 1] <=
        n) { // second es el Articulo
      std::cout << "\t\t- " << itr->second.getNombreArticulo() << ": "
                << itr->second.getDepositosArticulo()[deposito - 1]
                << " unidades en el depósito " << deposito << ".\n";
    }
  }
}

/*
 * Muestra el stock de un artículo
 * @param nombre_articulo Nombre del artículo
 */
void Administrador::stock(std::string nombre_articulo) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  std::cout << "\n\tStock del artículo " << nombre_articulo << ": ";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getNombreArticulo() == nombre_articulo) {
      std::cout << itr->second.getStockArticulo() << " unidades.\n\n";
    }
  }
}

/*
 * Muestra el stock de un artículo en el depósito
 * @param nombre_articulo Nombre del artículo
 * @param deposito Número de depósito
 */
void Administrador::stock_2(std::string nombre_articulo, int deposito) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  try {
    if (deposito <= 0 ||
        deposito >
            mapaArticulos.begin()->second.getDepositosArticulo().size()) {
      throw deposito;
    }
  } catch (int deposito) {
    std::cout << "\n\tError: el depósito ingresado no existe.\n\n";
    return;
  }

  std::cout << "\n\tStock del artículo " << nombre_articulo
            << " en el depósito " << deposito << ": ";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getNombreArticulo() == nombre_articulo) {
      std::cout << itr->second.getDepositosArticulo()[deposito - 1]
                << " unidades.\n\n";
    }
  }
}

/*
 * Muestra los artículos con stock mayor a n unidades
 * @param n Cantidad de unidades
 */
void Administrador::max_stock(int n) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  try {
    if (n < 0) {
      throw n;
    }
  } catch (int n) {
    std::cout << "\n\tError: el número ingresado debe ser positivo.\n\n";
    return;
  }

  std::cout << "\n\tArtículos con stock igual o mayor a " << n
            << " unidades:\n\n";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getStockArticulo() >= n) {
      std::cout << "\t\t- " << itr->second.getNombreArticulo() << ": "
                << itr->second.getStockArticulo() << " unidades.\n";
    }
  }
}

/*
 * Muestra los artículos con stock mayor a n unidades en el depósito
 * @param n Cantidad de unidades
 */
void Administrador::max_stock_2(int n, int deposito) {
  std::unordered_map<std::string, Articulo>::iterator itr;

  try {
    if (deposito <= 0 ||
        deposito >
            mapaArticulos.begin()->second.getDepositosArticulo().size()) {
      throw deposito;
    }
  } catch (int deposito) {
    std::cout << "\n\tError: el depósito ingresado no existe.\n\n";
    return;
  }

  std::cout << "\n\tArtículos con stock igual o mayor a " << n
            << " unidades en el depósito " << deposito << ":\n\n";

  for (itr = mapaArticulos.begin(); itr != mapaArticulos.end(); itr++) {
    if (itr->second.getDepositosArticulo()[deposito - 1] >=
        n) { // second es el Articulo
      std::cout << "\t\t- " << itr->second.getNombreArticulo() << ": "
                << itr->second.getDepositosArticulo()[deposito - 1]
                << " unidades en el depósito " << deposito << ".\n";
    }
  }
}

#endif // __ADMINISTRADOR_H__