//http://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/
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

void printNoSibling(struct node *head);
int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->right = newNode(4);
  root->right->left = newNode(5);
  root->right->left->left = newNode(6);
  printNoSibling(root);
  cout<<endl;
  return 0;
}


void printNoSibling(struct node *head) {
  if(head == NULL) {
    return;
  } else {
    if((head->left != NULL) && (head->right != NULL)) {
      printNoSibling(head->left);
      printNoSibling(head->right);
    } else if((head->left != NULL)) {
      cout<<head->left->data;
      printNoSibling(head->left);
    } else if(head->right != NULL) {
      cout<<head->right->data;
      printNoSibling(head->right);
    }   
  }
}

