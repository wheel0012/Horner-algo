#include <iostream>
template<typename T>
class HashTable
{
    T *values;
    char **keys;
    long _length = 0;
    public:
    HashTable(int size = 100)
    {
        this->arr = (T*)malloc(sizeof(T) * size);
    }
    void Add(T item)
    {
        this->arr[_length] = item;
        _length++;
    }
    long Length()
    {
        return _length;
    }
    void Remove(char * key)
    {
        
    }
    long GetHash()
    {
        
    }
    //__declspec(property(get=getLength)) int length;
    
};
int main()
{
    HashTable<int> *hash = new HashTable<int>(2);
    std::cout<<hash->Length()<<std::endl;
    return 0;
}