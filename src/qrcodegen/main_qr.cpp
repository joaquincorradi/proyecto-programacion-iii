#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../include/administradorInventario.h"
#include "../../lib/qrcodegen.hpp"

std::string generateQRCode(const std::string &text) {
  qrcodegen::QrCode qr =
      qrcodegen::QrCode::encodeText(text.c_str(), qrcodegen::QrCode::Ecc::LOW);

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

int main(int argc, char const *argv[]) {
  Administrador admin("../../data/database.csv");

  std::string QRData;
  std::string argumento = argv[1];

  if (argumento == "-qr") {
    QRData = admin.printQRData(argv[2]);
    std::cout << generateQRCode(QRData) << std::endl;
  }

  return 0;
}
