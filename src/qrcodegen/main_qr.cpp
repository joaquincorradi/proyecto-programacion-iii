#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../include/administradorInventario.h"
#include "../../lib/qrcodegen.hpp"

std::string generateQRCode(const std::string &text) {
  qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(
      text.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);

  int size = qr.getSize();

  std::string qrCode;

  for (int y = 0; y < size; ++y) {
    for (int x = 0; x < size; ++x) {
      bool module = qr.getModule(x, y);

      qrCode += module ? "██" : "  ";
    }

    qrCode += "\n";
  }

  return qrCode;
}

std::string getQR(std::string nombreArticulo) {
  Administrador admin("../../data/database.csv");
}

int main() {
  // std::string nombreArticulo;

  // Archivo archivo("../../data/database.csv");
  // archivo.leerCSV();

  // std::cout << "Generar código QR\n";
  // std::cout << "Ingrese el nombre del artículo: ";
  // getline(std::cin, nombreArticulo);

  // std::unordered_map<std::string, Articulo> mapaArticulos =
  //     archivo.getMapaArticulos();

  // std::string QRData = mapaArticulos[nombreArticulo].getQRArticulo();

  // std::string qrCode = generateQRCode(QRData);

  // std::cout << "\n\n" << qrCode << '\n';

  return 0;
}