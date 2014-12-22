//Incomplete!!!
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

class TreeOps {
  public:
    struct node* newNode(int data);
    struct node* insert(struct node *head,int data);
    void printPostOrder(struct node *head);
    void printInOrder(struct node *head);
};

void printDistanceFromLeaf(struct node *head,int distance);

int main() {
  TreeOps tree;
  
  struct node *head;
  int choice = 1,data;
  cout<<"Create a tree\n";
  while(choice == 1) {
    cout<<"Enter element to insert in the tree\n";
    cin>>data;
    head = tree.insert(head,data);
    cout<<"\n1.Continue adding more elements\n";
    cout<<"2.Done inserting elements\n";
    cin>>choice;
  }

  cout<<"\n********Print postOrder*********\n";
  tree.printPostOrder(head);
  cout<<"\n********Print InOrder*********\n";
  tree.printInOrder(head);
  cout<<endl;

  printDistanceFromLeaf(head,2);
  cout<<endl;
  return 0;
}

void distanceFromLeaf(struct node *node,int path[],bool visited[],int pathLen,int k){
  if(node == NULL) {
    return;
  }
  path[pathLen] = node->data;
  visited[pathLen] = false;
  pathLen++;
 
  //its a leaf node
  if(node->left == NULL && node->right == NULL && pathLen-k-1 >=0 && visited[pathLen-k-1] == false) {
    cout<<path[pathLen-k-1]<<" ";
    visited[pathLen-k-1] = true;
    return;
  }
 //recruse till you find a leaf node 
  distanceFromLeaf(node->left,path,visited,pathLen,k);
  distanceFromLeaf(node->right,path,visited,pathLen,k);
}

void printDistanceFromLeaf(struct node *head,int distance) {
  int path[1000];
  bool visited[1000] = {false};
  distanceFromLeaf(head,path,visited,0,distance);
}

struct node* TreeOps::newNode(int data) {
  struct node *p;
  p = new (struct node);
  if(p == NULL) {
    cout<<"No memory\n";
    return 0;
  }
  p->data = data;
  p->left = NULL;
  p->right = NULL;
  return p;
}

struct node* TreeOps::insert(struct node *node,int data) {
  struct node *p;
  p = newNode(data);
  if(node == NULL) {
    node = p;
    return node;
  }
  if(data <= node->data)
    node->left = insert(node->left,data);
  else
    node->right = insert(node->right,data);
  return node;
}

void TreeOps::printPostOrder(struct node *head) {
  if(head == NULL) {
    return;
  }
  printPostOrder(head->left);
  printPostOrder(head->right);
  cout<<head->data<<"--";
}

void TreeOps::printInOrder(struct node *head) {
  if(head == NULL) {
    return;
  }
  printInOrder(head->left);
  cout<<head->data<<"->";
  printInOrder(head->right);
}

