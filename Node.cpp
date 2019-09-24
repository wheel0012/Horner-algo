#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          Node *node = new Node(data);
          if(head == NULL)
          {
              return node;
          }
          else
          {
              Node* temp = next(head);
              for(;;)
              {
                  if(temp != NULL)
                    temp = next(temp);
                  else {
                    head->next = node;
                    cout<<temp->data;
                    break;
                  }
                  cout<<"for1";
              }
              //head->next = node;
              return head;
          }
          //Complete this method
      }
      Node* next(Node* node)
      {
          return node->next;
      }
      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
	cout<<head->next->next->data;
}