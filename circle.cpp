#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node{
  int value;
  Node* next;
};

int main(){
  bool loop = true;
  while (loop){
    Node* current = new Node;
    int size, increment;
    cout << "Input the size of the circle and then the increment by which they will be removed" << endl;
    cin >> size;
    cin >> increment;
    Node* begin = current;
    for (int i = 1; i < size; i++){
      current->value = i;
      current->next = new Node;
      current = current->next;
    }
    current->value = size;
    current->next = begin;
    while (size > 1){
      for (int i = 0; i < increment-1; i++){
	current = current->next;
      }
      current->next = current->next->next;
      size--;
    }
    cout << "The last remaining member is " << current->value << endl;
    cout << "Run again? (enter 'y' or 'yes')" << endl;
    string s;
    cin >> s;
    if (s == "y" || s == "yes"){
      loop = true;
    }
    else{
      loop = false;
    }
  }
  return 1;
}

