#include "../include/administradorInventario.h"

int main() {
  Administrador admin("../data/database.csv");
  admin.print();
  return 0;
}