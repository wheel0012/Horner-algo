#include <iostream>
#include <string>
class Search
{
    public:
    int *arr;
    int BinarySearch(int* arr, int value ,int left, int right)
    {
        int middle = (left + right)/2;
        if(arr[middle] > value) return BinarySearch(arr, value, left, middle);
        else if(arr[middle]<value)return BinarySearch(arr, value, middle, right);
        else if(arr[middle] == value)return middle;
        return -1;
    }/*
    private:
    int Size(int* arr)
    {
        int i = 0; 
        while(i++)
        {
            if(arr[i])break;
        }
        return i;
    }*/
};
int main()
{
    Search bs; 
    int arr[10] = {1, 4, 5, 7, 8, 9, 10, 10, 11, 12};
    int result = bs.BinarySearch(arr, 11, 0, 9);
    std::cout << result << std::endl;
    getchar();
    return 0;
}  