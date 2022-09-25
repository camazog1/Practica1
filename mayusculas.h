#ifndef mayusculas
#define mayusculas
#include <iostream>
using namespace std;

void mayuscula(string &txt){
  for (int i = 0; i < txt.size(); i += 1){
    txt[i] = toupper(txt[i]);
  }
}

#endif