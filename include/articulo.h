#ifndef __ARTICULO_H__
#define __ARTICULO_H__

#include <string>
#include <unordered_map>
#include <vector>

class Articulo {
private:
  std::string grupoArticulo;
  std::string QRArticulo;
  std::string nombreArticulo;
  std::vector<int> depositosArticulo;
  /* Cada espacio de la lista es un depósito, y el valor es el stock del
   * artículo en ese depósito */
  int stockArticulo;

public:
  Articulo(std::string, std::string, std::string, std::vector<int>, int);
  Articulo();

  std::string getQRArticulo();

  std::string getNombreArticulo();

  std::string getGrupoArticulo();

  std::vector<int> getDepositosArticulo();
  void setDepositosArticulo(std::vector<int>);

  int getStockArticulo();
};

/*
 * Constructor de la clase Articulo
 * @param _grupoArticulo Grupo al que pertenece el artículo
 * @param _QRArticulo Código QR del artículo
 * @param _nombreArticulo Nombre del artículo
 * @param _depositosArticulo Lista con la cantidad de artículos en cada
 * depósito
 */
Articulo::Articulo(std::string _grupoArticulo, std::string _QRArticulo,
                   std::string _nombreArticulo,
                   std::vector<int> _depositosArticulo, int _stockArticulo)
    : grupoArticulo(_grupoArticulo), QRArticulo(_QRArticulo),
      nombreArticulo(_nombreArticulo), depositosArticulo(_depositosArticulo),
      stockArticulo(_stockArticulo) {}

/*
 * Constructor por defecto de la clase Articulo
 */
Articulo::Articulo() {}

/*
 * Obtiene el código QR del artículo
 * @return Código QR del artículo
 */
std::string Articulo::getQRArticulo() { return QRArticulo; }

/*
 * Obtiene el nombre del artículo
 * @return Nombre del artículo
 */
std::string Articulo::getNombreArticulo() { return nombreArticulo; }

/*
 * Obtiene el grupo al que pertenece el artículo
 * @return Grupo al que pertenece el artículo
 */
std::string Articulo::getGrupoArticulo() { return grupoArticulo; }

/*
 * Obtiene la lista con el stock del artículo en cada depósito
 * @return Lista con el stock del artículo en cada depósito
 */
std::vector<int> Articulo::getDepositosArticulo() { return depositosArticulo; }

/*
 * Establece la lista con el stock del artículo en cada depósito
 * @param _depositosArticulo Lista con el stock del artículo en cada depósito
 */
void Articulo::setDepositosArticulo(std::vector<int> _depositosArticulo) {
  depositosArticulo = _depositosArticulo;
}

/*
 * Obtiene el stock del artículo
 * @return Stock del artículo
 */
int Articulo::getStockArticulo() { return stockArticulo; }

#endif // __ARTICULO_H__