#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
  int value;
  struct Node * next;
  struct Node * prev;
};
void insert(int val);
void search(int val);
void deleteNode(int val);
void swap(int x,int y);
void print();

struct Node * start = NULL;
int main(int argc, char const * argv[]) {
  /* code */
  print();
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  print();
  search(10);
  search(20);
  search(30);
  search(40);
  search(50);
  search(100);
  print();
  cout << "After Swapping" << endl;
  // swap(10,20);
  // swap(20,30);
  swap(40,50);
  // swap(10,30);
  // swap(10,50);
  
  print();
  
  system("pause");
  return 0;
}

void insert(int val) {
  struct Node * ptr;
  ptr = (struct Node *) malloc(sizeof(struct Node));
  ptr -> next = NULL;
  ptr -> prev = NULL;
  ptr -> value = val;

  if (start == NULL) {
    start = ptr;
  } else {
    struct Node * curr = start;
    while (curr -> next != NULL) {
      curr = curr -> next;
    }
    curr -> next = ptr; 
    ptr -> prev = curr;
  }
}

void search(int val) {
  if (start == NULL) {
    cout << "List is Empty" << endl;
  } else {
    int temp = 0;
    struct Node * curr = start;
    while (curr != NULL) {
      if (curr -> value == val) {
        temp++;
        break;
      }
      curr = curr -> next;
    }

    if (temp > 0) {
      cout << "Found in List" << endl;
    } else {
      cout << "Not Found" << endl;
    }
  }
}

void deleteNode(int val){
  if(start == NULL){
    cout << "List is Empty" << endl; 
  }else{
    struct Node *curr = start;
    if(curr->value == val){
      start = start->next;
      start->prev = NULL;
      cout << "Deleted : " << curr->value << endl;
      free(curr);
    }else{  
      curr = curr->next;
      struct Node *prev = start;
      while(curr->value != val){
        curr = curr->next;
        prev = prev->next;
      }
      if(curr->value == val){
          prev->next = curr->next;
          (curr->next)->prev = prev;
          cout << "Deleted : " << curr->value << endl; 
          free(curr);
      }else{
        cout << "Value Not Found" << endl;
      } 
    }
  }
}

void swap(int x,int y){
  // Search for X and Y
  struct Node *prevX = NULL;
  struct Node *currX = start;
  while(currX->value != x){
    prevX = currX;
    currX = currX->next; 
  }

  struct Node *prevY = NULL;
  struct Node *currY = start;
  while(currY->value != y){
    prevY = currY;
    currY = currY->next;
  }

  // Now We Will Swap Nodes
  struct Node *tempY = currY->next;
  if(currX->next == currY){
    // When Two Consecutive Nodes
    if(prevX == NULL){
        currY->prev = NULL;
    }else{
        currY->prev = prevX;
    }

    if(tempY == NULL){
        currX->next = NULL;
    }else{
        currX->next = tempY;
        tempY->prev = currX;
    }
        currY->next = currX;
        currX->prev = currY;

        if(prevX != NULL){
        prevX->next = currY;
        }else{
        start = currY;
        }
    
  }else{
      struct Node *tempX = currX->next;
      if(tempY == NULL){
        // When Node is stard and end
        currY->next = currX->next;
        currX->next = NULL;
        currY->prev = NULL;
        tempX->prev = currY;
      }else{
        // When Node is start,internal or End
        currY->next = currX->next;
        currX->next = tempY;
        tempY->prev = currX;
        tempX->prev = currY;
      }

      // Now we will set our start Node
      if(prevX != NULL){
        prevX->next = currY;
      }else{
        start = currY;
      }
      
      if(prevY != NULL){
        prevY->next = currX;
      }else{
        start = currX;
      }
  }


}

void print() {
  if (start == NULL) {
    cout << "List is Empty" << endl;
  } else {
    struct Node * curr = start;
    while (curr != NULL) {
      cout << curr -> value << endl;
      curr = curr -> next;
    }
  }
}