#ifndef bancodepalabras
#define bancodepalabras
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Listas.h"
using namespace std;

LinkedList palabras(){
    string palabras [] = {"RADIO","SALTO","MARTE","PODER","RELOJ","CALOR","MEDIA","TEMOR","JUGAR","PUMAS","MIRAR", "TAPAR", "CIELO", "LUCES", "NADIE", "NUNCA", "GAFAS", "CEJAS", "OREJA", "FALTA"};
    LinkedList llp = LinkedList();
    srand(time(0));
    int random = 0;
    random = rand() % 20;
    string txt = palabras[random];
    for (int i = 5; i > -1; i -= 1){
        string s = "";
        s = txt[i];
        llp.add_at_head(s);
    }
    return llp;
}

#endif