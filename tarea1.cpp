//Zuleinis K Ramos López
#include <iostream>
using namespace std;
#define MAX 100

class Conjunto
{
public:
    Conjunto();
    ~Conjunto();
    void agregar();
    int pertenece(const int & elemento);
    bool estaVacio();
    bool estaLleno();
    void escribir();
    friend Conjunto unionConjunto(Conjunto & conjunto1, Conjunto & conjunto2, Conjunto & conjunto3);
private:
    int conjunto[MAX];
    int size;
};

int main()
{
    Conjunto conjuntoA, conjuntoB, conjuntoC;
    int i = 0;
    int elemento;
    char seleccion;
    bool repetir, repetirMenu = true;
    char opcionConjunto;
    do
    {
        cout << "\nMENÚ" << endl;
        cout << "\n(a) Añadir elementos a un conjunto";
        cout << "\n(b) Verificar si un elemento ya existe en un conjunto";
        cout << "\n(c) Verificar si un conjunto esta vacio";
        cout << "\n(d) Verificar si un conjunto esta lleno";
        cout << "\n(e) Mostrar todos los elementos de un conjunto";
        cout << "\n(f) Crear union de los conjuntos A y B";
        cout << "\n(g) Terminar" << endl;
        cout << "\nSelección: ";
        cin >> seleccion;
        switch (seleccion)
        {
            case 'a':
                cout << "Con que conjunto desea trabajar? (A/B)\n";
                cin >> opcionConjunto;
                switch(opcionConjunto)
                {
                    case 'A':
                        conjuntoA.agregar();
                        break;
                    case 'B':
                        conjuntoB.agregar();
                        break;
                    case 'C':
                        conjuntoC.agregar();
                        break;
                    default:
                        cout << "\nSu selección es iválida, intente de nuevo.\n";
                        break;
                }
                break;
            case 'b':
                cout << "Con que conjunto desea trabajar? (A/B/C)\n";
                cin >> opcionConjunto;
                cout << "Ingrese el elemento que busca: ";
                cin >> elemento;
                switch(opcionConjunto)
                {
                    case 'A':
                        if(conjuntoA.pertenece(elemento)==-1)
                            cout << "El elemento " << elemento << " no existe en el conjunto A." << endl;
                        else
                            cout << "El elemento " << elemento << " existe en la posición " << conjuntoA.pertenece(elemento) << " del conjunto A." << endl;                           
                        break;
                    case 'B':
                        if(conjuntoB.pertenece(elemento)==-1)
                            cout << "El elemento " << elemento << " no existe en el conjunto B." << endl;
                        else
                            cout << "El elemento " << elemento << " existe en la posición " << conjuntoB.pertenece(elemento) << " del conjunto B." << endl;  
                        break;
                    case 'C':
                        if(conjuntoC.pertenece(elemento)==-1)
                            cout << "El elemento " << elemento << " no existe en el conjunto C." << endl;
                        else
                            cout << "El elemento " << elemento << " existe en la posición " << conjuntoC.pertenece(elemento) << " del conjunto C." << endl;  
                        break;
                    default:
                        cout << "\nSu selección es iválida, intente de nuevo.\n";
                    break;
                }
            break;
            case 'c':
                    cout << "Con que conjunto desea trabajar? (A/B/C)\n";
                    cin >> opcionConjunto;
                    switch(opcionConjunto)
                    {
                        case 'A':
                            if (conjuntoA.estaVacio())
                                cout << "\nEl conjunto esta vacio.\n";
                            else
                                cout << "\nEl conjunto no esta vacio.\n";
                            break;
                        case 'B':
                            if (conjuntoB.estaVacio())
                                cout << "\nEl conjunto esta vacio.\n";
                            else
                                cout << "\nEl conjunto no esta vacio.\n";
                            break;
                        case 'C':
                            if (conjuntoC.estaVacio())
                                cout << "\nEl conjunto esta vacio.\n";
                            else
                                cout << "\nEl conjunto no esta vacio.\n";
                            break;
                        default:
                            cout << "\nSu selección es iválida, intente de nuevo.\n";
                        break;
                    }
            break;
            case 'd':
                    cout << "Con que conjunto desea trabajar? (A/B/C)\n";
                    cin >> opcionConjunto;
                    switch(opcionConjunto)
                    {
                        case 'A':
                            if(conjuntoA.estaLleno())
                                cout << "\nEl conjunto esta lleno.\n";
                            else
                                cout << "\nEl conjunto no esta lleno.\n";
                            break;
                        case 'B':
                            if(conjuntoB.estaLleno())
                                cout << "\nEl conjunto esta lleno.\n";
                            else
                                cout << "\nEl conjunto no esta lleno.\n";
                            break;
                        case 'C':
                            if(conjuntoC.estaLleno())
                            cout << "\nEl conjunto esta lleno.\n";
                            else
                                cout << "\nEl conjunto no esta lleno.\n";
                            break;
                        default:
                            cout << "\nSu selección es iválida, intente de nuevo.\n";
                        break;
                    }
                break;
            case 'e':
                    cout << "Con que conjunto desea trabajar? (A/B/C)\n";
                    cin >> opcionConjunto;
                    switch(opcionConjunto)
                    {
                        case 'A':
                            conjuntoA.escribir();
                            break;
                        case 'B':
                            conjuntoB.escribir();
                            break;
                        case 'C':
                            conjuntoC.escribir();
                            break;
                        default:
                            cout << "\nSu selección es iválida, intente de nuevo.\n";
                        break;
                    }
                break;
            case 'f':
                //conjuntoA + conjuntoB;
                unionConjunto(conjuntoA,conjuntoB,conjuntoC);
                cout << "\nSe ha creado la union de los conjuntos A y B.\n";
                break;
            case 'g':
                cout << "\nGracias por usar este programa.\n";
                repetirMenu = false;
                break;
            default:
                cout << "\nSu selección es iválida, intente de nuevo.\n";
                repetirMenu = true;
                break;
        }
    } while (repetirMenu == true);
return 0;
}
//Permite al usuario utilizar las funciones de este programa mediante un menú.
Conjunto :: Conjunto()
{
   int conjunto[MAX]={0};
   size = 0;
}

Conjunto :: ~Conjunto(){}

void Conjunto :: agregar()
{
    int elemento;
    char repetir;
    do
    {
    cout << "Ingrese el elemento: ";
    cin >> elemento;
    if (pertenece(elemento)==-1 && size!=MAX)
    {
        conjunto[size] = elemento;
        size++;
    }
    else if(size == MAX)
        cout << "No se puede añadir este elemento, ya que el arreglo a alcanzado su cantidad máxima de elementos.\n";
    else
        cout << "El elemento " << elemento << " ya existe en el conjunto.\n";
    cout << "Desea añadir otro elemento?(y/n): ";
     cin >> repetir;
    }while (repetir == 'y');
}
//Agrega elementos a un conjunto siempre que dichos elementos no existan en el mismo.
int Conjunto :: pertenece(const int & elemento)
{
    for (int i = 0; i < size; i++)
    {
        if (elemento == conjunto[i])
        {
            return i;
        }
    }
    return -1;
}
//Verifica si un elemento existe o no en un conjunto. Si existe, devuelve la posición.
bool Conjunto :: estaVacio()
{
    if (size == 0) {
        return true;
    }
    else
        return false;
}
//Verifica si un conjunto tiene elementos o no.
bool Conjunto :: estaLleno()
{
    return (size == MAX);
}
//Verifica si un conjunto tiene la cantidad maxima de elementos.
void Conjunto :: escribir()
{
    for (int i = 0; i < size; i++) {
        cout << conjunto[i] << endl;
    }
}
//Imprime todos los elementos de un conjunto.
Conjunto unionConjunto(Conjunto & conjunto1, Conjunto & conjunto2, Conjunto & conjunto3)
{
    for (int i = 0; i < conjunto1.size; i++)
    {
        conjunto3.conjunto[i] = conjunto1.conjunto[i];
        conjunto3.size++;
    }

    for (int j = 0; j < conjunto2.size; j++)
    {
        if(conjunto3.pertenece(conjunto2.conjunto[j]) == -1)
            conjunto3.conjunto[conjunto3.size++] = conjunto2.conjunto[j];
    }
return conjunto3;
} 
