#include <iostream>
#include <string>

void hola(std::string);

int main(int argc, char const *argv[]) {
  std::string archivo = argv[argc - 1], arg;
  std::cout << "Archivo: " << archivo << '\n';

  for (int i = 1; i < argc - 1; i++) {
    arg = argv[i];
    std::cout << "Argumento " << i << ": " << arg << '\n';

    if (arg == "-hola") {
      hola(archivo);
    }
  }
  return 0;
}

void hola(std::string archivo) { std::cout << "Hola " << archivo << '\n'; }