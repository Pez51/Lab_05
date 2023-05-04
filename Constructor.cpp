#include <iostream>
using namespace std;

class Direccion {
    public:
        Direccion(string c, string ciu) { // Constructor
            calle = c;
            ciudad = ciu;
        }
        string calle;
        string ciudad;
};

class Auto {
    public:
        Auto(string m, string mod) { // Constructor
            marca = m;
            modelo = mod;
        }
        string marca;
        string modelo;
};

class Persona {
    public:
        Persona(string nom, int ed, string c, string ciu, string m, string mod) { // Constructor
            nombre = nom;
            edad = ed;
            direccionPersona = new Direccion(c, ciu);
            autoPersona = new Auto(m, mod);
        }
        ~Persona() { // Destructor
            delete direccionPersona;
            delete autoPersona;
        }
        void mostrarDatos() {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Auto: Marca " << autoPersona->marca << ", Modelo " << autoPersona->modelo << endl;
            cout << "Dirección: Calle " << direccionPersona->calle << ", Ciudad " << direccionPersona->ciudad << endl;
        }
    private:
        string nombre;
        int edad;
        Direccion* direccionPersona;
        Auto* autoPersona;
};

int main() {
    Persona* p = new Persona("Juan", 30, "Calle 123", "Lima", "Toyota", "Corolla");
    p->mostrarDatos();
    delete p;
    return 0;
}