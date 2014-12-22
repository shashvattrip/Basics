//Print Left View of a Binary Tree
//http://www.geeksforgeeks.org/print-left-view-binary-tree/
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

void leftView(struct node *root);
void printPostOrder(struct node *root);
int main() {
  struct node *root = newNode(12);
  root->left = newNode(10);
  root->left->left = newNode(22);
  root->left->right = newNode(44);
  root->right = newNode(30);
  root->right->left = newNode(25);
  root->right->right = newNode(40);
  printPostOrder(root);
  cout<<endl<<endl;
  leftView(root);
  cout<<endl;
  return 0;
}

void leftView(struct node *root) {
  if(root == NULL){
    return;
  }
  if(root->left != NULL) {
    cout<<root->left->data<<endl;
  }
  leftView(root->left);
  leftView(root->right);
}

void printPostOrder(struct node *head) {
  if(head == NULL) {
    return;
  }
  printPostOrder(head->left);
  printPostOrder(head->right);
  cout<<head->data<<"--";
}

