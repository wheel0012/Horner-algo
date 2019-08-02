#include <iostream>
template<typename T>
class LinkedList
{
    LinkedList* nextAddr;
    public:
    T currentVal;
    LinkedList(T t)
    {
        this->currentVal = t;
    }
    LinkedList* Add(T t)
    {
        this->nextAddr =  new LinkedList(t);
        return this->nextAddr;
    }
    LinkedList* MoveNext()
    {
        return nextAddr;
    }
    void Delete()
    {
        
    }
    
};
int main()
{
    LinkedList<int>* ls = new LinkedList<int>(123);
    LinkedList<int>*  a = ls->Add(1234);
    LinkedList<int>* b = a ->Add(234);
    std::cout<<ls->MoveNext()->MoveNext()->currentVal<<std::endl;
}