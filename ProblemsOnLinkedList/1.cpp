#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node {
  int info;
  struct node *next;
};


node* create_node(int value) {
  struct node *p;
  p = new (struct node);
  if(p == NULL) {
    cout<<"Not enough memory\n";
    return 0;
  }
  
  p->info = value;
  p->next = NULL;
  return p;
}

struct node* add_node(struct node *head, int value) {
  struct node *p,*temp;
  p = create_node(value);
  if(head == NULL) {
    p->info = value;
    p->next = NULL;
    head = p;
    return head;
  }
  temp = head;
  head = p;
  head->next = temp;
  return head;
}

void display(struct node *head) {
  struct node *p;
  p = head;
  while(p != NULL) {
    cout<<p->info<<"->";
    p = p->next;
  }
  cout<<"\n";
}

//to initialize the two digit-pointers
void init(struct node **first,struct node **second) {

  *first = create_node(5);
  *first = add_node(*first,1);
  *first = add_node(*first,4);
 // *first = add_node(*first,8);

  *second = create_node(2);
  *second = add_node(*second,9);
  *second = add_node(*second,3);
  //*second = add_node(*second,1);
  //*second = add_node(*second,9);
  //*second = add_node(*second,7);
}

struct node* sum(struct node *first, struct node *second) {
  int sum = 0, carry = 0;
  struct node *temp1,*temp2, *answer, *answerTemp;
  answer = NULL;
  temp1 = first;
  temp2 = second;

  while((temp1 != NULL) || (temp2 != NULL)) {
    sum = (((temp1->info + temp2->info) % 10) + carry) % 10;
    carry = (temp1->info + temp2->info) / 10;
    answer = add_node(answer,sum);
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  return answer;

}

int main() {
  struct node *first,*second,*temp1,*temp2,*answer;
  first = NULL;
  second = NULL;
  answer = NULL;

  init(&first,&second);
  display(first);
  display(second);

  answer = sum(first,second);
  display(answer);
  return 0;
}
