#include <iostream>
#include<stdlib.h>
using namespace std;
class link{
public:
    int a;
     link *next;
};
void pop();
void insert(int val);
void deleteit(int value);
void display();
void addbeginning(int value);
link *head;
int main()
{
    head=NULL;
      while(1)
    {

    cout<<"Options .:\n 1. Add \n 2. Delete \n 3. Display\n 4. Pop \n 5. Insert at Beginning\n";
    int choice;
    int content;
    cin>>choice;

    switch(choice)
    {
    case 1:
         cout<<"Enter the Number : ";
         cin>>content;
         insert(content);
         break;
    case 2:
         cout<<"Enter the Number : ";
         cin>>content;
         deleteit(content);
         break;
    case 3:
        cout<<"Numbers are \n";
         display();
         break;
    case 4:
         pop();
         break;
    case 5:
         cout<<"Enter the Number : ";
         cin>>content;
         addbeginning(content);
         break;
    default:
         cout<<"Wrong Option";
         break;
    }
    }
}
void pop()
{
    if(head!=NULL)
    head=head->next;
}
void deleteit(int value)
{
    link *a=head;
    link *b=NULL;
    //cout<<a->a;
 while(a!=NULL)
 {
     //cout<<a->a;
    if(a->a==value && b!=NULL)
    {
     b->next=a->next;
    }
    else if(a->a==value && b==NULL)
    { head=head->next;
        //head=a->next;
        //free(head);
    }
    b=a;
    a=a->next;

 }

}
void insert(int val)
{

    link *a=new link;
    a->next=head;
    a->a=val;
    head=a;
}
void display()
{
 link *a=head;
 while(a!=NULL)
 {
    cout<<a->a<<"\n";
    a=a->next;
 }
}
void addbeginning(int value)
{
 link *a=head;
 if(a==NULL)
 {
    // cout<<a->a;
        link *b=new link;
        b->next=NULL;
        b->a=value;
        head=b;
 }
 while(a!=NULL)
 {
    if(a->next==NULL)
    {
       // cout<<a->a;
        link *b=new link;
        b->next=NULL;
        b->a=value;
        a->next=b;
        break;
    }
    a=a->next;

 }
}
