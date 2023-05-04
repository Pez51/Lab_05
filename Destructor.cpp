#include <iostream>
#include <string>


using namespace std;


class Persona {
    private:
        string nombre;
        int edad;
    public:
        Persona(string n, int e) { // Constructor
            nombre = n;
            edad = e;
            cout << "Se ha creado una persona llamada " << nombre << endl;
        }
        ~Persona() { // Destructor
            cout << "Se ha destruido los datos de la persona llamada " << nombre << endl;
        }
};


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


int main() {
    Persona p("Oscar", 30);
    Auto a("Toyota", "Rav4");
    return 0;
}