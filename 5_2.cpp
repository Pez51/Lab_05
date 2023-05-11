#include <iostream>
#include <string>


using namespace std;


class Auto {
private:
    string marca;
    string modelo;
public:
    Auto(string m, string mod) { // Constructor
        marca = m;
        modelo = mod;
        cout << "Se ha creado un auto de marca " << marca << " y modelo " << modelo << endl;
    }
    ~Auto() { // Destructor
        cout << "Se ha destruido los datos de un auto marca " << marca << " y modelo " << modelo << endl;
    }
};


class Direccion {
private:
    string calle;
    string ciudad;
public:
    Direccion(string c, string ci) { // Constructor
        calle = c;
        ciudad = ci;
        cout << "Se ha creado una dirección en la calle " << calle << " en la ciudad de " << ciudad << endl;
    }
    ~Direccion() { // Destructor
        cout << "Se ha destruido los datos de una dirección en la calle " << calle << " en la ciudad de " << ciudad << endl;
    }
};


class Persona {
private:
    string nombre;
    int edad;
    Auto* autoPersona;
    Direccion* direccionPersona;
public:
    Persona(string n, int e, string marcaAuto, string modeloAuto, string calleDireccion, string ciudadDireccion) { // Constructor
        nombre = n;
        edad = e;
        autoPersona = new Auto(marcaAuto, modeloAuto);
        direccionPersona = new Direccion(calleDireccion, ciudadDireccion);
        cout << "Se ha creado una persona llamada " << nombre << endl;
    }


    ~Persona() { // Destructor
        cout << "Se ha destruido los datos de la persona llamada " << nombre << endl;
        delete autoPersona;
        delete direccionPersona;
    }


    void cambiarDireccion(string nuevaCalle, string nuevaCiudad) {
        cout << "Cambiando dirección de la persona " << nombre << endl;
        delete direccionPersona; // Elimina la dirección anterior
        direccionPersona = new Direccion(nuevaCalle, nuevaCiudad); // Crea una nueva dirección
    }


    void cambiarAuto(string nuevaMarca, string nuevoModelo) {
        cout << "Cambiando auto de la persona " << nombre << endl;
        delete autoPersona; // Elimina el auto anterior
        autoPersona = new Auto(nuevaMarca, nuevoModelo); // Crea un nuevo auto
    }


    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Auto: Marca " << autoPersona->marca << ", Modelo " << autoPersona->modelo << endl;
        cout << "Dirección: Calle " << direccionPersona->calle << ", Ciudad " << direccionPersona->ciudad << endl;
    }
};


int main() {
    Persona p("Oscar", 30, "Toyota", "Rav4", "Av. Siempre Viva 123", "Springfield");
    p.mostrarDatos();


    p.cambiarDireccion("Calle Falsa 123", "Shelbyville");
    p.mostrarDatos();


    p.cambiarAuto("Nissan", "Versa");
    p.mostrarDatos();


    return 0;
}
