#include <iostream>
#include <string>

using namespace std;

class Cuenta {
    private:
        float total;
    public:
        Cuenta() {
            total = 0.0;
        }
        void agregarTotal(float cantidad) {
            total += cantidad;
        }
        float obtenerTotal() {
            return total;
        }
        ~Cuenta() {
            cout << "El total a pagar es de: S/ " <<total<<endl;
        }
};

class Comidas {
    private:
        int milanesa, pollo, parrilla;
    public:
        Comidas(int m, int p, int pa) {
            milanesa = m;
            pollo = p;
            parrilla = pa;
        }
        int getPrecio(string comida) {
            if (comida == "Milanesa") {
                return milanesa;
            } else if (comida == "Pollo") {
                return pollo;
            } else if (comida == "Parrilla") {
                return parrilla;
            } else {
                return 0;
            }
        }
        ~Comidas() {
            cout << "La clase de comidas ha sido destruida!!" << endl;
        }
};

class Bebidas {
    private:
        float cola, limonada, maracuya;
    public:
        Bebidas(float c, float l, float m) {
            cola = c;
            limonada = l;
            maracuya = m;
        }
        float getPrecio(string bebida) {
            if (bebida == "Kola Escocesa") {
                return cola;
            } else if (bebida == "Jarra_de_limonada") {
                return limonada;
            } else if (bebida == "Jarra_de_maracuya") {
                return maracuya;
            } else {
                return 0;
            }
        }
        ~Bebidas() {
            cout << "La clase de bebidas ha sido destruida!!"<<endl;
        }
};

class Menu {
    private:
        Comidas comida;
        Bebidas bebida;
        Cuenta cuenta;
    public:
        Menu() : comida(30, 22, 26), bebida(6.50, 12, 16) {}
        void mostrarMenu() {
            cout << "=========Forky's========"<<endl;
            cout << "Comidas:"<<endl;
            cout << "1.Milanesa = S/30"<<endl;
            cout << "2.Pollo = S/22"<<endl;
            cout << "3.Parrilla = S/26"<<endl;
            cout << "Bebidas:"<<endl;
            cout << "4.Cola Escocesa = S/6.50"<< endl;
            cout << "5.Jarra de Limonada = S/12"<<endl;
            cout << "6.Jarra de Maracuya = S/16"<<endl;
            cout << "========================="<<endl;
        }
        void tomarOrden() {
            int opcionComida, opcionBebida;
            string comidaSeleccionada, bebidaSeleccionada;
            cout << "Escriba el numero de orden de comida (Del 1-3): ";
            cin >> opcionComida;
            switch(opcionComida) {
                case 1:
                    comidaSeleccionada = "Milanesa";
                    break;
                case 2:
                    comidaSeleccionada = "Pollo";
                    break;
                case 3:
                    comidaSeleccionada = "Parrilla";
                    break;
                    default:
                cout << "Error!!" << endl;
                return;
        }
        cout << "Seleccione su bebida(De 4-6): ";
        cin >> opcionBebida;
        switch(opcionBebida) {
            case 4:
                bebidaSeleccionada = "KolaEscocesa";
                break;
            case 5:
                bebidaSeleccionada = "Jarra_de_Limonada";
                break;
            case 6:
                bebidaSeleccionada = "Jarra_de_Maracuya";
                break;
            default:
                cout << "ERRORRR!!!" << endl;
                return;
        }
        float precioComida = comida.getPrecio(comidaSeleccionada);
        float precioBebida = bebida.getPrecio(bebidaSeleccionada);
        cuenta.agregarTotal(precioComida + precioBebida);
        cout << "Gracias por su preferencia, su Factura es de:" << cuenta.obtenerTotal() << endl;
    }
    ~Menu() {
        cout << "El menu ha sido destruido" << endl;
    }
};

int main() 
{
    Menu menu;
    int opcion;
    do 
    {
        menu.mostrarMenu();
        cout << "Seleccione una opcion (0 para salir): ";
        cin >> opcion;
        if (opcion != 0) 
        {
            menu.tomarOrden();
        }
    } while (opcion != 0);
    return 0;
}