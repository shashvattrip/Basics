#include<stdio.h>
#include<string>
using namespace std;

class Stack {

  private:
    int top;
    int capacity;
    int *storage;

  public:
    Stack(int capacity) {
      if(capacity<=0) {
        throw string("Capacity must be greater than 0\n");
      }
      storage = new int[capacity];
      this->capacity = capacity;
      top = -1;
    }

    
    void push(int value) {
      if(top == capacity) {
        throw string("No more space left! Pop some elements before inserting new ones\n");
      }
      top++;
      storage[top] = value;
    }

    int pop() {
      if(top == -1) {
        throw string("The stack is empty! Cannot pop!");
      }
      top--;
      return storage[top+1];
    }

    int peek() {
      if(top == -1) {
        throw string("The stack is empty! Cannot peek!");
      }
      return storage[top];
    }

    int size(){
      return capacity;
    }

    bool isEmpty(){
      if(top == -1) {
        return true;
      } else {
        return false;
      }
    }
  
    void viewAll() {
      for(int i=0;i<=top;i++) {
        printf("%d\n",storage[i]);
      }
      printf("\n");
    }

    ~Stack() {
      delete[] storage;
    }

};

int main() {
  printf("Begining Stack Implementation\n");
  Stack s(10);
  s.push(2);
  s.push(12);
  s.push(44);
  s.push(57);
  s.viewAll();
  return 0;
}
