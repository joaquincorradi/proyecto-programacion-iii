#include <iostream>
#include <string>

#include "../include/administradorInventario.h"

void printHelp(char const *argv[]);

int main(int argc, char const *argv[]) {
  Administrador admin("../data/database.csv");

  if (argc == 1) {
    std::cout << "\nFaltan argumentos. ";
    printHelp(argv);
    return 0;
  }

  std::string argumento = argv[1];

  if (argumento == "-h" || argumento == "--help") {
    printHelp(argv);
  } else if (argumento == "-artdiff" || argumento == "--total-art-diff") {
    admin.total_art_diff();
  } else if (argumento == "-arttotal" || argumento == "--total-art") {
    admin.total_art();
  } else if (argumento == "-min" || argumento == "--min-stock") {
    if (argc == 3) {
      admin.min_stock(std::stoi(argv[2]));
    } else if (argc == 4) {
      admin.min_stock_2(std::stoi(argv[2]), std::stoi(argv[3]));
    }
  } else if (argumento == "-max" || argumento == "--max-stock") {
    if (argc == 3) {
      admin.max_stock(std::stoi(argv[2]));
    } else if (argc == 4) {
      admin.max_stock_2(std::stoi(argv[2]), std::stoi(argv[3]));
    }
  } else if (argumento == "-s" || argumento == "--stock") {
    if (argc == 3) {
      admin.stock(argv[2]);
    } else if (argc == 4) {
      admin.stock_2((argv[2]), std::stoi(argv[3]));
    }
  } else if (argumento == "-p" || argumento == "--print") {
    admin.printArticulo(argv[2]);
  } else {
    std::cout << "\n\n\tArgumento no válido, use -h o --help para más "
                 "información.\n\n";
  }

  return 0;
}

void printHelp(char const *argv[]) {
  std::cout << "\n\nSINOPSIS:\n\n";
  std::cout << '\t' << argv[0] << " [opción] [extra] [extra]\n\n";

  std::cout << "DESCRIPCIÓN:\n\n";
  std::cout << "\tEste programa permite visualizar el inventario de forma "
               "organizada por medio de diferentes opciones.\n\n";

  std::cout << "OPCIONES:\n\n";

  std::cout << "\t-h, --help\n";
  std::cout << "\t\tMuestra esta ayuda\n\n";

  std::cout << "\t-artdiff, --total-art-diff\n";
  std::cout << "\t\tMuestra el total de artículos diferentes (ignora artículos "
               "repetidos) \n\n";

  std::cout << "\t-arttotal, --total-art\n";
  std::cout << "\t\tMuestra el total de artículos (no ignora artículos "
               "repetidos)\n\n";

  std::cout << "\t-min [n], --min-stock [n]\n";
  std::cout << "\t\tMuestra los artículos con stock menor o igual a 'n'\n\n";

  std::cout << "\t-min [n] [depósito], --min-stock [n] [depósito]\n";
  std::cout << "\t\tMuestra los artículos con stock menor o igual a 'n' en un "
               "depósito específico\n\n";

  std::cout << "\t-max [n], --max-stock [n]\n";
  std::cout << "\t\tMuestra los artículos con stock mayor o igual a 'n'\n\n";

  std::cout << "\t-max [n] [depósito], --max-stock [n] [depósito]\n";
  std::cout << "\t\tMuestra los artículos con stock mayor o igual a 'n' en un "
               "depósito específico\n\n";

  std::cout << "\t-s [nombre_articulo], --stock [nombre_articulo]\n";
  std::cout << "\t\tMuestra el stock de un artículo específico (ingresar el "
               "nombre del artículo entre comillas)\n\n";

  std::cout << "\t-s [nombre_articulo] [depósito], --stock [nombre_articulo] "
               "[depósito]\n";
  std::cout << "\t\tMuestra el stock de un artículo específico en un depósito "
               "específico (ingresar el nombre del\n \t\tartículo entre "
               "comillas)\n\n";

  std::cout << "\t-p [nombre_articulo], --print [nombre_articulo]\n";
  std::cout << "\t\tMuestra toda la información de un artículo específico "
               "(ingresar el nombre del artículo entre\n \t\tcomillas)\n\n";
}