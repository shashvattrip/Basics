#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*Following steps can be used to sort the given linked list.
1) Traverse the list and count the number of 0s, 1s and 2s. Let the counts be n1, n2 and n3 respectively.
2) Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1 and finally n3 nodes with 2.
*/

struct node{
  int info;
  struct node *next;
};

struct node* create_node(int value) {
  struct node *ptr;
  ptr = new (struct node);
  if(ptr == NULL) {
    cout<<"Not enough memory!\n";
    return 0;
  }
  ptr->info = value;
  ptr->next = NULL;
  return ptr;
}

void add_node(struct node **head, int value) {
  struct node *p,*temp;
  p = create_node(value);
  if(*head == NULL) {
    *head = p;
    return;
  }
  temp = *head;
  p->next = temp;
  *head = p;
}

void sort(struct node **head) {
  int countZero = 0, countOne = 0, countTwo = 0;
  struct node *iter;
  iter = *head;
  cout<<iter->info<<"\n\n\n";
  while(iter != NULL) {
    if(iter->info == 0) 
      countZero++;
    else if(iter->info == 1)
      countOne++;
    else 
      countTwo++;
    iter = iter->next;
  }
  cout<<countZero<<"\n\naaaaaaaaa\n\n";
  int total = countZero + countOne + countTwo;
  iter = *head;
  while(countZero) {
    iter->info = 0;
    iter = iter->next;
    countZero--;
  }
  while(countOne) {
    iter->info = 1;
    iter = iter->next;
    countOne--;
  }
  while(countTwo) {
    iter->info = 2;
    iter = iter->next;
    countTwo--;
  }

}

void display(struct node *head) {
  struct node *iter;
  iter = head;
  cout<<"Displaying the list\n";
  while(iter != NULL) {
    cout<<iter->info<<"->";
    iter = iter->next;
  }
  cout<<"\n";
}

int main() {
  struct node *head, *sorted;
  head = create_node(1);
  add_node(&head,2);
  add_node(&head,1);
  add_node(&head,2);
  add_node(&head,2);
  add_node(&head,1);
  add_node(&head,1);
  add_node(&head,0);
  add_node(&head,0);
  add_node(&head,0);
  add_node(&head,1);
  add_node(&head,2);
  add_node(&head,2);
  add_node(&head,0);
  add_node(&head,2);
  add_node(&head,0);
  add_node(&head,2);
  add_node(&head,0);
  add_node(&head,1);
  add_node(&head,2);
  add_node(&head,0);
  add_node(&head,2);
  add_node(&head,1);
  add_node(&head,0);
  display(head);
  sort(&head);
  display(head);
  return 0;
}



