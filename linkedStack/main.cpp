#include<iostream>

using namespace std;

class Stacknode{ 
          public:

          int data ;
          Stacknode* prev;

          Stacknode( int _data){  
                    data=_data;
                    prev=NULL;
          }
          ~Stacknode(){}
};

class Linkednode{  
          public:
          Stacknode* tail;
          int counter;
          
          Linkednode(){  
                    tail=NULL;
                    counter=0;
          }

          void push( int _data){ 
                    Stacknode* newnode= new Stacknode (_data);
                    if(tail == NULL ){ 
                              tail = newnode;
                              return ;
                    }
                    newnode->prev=tail;
                    tail=newnode;
                    counter++;
          }

          int pop(){ 
                    Stacknode* temp =NULL;
                    int data=0;
                    if(tail == NULL){ 
                              delete temp;
                              return 0;
                    }
                    temp =tail;
                    tail =tail->prev;
                    data=temp->data;
                    delete temp;
                    return data;
                    counter--;
          }
          int peek(){ 
                    int data = 0;
                    if(tail == NULL){ 
                              cout<<"Not data yet \t"<<endl;
                              return 0;
                    }
                    data = tail->data;
                    cout<<"data \t"<<data<<endl;
                    return data;

          }
          void display(){ 
                    Stacknode* current =tail;
                    if(current == NULL){ 
                              delete current;
                              cout<<"LInked empty"<<endl;
                              return ;
                    }
                    while(current != NULL){ 
                             
                              cout<<current->data<<"\t";
                              current = current->prev;
                    }
          }


          int getcounter(){ 
                    return counter;
          }

};






int main(){ 

Linkednode l;

l.push(1);
l.push(2);
l.push(3);
l.push(4);
l.push(5);
l.pop();
l.pop();
l.pop();
l.pop();
l.pop();
l.pop();
l.peek();

l.display();


          return 0;
}
