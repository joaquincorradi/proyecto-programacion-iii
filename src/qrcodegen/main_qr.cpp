#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../include/archivo.h"
#include "../../include/qrcodegen/qrcodegen.hpp"

std::string generateQRCode(const std::string &text) {
  // Create a QR Code object with the given text and error correction level.
  qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(
      text.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);

  // Get the size of the QR code matrix.
  int size = qr.getSize();

  // Create a string to store the QR code.
  std::string qrCode;

  // Iterate over each row of the QR code matrix.
  for (int y = 0; y < size; ++y) {
    // Iterate over each column of the QR code matrix.
    for (int x = 0; x < size; ++x) {
      // Get the value of the current module (black or white).
      bool module = qr.getModule(x, y);

      // Append the appropriate character to the QR code string.
      qrCode += module ? "██" : "  ";
    }

    // Add a new line after each row.
    qrCode += "\n";
  }

  return qrCode;
}

int main() {
  std::string nombreArticulo;

  Archivo archivo("../../data/database.csv");
  archivo.leerCSV();

  std::cout << "Generar código QR\n";
  std::cout << "Ingrese el nombre del artículo: ";
  getline(std::cin, nombreArticulo);

  std::unordered_map<std::string, Articulo> mapaArticulos =
      archivo.getMapaArticulos();

  std::string QRData = mapaArticulos[nombreArticulo].getQRArticulo();

  // Example usage: Generate a QR code for a URL.
  std::string qrCode = generateQRCode(QRData);

  // Print the generated QR code.
  std::cout << "\n\n" << qrCode << '\n';

  return 0;
}