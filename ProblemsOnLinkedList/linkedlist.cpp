#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node {
  int info;
  struct node *next;
}*start;

class single_list {
  private:

   public:
    single_list() {
      start = NULL;
    }
    node* create_node(int);
    void insert_begin();
    void insert_pos();
    void insert_last();
    void delete_pos();
    void sort();
    void search();
    void update();
    void reverse();
    void display();
    void deleteList();
};



int main() {
  int choice, nodes, element, position, i;
  single_list sl;
  start = NULL;
  while (1){
    cout<<endl<<"---------------------------------"<<endl;
    cout<<endl<<"Operations on singly linked list"<<endl;
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"1.Insert Node at beginning"<<endl;
    cout<<"2.Insert node at last"<<endl;
    cout<<"3.Insert node at position"<<endl;
    cout<<"4.Sort Link List"<<endl;
    cout<<"5.Delete a Particular Node"<<endl;
    cout<<"6.Update Node Value"<<endl;
    cout<<"7.Search Element"<<endl;
    cout<<"8.Display Linked List"<<endl;
    cout<<"9.Reverse Linked List "<<endl;
    cout<<"10.Delete List "<<endl;
    cout<<"11.Exit "<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice) {
      case 1:
        cout<<"Inserting Node at Beginning: "<<endl;
        sl.insert_begin();
        cout<<endl;
        break;
      case 2:
        cout<<"Inserting Node at Last: "<<endl;
        sl.insert_last();
        cout<<endl;
        break;
      case 3:
        cout<<"Inserting Node at a given position:"<<endl;
        sl.insert_pos();
        cout<<endl;
        break;
      case 4:
        cout<<"Sort Link List: "<<endl;
        sl.sort();
        cout<<endl;
        break;
      case 5:
        cout<<"Delete a particular node: "<<endl;
        sl.delete_pos();
        break;
      case 6:
        cout<<"Update Node Value:"<<endl;  
        //sl.update();
        cout<<endl;
        break;
      case 7:
        cout<<"Search element in Link List: "<<endl;
        //sl.search();
        cout<<endl;
        break;
      case 8:
        cout<<"Display elements of link list"<<endl;
        sl.display();
        cout<<endl;
        break;
      case 9:
        cout<<"Reverse elements of Link List"<<endl;
        sl.reverse();
        cout<<endl;
        break;
      case 10:
        sl.deleteList();
        break;
      case 11:
        cout<<"Exiting..."<<endl;
        exit(1);
        break;  
        default:
        cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
}

node* single_list::create_node(int value) {
  struct node *temp;
  temp = new struct node;
  if(temp == NULL) {
    cout<<"Not enough memory!\n";
    return 0;
  }
  temp->info = value;
  temp->next = NULL;
  return temp;
}


void single_list::insert_begin() {
  int value;
  cout<<"Enter the value of the node\n";
  cin>>value;
  struct node *temp, *ptr;
  temp = create_node(value);
  if(temp == 0) {
    return;
  } else {
    if(start == NULL) {
      start = temp;
      start->next = NULL;
    } else {
      ptr = start;
      start = temp;
      start->next = ptr;
    }
  }
  cout<<"Element inserted in the begining\n";
}


void single_list::insert_last() {
  int value;
  cout<<"Enter the value\n";
  cin>>value;
  struct node *temp, *iter;
  temp = create_node(value);
  if(temp == 0) {
    return;
  } else {
    if(start == NULL) {
      start = temp;
    } else {
      iter = start;
      while(iter->next != NULL) {
        iter = iter->next;
      }
      iter->next = temp;
    }
  }
}


void single_list::insert_pos() {
  int value,pos;
  cout<<"Enter the value of the node\n";
  cin>>value;
  cout<<"Enter the position to insert the node at\n";
  cin>>pos;
  struct node *temp,*p,*s;
  temp = create_node(value);
  if(temp == 0) {
    return;
  } else {
    //assume right position is entered
    if(pos == 1) {
      //insert in the begining
      p = start;
      start = temp;
      start->next = p;
    } else {
      int counter = 1;
      p = start;
      while(counter < pos) {
        p = p->next;
        counter++;
      }
      temp->next = p->next;
      p->next = temp;
    }
  }
  
}


void single_list::delete_pos() {
  int pos,counter;
  struct node *temp,*p;
  cout<<"Enter the position of the node to delete\n";
  cin>>pos;
  if(start == NULL) {
    cout<<"Linked list is empty\n";
    return;
  } 
  if(pos == 1) {
    temp = start;
    start = start->next;
    delete temp;
  } else {
    temp = start;
    counter = 1;
    while(counter < pos - 1) {
      temp = temp->next;
      counter++;
    }
    //now temp is pointing to the node that needs to be deleted
    p = temp->next;
    temp->next = p->next;
    delete p;
  }
}

//use insertion sort to sort

void single_list::sort() {
  struct node *p,*s;
  int temp;
  if(start == NULL) {
    cout<<"List is empty! Nothing to sort!\n";
  }
  
  p = start;

  while(p != NULL) {
    for(s = p->next;s != NULL;s = s->next) {
      if(p->info > s->info) {
        temp = p->info;
        p->info = s->info;
        s->info = temp;
      }
    }
    p = p->next;
  }
}


void single_list::reverse() {
  struct node *prev, *current, *next;
  prev = NULL;
  current = start;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  start = prev;

}


void single_list::display() {
  struct node *temp;
  temp = start;
  cout<<"Displaying the linkedList\n";
  if(!start) {
    cout<<"Linked List is empty\n";
    return;
  }

  while(temp) {
    cout<<temp->info<<"::";
    temp = temp->next;
  }
}


void single_list::deleteList() {
  struct node *temp,*iter;
  iter = start;

  while(iter != NULL) {
    temp = iter->next;
    free (iter);
    iter = temp;
  }
  start = NULL;
}





