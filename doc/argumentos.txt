#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include <vector>

using namespace std;

void verFila(string nombreArchivo){

    fstream dato;

    dato.open("./" + nombreArchivo, ios::in);

    string columna, filas;
    getline(dato, filas);
    stringstream s(filas);
    while(getline(s, columna, ',')){

        cout << columna << endl;
    }

}

/*
 * argc --> numero de palabras (incluido el nombre del programa)
 * argv --> vector de punteros a cadena, donde cada elemento apunta a una palabra.
 */
int main(int argc, char **argv) {

    cout<<"Cantidad de argumentos: "<<argc<<endl;
    for(int i=0; i<argc; i++){
        cout << "Argumento " << i << ": " << argv[i] <<endl;

        if(strcmp(argv[i], "-file")==0){
            cout << "Nombre del Archivo " << argv[i+1] <<endl;
            verFila(argv[i+1]);
            break;

        }
    }

    return 0;
}
