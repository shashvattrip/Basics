#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node {
  int info;
  struct node *next;
}*last;

class circular_list{
  private:

   public:
    circular_list() {
      last = NULL;
    }
    void create_node(int value);
    void add_begin(int value);
    void add_after(int value,int position);
    void delete_element(int value);
    void search_element(int value);
    void display_list();
    void update();
    void sort();
};



int main() {
  int choice, nodes, element, position, i;
  circular_list cl;
  last = NULL;
  while(1) {
    cout<<endl<<"---------------------------"<<endl;
    cout<<endl<<"Circular singly linked list"<<endl;
    cout<<endl<<"---------------------------"<<endl;     
    cout<<"1.Create Node"<<endl;
    cout<<"2.Add at beginning"<<endl;
    cout<<"3.Add after"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Search"<<endl;
    cout<<"6.Display"<<endl;
    cout<<"7.Update"<<endl;
    cout<<"8.Sort"<<endl;
    cout<<"9.Quit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1:
        cout<<"Enter the element: ";
        cin>>element;
        cl.create_node(element);
        cout<<endl;
        break;
      case 2:
        cout<<"Enter the element: ";
        cin>>element;
        cl.add_begin(element);
        cout<<endl;
        break;
      case 3:
        cout<<"Enter the element: ";
        cin>>element;
        cout<<"Insert element after position: ";
        cin>>position;
        cl.add_after(element, position);
        cout<<endl;
        break;
      case 4:
        if (last == NULL)
        {
        cout<<"List is empty, nothing to delete"<<endl;
        break;
        }
        cout<<"Enter the element for deletion: ";
        cin>>element;
        cl.delete_element(element);
        cout<<endl;
        break;
      case 5:
        if (last == NULL)
        {
        cout<<"List Empty!! Can't search"<<endl;
        break;
        }
        cout<<"Enter the element to be searched: ";
        cin>>element;
        //cl.search_element(element);
        cout<<endl;
        break;
      case 6:
        cl.display_list();
        break;
      case 7:
        //cl.update();
        break;
      case 8:
        cl.sort();
        break;                      
      case 9:
        exit(1);
        break;
        default:
        cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
}

void circular_list::create_node(int value) {
  struct node *temp;
  temp = new struct node;
  temp->info = value;
  if(temp == NULL) {
    cout<<"Out of memory!\n";
    return;
  }
  if(last == NULL) {
    last = temp;
    temp->next = last;
  } else {
    temp->next = last->next;
    last->next = temp;
    last = temp;
  }

}

void circular_list::add_begin(int value) {
  struct node *temp;
  temp = new struct node;
  temp->info = value;
  if(temp == NULL) {
    cout<<"Out of memory\n";
    return;
  }

  if(last == NULL) {
    temp->next = last;
    last = temp;
  } else {
    temp->next = last->next;
    last->next = temp;
  }

}

void circular_list::add_after(int value,int position) {
  if(last == NULL) {
    cout<<"Circular list is empty!\n";
    return;
  }
  struct node *p,*temp;
  int counter;
  temp = new (struct node);
  temp->info = value;
  p = last;
  counter = 0;
  while(counter < position) {
    p = p->next;
    counter++;
  }

  temp->next = p->next;
  p->next = temp;
  
}


void circular_list::delete_element(int value) {
  struct node *temp,*p;
  if(last == NULL) {
    cout<<"List is empty!\n";
    return;
  }

  //if deletion of first element
  if(last->next->info == value) {
    temp = last->next;
    last->next = temp->next;
    free (temp);
  }

  p = last->next;

  while(p->next != last) {
    if(p->next->info == value){
      //delete this element
      temp = p->next;
      p->next = temp->next;
      delete temp;
    }
    p = p->next;
  }

  //if deletion of last element
  if(p->next->info == value) {
    temp = p->next;
    p->next = temp->next;
    free (temp);
    last = p;
  }
}

void circular_list::sort() {
  int temp;
  struct node *p, *s;
  if(last == NULL) {
    cout<<"The circular list is empty! Nothing to sort\n";
    return;
  }
  p = last->next;
  while(p != last) {
    for(s = p->next ; s != last->next ; s = s->next) {
      if(p->info > s->info) {
        temp = p->info;
        p->info = s->info;
        s->info = temp;
      }
    }
    p = p->next;
  }

  //put the last element in the right place
}

void circular_list::display_list() {
  if(last == NULL) {
    cout<<"The list is empty\n";
  }
  struct node *iter;
  iter = last->next;
  while(iter != last){
    cout<<iter->info<<"-->";
    iter = iter->next;
  }
  cout<<iter->info;
  cout<<"\n";
}




