#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data) {
  struct node *temp = new (struct node);
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->right = newNode(4);
  root->right->left = newNode(5);
  root->right->left->left = newNode(6);
  cout<<endl;
  return 0;
}
