#ifndef Listas
#define Listas
#include <iostream>
#include "color.h"
using namespace std;

class Node {
public:
  string value;
  Node *next;
  string colores;
  Node(string value) {
    this->value = value;
    this->next = NULL;
    this->colores = "default";
  }
};
class LinkedList {
public:
  Node* head = NULL;

  void add_at_head(string value){
    Node* new_node = new Node(value); 
    if(this->head == NULL)
    {
      this->head = new_node;
    }
    else
    {
      Node* aux_node = this->head;
      new_node->next = aux_node;
      this->head = new_node;
    }
  }

  void traverse() {
    Node* current_node = this->head;
    while (current_node != NULL) {
      cout << current_node->value;
      current_node = current_node->next;
    }
    cout << endl;
  };
  void colorear(){
    Color::Modifier verde(Color::FG_GREEN);
    Color::Modifier amarillo(Color::FG_YELLOW);
    Color::Modifier def(Color::FG_DEFAULT);
    Node* current_node = this->head;

    for (int i = 0; i < 5; i += 1){
      if(current_node->colores == "verde"){
        cout << verde << current_node->value << def;
      }
      else if (current_node->colores == "amarillo"){
        cout << amarillo << current_node->value << def;
      }
      else{
        cout << def << current_node->value;
      }
      current_node = current_node->next;
    }
    cout << def << endl;
  }
  LinkedList comparar (LinkedList lli){
    LinkedList aux = lli;
    Node* curr = this->head;
    Node* curr2 = aux.head;
    for(int i = 0; i < 6; i += 1){
      curr2 = aux.head;
      for (int j = 0; j < 6; j += 1){
        if (curr->value == curr2->value){
          if (i == j){
            curr2->colores = "verde";
          }
          else {
            if (curr2->colores != "verde"){
              curr2->colores = "amarillo";
            }
          }
        }
        curr2 = curr2->next;
      }
      curr = curr->next;
    }
    return aux;
  }
  void ponerrojo(){
    Color::Modifier rojo(Color::FG_RED);
    Node* current_node = this->head;
    while (current_node != NULL) {
      cout << rojo << current_node->value;
      current_node = current_node->next;
    }
    cout << endl;
  }

  bool compararigualdad(){
    Node* current_node = this->head;
    while (current_node != NULL) {
      if (current_node->colores != "verde"){
        return false;
      }
      current_node = current_node->next;
    }
    return true;
  }
};

#endif