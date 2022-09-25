#ifndef crearlli
#define crearlli
#include <iostream>
#include "Listas.h"
using namespace std;

LinkedList crear_lli(string txt){
    LinkedList lli = LinkedList();
    for (int i = 5; i > -1; i -= 1){
        string s = "";
        s = txt[i];
        lli.add_at_head(s);
    }
    return lli;
};

#endif