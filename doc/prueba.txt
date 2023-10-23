#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "InventarioProductos.csv"
using namespace std;

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string idProducto, codigoBarras, descripcion, precioCompra, precioVenta, existencia, stock;
        // Extraer todos los valores de esa fila
        getline(stream, idProducto, delimitador);
        getline(stream, codigoBarras, delimitador);
        getline(stream, descripcion, delimitador);
        getline(stream, precioCompra, delimitador);
        getline(stream, precioVenta, delimitador);
        getline(stream, existencia, delimitador);
        getline(stream, stock, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Id: " << idProducto << endl;
        cout << "Codigo de barras: " << codigoBarras << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio de compra: " << precioCompra << endl;
        cout << "Precio de venta: " << precioVenta << endl;
        cout << "Existencia: " << existencia << endl;
        cout << "Stock: " << stock << endl;
    }

    archivo.close();
}