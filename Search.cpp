#include <iostream>
#include <string>
class Search
{
    public:
    int *arr;
    template<typename Data>
    Data BinarySearch(Data* arr, Data value ,int left, int right)
    {
        int middle = (left + right)/2;
        if(arr[middle] > value) return BinarySearch(arr, value, left, middle);
        else if(arr[middle]<value)return BinarySearch(arr, value, middle, right);
        else if(arr[middle] == value)return middle;
        return -1;
    }
};