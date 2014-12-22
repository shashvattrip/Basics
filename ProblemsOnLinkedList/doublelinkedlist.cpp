#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct node {
  int info;
  struct node *next;
  struct node *prev;
}*start;

class double_llist{
  public:
    double_llist() {
      start = NULL;
    }
    void create_list(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void search_element(int value);
    void display();
    void count();
};


int main() {
  int choice, element, position;
  double_llist dl;
  while (1){
    cout<<endl<<"----------------------------"<<endl;
    cout<<endl<<"Operations on Doubly linked list"<<endl;
    cout<<endl<<"----------------------------"<<endl;         
    cout<<"1.Create Node"<<endl;
    cout<<"2.Add at begining"<<endl;
    cout<<"3.Add after position"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Count"<<endl;
    cout<<"7.Reverse"<<endl;
    cout<<"8.Quit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch ( choice )
    {
      case 1:
        cout<<"Enter the element: ";
        cin>>element;
        dl.create_list(element);
        cout<<endl;
        break;
      case 2:
        cout<<"Enter the element: ";
        cin>>element;
        dl.add_begin(element);
        cout<<endl;
        break;
      case 3:
        cout<<"Enter the element: ";
        cin>>element;
        cout<<"Insert Element after postion: ";
        cin>>position;
        dl.add_after(element, position);
        cout<<endl;
        break;
      case 4:
        if (start == NULL)
        {                      
        cout<<"List empty,nothing to delete"<<endl;   
        break;
        }
        cout<<"Enter the element for deletion: ";
        cin>>element;
        dl.delete_element(element);
        cout<<endl;
        break;
      case 5:
        dl.display();
        cout<<endl;
        break;
        case 6:
        //dl.count();
        break;    
      case 7:
        if (start == NULL)
        {
        cout<<"List empty,nothing to reverse"<<endl;
        break;
        }
        //dl.reverse();
        cout<<endl;
        break;
      case 8:
        exit(1);
        default:
        cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
}

void double_llist::create_list(int value) {
  struct node *s,*temp;
  temp = new (struct node);
  if(temp == NULL) {
    cout<<"Out of memory\n";
    return;
  }
  temp->info = value;
  temp->next = NULL;
  if(start == NULL) {
    temp->prev = NULL;
    start = temp;
  } else {
    //add at the end
    s = start;
    while(s->next != NULL) {
      s= s->next;
    }
    s->next = temp;
    temp->prev = s;
  }
}



void double_llist::add_begin(int value) {
  struct node *p;
  p = new (struct node);
  if(p == NULL) {
    cout<<"Not enough memory\n";
    return;
  }
  p->info = value;
  p->prev = NULL;
  if(start == NULL) {
    p->next = NULL;
    start = p;
  } else {
    p->next = start;
    start->prev = p;
    start = p;
  }

}


void double_llist::add_after(int value, int pos) {
  struct node *p,*temp,*s;
  if(start == NULL) {
    cout<<"the list is empty!\n";
    return;
  }
  
  temp = new (struct node);
  if(temp == NULL) {
    cout<<"no memory\n";
    return;
  }
  temp->info = value;
  temp->next = NULL;
  temp->prev = NULL;
  
  p = start;
  int counter = 0;
  while(counter < pos) {
    p = p->next;
    counter++;
  }
  s = p->next;
  p->next = temp;
  temp->prev = p;
  temp->next = s;
  s->prev = temp;
}


void double_llist::delete_element(int value) {
  
}


void double_llist::display() {
  struct node *iter;
  iter = start;
  if(start == NULL) {
    cout<<"List is empty!\n";
    return;
  }
  cout<<"Displaying the list\n";
  while(iter != NULL) {
    cout<<iter->info<<"->";
    iter = iter->next;
  }
  cout<<"\n";
}

