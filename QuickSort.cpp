#include <iostream>
#include <vector>
template<typename T>
class QuickSort
{
    private:
    int length;
    
    public:
    QuickSort()
    {
    }
    void Sort(T* arr, int length)
    {
        T* left;
        T* right;


    }

    int Length()
    {return this->length;}
    
    
};


template<typename T>
class Node
{
    private:
    Node* prevNode = NULL;
    Node* nextNode = NULL;
    public:
    T Value;
    Node(Node *prev, T value)
    {
        this->prevNode = prev;
        this->Value = value;
        prev->nextNode = this;
    }
    Node(T value)
    {
        this->Value = value;
    }
    //Add node between two nodes
    Node(Node *prev, T value, Node* next)
    {
        //value inital
        this->Value = value;
        //Setting prev node;
        this->prevNode = prev;
        prev->nextNode = this;
        //Setting next node;
        this->nextNode = next;
        next->prevNode = this;
    }
    Node<T>* Next()
    {
        return nextNode;
    }
    Node<T>* Prev()
    {
        if(prevNode!=NULL)
            return prevNode;
        else return nullptr;
    }
    void SetNext(Node<T> *node)
    {
        if(this->nextNode == NULL)
        {
            this->nextNode = node;
        }
        else
        {
            Node<T> *temp = this->nextNode;
            this->nextNode = node;
            temp->prevNode = node;
        }
    }
};
template<typename T>
class LinkedList
{
    private:
    Node<T>* header;
    Node<T>* currNode;
    int count;
    int length;
    public:
    LinkedList()
    {    }
    LinkedList(T item, ...)
    {
        
    }
    void Add(Node<T>* item)
    {
        if(this->header == NULL)
        {
            this->header = item;
            this->currNode = header;
            this->length = 0;
        }
        else
        {
            this->currNode->SetNext(item);
            this->currNode = this->currNode->Next();
            length++;
        }
    }
    void Add(T value)
    {
        auto node = new Node<T>(value);
        if(this->header == NULL)
        {
            this->header = node;
            this->currNode = header;
            this->length = 0;
        }
        else
        {
            this->currNode->SetNext(node);
            this->currNode = this->currNode->Next();
            length++;
        }
    }
    int Length()
    {
        return this->length;
    }
    void Display()
    {
        Node<T>* head = this->header;
        while(head != NULL)
        {
            std::cout<<head->Value<<std::endl;
            head = head->Next();
        }

    }
};
int main()
{
    int arr[10] = {1,5,2,9,4,6,2,4,3,7};
    Node<int>* node1 = new Node<int>(5);
    Node<int>* node2 = new Node<int>(6);
    LinkedList<int> *list = new LinkedList<int>();
    list->Add(node1);
    list->Add(node2);
    list->Add(10);
    list->Display();
}