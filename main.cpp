#include <iostream>
#include<windows.h>
using namespace std;
struct Node
{
    int id;
    string name;
    float gpa;
    Node *next;
    Node*prev;
} node ;
class LinkedList{
private:

    Node *l;
public:
     int Insert(int x,string y, float z);
        LinkedList();
     int PrintAll(void);
     int deleteValue(int x);
     int searchValue(int x);
     void Delete(){ l= NULL;}
};
LinkedList::LinkedList()
{
    l=NULL;
}


int LinkedList ::Insert(int x,string y, float z)
{
    Node *p;
    p=new Node;
    Node *k;
    Node *q;
    Node *j;
    if(p==NULL)
    {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
        cout<<" Error \n";
        return 0;
    }
    p->id=x;
    p->name=y;
    p->gpa=z;
      if(l==NULL)
      {
        p->prev=NULL;
        p->next=NULL;
        l=p;
        return 1;
      }
      {
          j=l;
          while(j!=NULL)
          {
              if((j->id)==(p->id))
              {
                  cout<<" This id is already exist \n"<<endl;
                  return 0;
              }
              j=j->next;
          }
      }

      k=l;
      q=k->next;

        while(k!=NULL)
        {
            if((p->id)<(k->id))
            {
                k->prev=p;
                p->next=k;
                p->prev=NULL;
                l=p;
                break;
            }
            if(((p->id)>(k->id))&&(k->next==NULL))
                {
                    k->next=p;
                    p->prev=k;
                    p->next=NULL;
                    break;
                }
              if(((p->id)>(k->id))&&((p->id)<(q->id)))
              {
                  k->next=p;
                  p->prev=k;
                  p->next=q;
                  q->prev=p;
                  break;
              }


                    k=q;
                    q=k->next;
        }
        return 1;
}
int LinkedList ::PrintAll(void)
{
    if(l==NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        cout<<" The list is empty \n";
        return 0;
    }
      Node *p;

      p=l;
      while(p!=NULL)
      {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
          cout<<(p->id)<<endl;
          cout<<(p->name)<<endl;
          cout<<(p->gpa)<<endl;

          p=p->next;
      }
      return 1;
}
int LinkedList::deleteValue(int x)
{
    Node *p;
    Node *q;
    Node *k;
    p=l;

    if(l==NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        cout<<" The list is empty there is nothing to remove \n";
        return 0;
    }
    if(p->id==x)
    {
        if(p->next==NULL)
        {
            delete(p);
            l=NULL;
            cout<<" The id exist in the list and deleted \n"<<endl;
            return 1;
        }
    }
    if(p->id==x)
    {
          if(p->prev==NULL)
        {
            q=p->next;
            delete(p);
            q->prev=NULL;
            l=q;
            cout<<" The id exist in the list and deleted \n"<<endl;
            return 1;
        }
    }

    while(p!=NULL)
    {
        if(p->id==x)
        {
            if(p->next!=NULL)
            {
                k=p->next;
                q->next=k;
                k->prev=q;
                delete(p);
                cout<<" The id exist in the list and deleted \n"<<endl;
                return 1;
            }
            else
            {
                q->next=NULL;
                delete(p);
                cout<<" The id exist in the list and deleted \n"<<endl;
                return 1;
            }
        }
        q=p;
        p=p->next;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    cout<<" The value is not exist in the list \n"<<endl;
    return 0;

}
int LinkedList ::searchValue(int x)
{
    Node *p;
    p=l;
    if (l==NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        cout<<" The list is empty ,no elements to search \n"<<endl;
        return 0;
    }
    while(p!=NULL)
    {
        if(p->id==x)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
          cout<<(p->id)<<endl;
          cout<<(p->name)<<endl;
          cout<<(p->gpa)<<endl;


            return 1;
        }
        p=p->next;

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    cout<<" That value not exist in tha list \n"<<endl;
    return 0;
}
int main()
{ int x;
    string name1;
    float gpa;
LinkedList s;
    index:
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
  cout<<"if you want to insert student enter 1"<<endl;
  cout<<"if you want to delete student enter 2"<<endl;
  cout<<"if you want to search student enter 3"<<endl;
  cout<<"if you want to display student enter 4"<<endl;
  cout<<"if you want to delete list enter 5"<<endl;
   cin>>x;
   switch(x)
   {
       case 1:{
        system("CLS");

            cout<<"Enter the Name"<<endl;
            cin>>name1;
            cout<<"Enter the id"<<endl;
            cin>>x;
            cout<<"Enter the gpa"<<endl;
            cin>>gpa;
        s.Insert(x,name1,gpa);
        system("CLS");
       } break;
       case 2:{
           system("CLS");
            cout<<"Enter the id"<<endl;
            cin>>x;
        s.deleteValue(x);
       } break;
       case 3: {
           system("CLS");
            cout<<"Enter the id"<<endl;
            cin>>x;
        s.searchValue(x);
       }break;
       case 4:  {s.PrintAll();
       }break;
       case 5: s.Delete();
   }
   goto index;

    return 0;
}
