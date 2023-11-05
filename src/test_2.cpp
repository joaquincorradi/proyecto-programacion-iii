#include <iostream>
#include <unordered_map>

#include "../include/archivo.h"

int main() {
  Archivo archivo("../data/database.csv");
  archivo.leerCSV();

  std::unordered_map<std::string, Articulo> mapaArticulos =
      archivo.getMapaArticulos();

  int total_art = archivo.getTotalArt();
  int total_art_dif = archivo.getTotalArtDif();

  std::cout << "Total de artículos: " << total_art << "\n";
  std::cout << "Total de artículos diferentes: " << total_art_dif << "\n\n";

  std::string nombreArticulo;

  std::cout << "Consultar por stock en depósito\n";
  std::cout << "Ingrese el nombre del artículo: ";
  getline(std::cin, nombreArticulo);

  if (mapaArticulos.find(nombreArticulo) != mapaArticulos.end()) {
    std::cout << "\nEl artículo '" << nombreArticulo << "' con QR '"
              << mapaArticulos[nombreArticulo].getQRArticulo()
              << "' del grupo '"
              << mapaArticulos[nombreArticulo].getGrupoArticulo()
              << "' se encuentra en los depósitos.\n";
    for (int i = 0;
         i < mapaArticulos[nombreArticulo].getDepositosArticulo().size(); ++i) {
      std::cout << "\nDeposito " << i + 1 << ": "
                << mapaArticulos[nombreArticulo].getDepositosArticulo()[i]
                << " unidades, ";
    }
    std::cout << "\n\nStock total: "
              << mapaArticulos[nombreArticulo].getStockArticulo()
              << " unidades\n";
  } else {
    std::cout << "El artículo " << nombreArticulo
              << " no se encuentra en la base de datos\n";
  }

  return 0;
}