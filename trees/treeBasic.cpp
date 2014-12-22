//Followed questions from http://cslibrary.stanford.edu/110/BinaryTrees.html"

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
    int lookup(struct node *root, int target);
    struct node* newNode(int data);
    struct node* insert(struct node *head,int data);
    void printPostOrder(struct node *head);
    void printInOrder(struct node *head);
    int size(struct node *head);
    int maxDepth(struct node *head);
    int minValue(struct node *head);
    int hasPathSum(struct node *head,int sum);
    void printPaths(struct node *head);
    void printPathsRecurr(struct node *node,int path[],int pathLen);
    void printArray(int ints[],int len);
    void mirror(struct node *head);
    void doubleTree(struct node *head);
};


int main() {
  int choice, nodes, element, position, i;
  struct node *head;
  class TreeOps tree;
  while (1){
    cout<<endl<<"---------------------------------"<<endl;
    cout<<endl<<"Operations on singly linked list"<<endl;
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Lookup"<<endl;
    cout<<"3.Size"<<endl;
    cout<<"4.Max Depth"<<endl;
    cout<<"5.Min Value"<<endl;
    cout<<"6.Print Post Order Tree"<<endl;
    cout<<"7.Print Tree"<<endl;
    cout<<"8.hasPathSum :"<<endl;
    cout<<"9.Print Paths"<<endl;
    cout<<"10.Mirror the Tree: "<<endl;
    cout<<"11.Exit "<<endl;
    cout<<"12.Double Tree "<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice) {
      case 1:  
      cout<<"Inserting Node "<<endl;
      cout<<"Enter the element\n";
      int value;
      cin>>value;
      head = tree.insert(head,value);
      cout<<endl;
      break;
      case 2:
      cout<<"Inserting Node at Last: "<<endl;
  //    sl.insert_last();
      cout<<endl;
      break;
      case 3:
      cout<<"Size of the tree is : "<<endl;
      cout<<tree.size(head);
      cout<<endl;
      break;
      case 4:
      cout<<"Max Depth: "<<endl;
      cout<<tree.maxDepth(head);
      cout<<endl;
      break;
      case 5:
      cout<<"Min Value: "<<endl;
      cout<<tree.minValue(head);
      cout<<endl;
      break;
      case 6:
      cout<<"Update Node Value:"<<endl;
      tree.printPostOrder(head);
      cout<<endl;
      break;
      case 7:
      cout<<"Print In order tree "<<endl;
      tree.printInOrder(head);
      cout<<endl;
      break;
      case 8:
      cout<<"Enter the sum of the path : "<<endl;
      cin>>value;
      cout<<tree.hasPathSum(head,value);
      cout<<endl;
      break;
      case 9:
      tree.printPaths(head);
      break;
      case 10:
      tree.mirror(head);
      break;
      case 11:
      cout<<"Exiting..."<<endl;
      exit(1);
      break;
      case 12:
      cout<<"Doubling the tree\n";
      tree.doubleTree(head);
      break;
      default:
      cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
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

int TreeOps::size(struct node *head) {
  if(head == NULL)
    return 0;
  else {
    return 1 + size(head->left) + size(head->right);
  }

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

int TreeOps::maxDepth(struct node *head) {
  if(head == NULL) {
    return 0;
  }

  int left = maxDepth(head->left);
  int right = maxDepth(head->right);

  return ((left>right)?(left+1):(right+1));
}

int TreeOps::minValue(struct node *head) {
  if(head == NULL) {
    return 0;
  }
  if(head->left == NULL) {
    return head->data;
  } else {
    minValue(head->left);
  }
}


int TreeOps::hasPathSum(struct node *head, int sum) {
  if(head == NULL) {
    return (sum == 0);
  } else {
    int subSum = sum - head->data;
    return hasPathSum(head->left,subSum) || hasPathSum(head->right,subSum);
  }

}


void TreeOps::printPaths(struct node *head) {
  int path[1000];
  printPathsRecurr(head,path,0);
  printArray(path,3);
}

void TreeOps::printPathsRecurr(struct node *node,int path[],int pathLen) {
  if(node == NULL) return;

  path[pathLen] = node->data;
  pathLen++;

  if(node->left == NULL && node->right) {
    printArray(path,pathLen);
  } else {
    printPathsRecurr(node->left,path,pathLen);
    printPathsRecurr(node->right,path,pathLen);
  }
}

void TreeOps::printArray(int ints[],int len) {
  for(int i=0;i<len;i++) {
    cout<<ints[i]<<" ";
  }
  cout<<endl;
}

void TreeOps::mirror(struct node *head) {
  if(head == NULL) {
    return;
  } else {
    struct node *temp;
    temp = head->left;
    head->left = head->right;
    head->right = temp;
    mirror(head->left);
    mirror(head->right);
  }
}


void TreeOps::doubleTree(struct node *head) {
  if(head == NULL) {
    return;
  } else {
    struct node *temp,*node;
    doubleTree(head->left);
    doubleTree(head->right);
    temp = head->left;
    node = newNode(head->data);
    head->left = node;
    node->left = temp;
  }
}



