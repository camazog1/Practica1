#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include "Listas.h"
#include "bancodepalabras.h"
#include "mayusculas.h"
#include "crearlli.h"
#include "color.h"
using namespace std;

void juego(){
    Color::Modifier verdel(Color::FG_LIGHT_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    LinkedList llp = LinkedList();
    llp = palabras();
    LinkedList lli = LinkedList();
    cout << verdel << "Wordle For: Carlos M." << endl << "----------------------------------------" << def << endl << endl << "¿Cual es tu nombre? -> Escribe un solo nombre sin espacios :)" << endl;
    string name;
    cin>>name;
    cout << endl << "Bienvenid@ " << verdel << name << def << " ¿Estas listo para jugar?" << endl << endl << "Presiona 1 para Sí" << endl << "Presiona otra tecla para No" << endl << endl;
    int resp;
    cin>>resp;
    if (resp == 1){
        cout << "Escribe una palabra de [5] digitos -> Tienes 6 intentos" << endl << endl;
        string intentos;
        for(int i = 0; i < 7; i += 1){
            if (i == 6){
                cout << "Lo siento la palabra era: ";
                llp.ponerrojo();
                break;
            }
            cin>>intentos;
            if (intentos.size() == 5){
                mayuscula(intentos);
                lli = crear_lli(intentos);
                lli = llp.comparar(lli);
                lli.colorear();
                if (lli.compararigualdad() == true){
                    cout << endl << "Felicidades ganaste :)" << endl;
                    break;
                }
            }
            else{
                cout << endl << "La palabra tiene más o menos caracteres de los necesarios" << endl << endl;
                i -= 1;
            }
        }
    }
}

int main(){
    juego();
}