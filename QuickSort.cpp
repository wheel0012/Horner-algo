#include <iostream>
template<typename T>
class QuickSort
{
    public:
    QuickSort()
    {
    }
    T* Sort(T* arr, int length)
    {
        T* left;
        T* right;
    }

    int Length()
    {return this->length;}
    private:
    int length;
    
};
/*
template<typename T>
class List
{
    /*
    void Add(T val)
    {
        Node* temp = new Node<T>();
        temp->Value = val;
        temp->prevNode = this;
        this->nextNode = temp;
    }
    void Del(int index)
    {
        for(int i = 0; i< index; i++)
        {

        }
    }
    static void RemoveAt(int index)
    {
    }
    private:
    int index;
    List(int size, T initialValue)
    {
        Node<T> *temp = new Node<T>(initialValue)
        for(int i = 0; i< size; i++)
        {
            Node<T> *temp = new Node<T>()
        }
    }
    int Length()
    {
        return this->length;
    }
    private:
    int length;
    
};*/
template<typename T>
class Node
{
    private:
    Node* prevNode;
    Node* nextNode;
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
};
int main()
{
    int arr[10] = {1,5,2,9,4,6,2,4,3,7};
    Node<int>* node1 = new Node<int>(5);
    Node<int>* node2 = new Node<int>(node1, 10);
    std::cout<<node1->Value<<std::endl;
    std::cout<<node1->Next()->Value<<std::endl;
    std::cout<<"--------------"<<std::endl;
    Node<int>* node3 = new Node<int>(node1, 7, node2);
    std::cout<<node3->Prev()->Value<<std::endl;
    std::cout<<node3->Value<<std::endl;
    std::cout<<node3->Next()->Value<<std::endl;
}