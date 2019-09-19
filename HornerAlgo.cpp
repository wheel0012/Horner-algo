#include <iostream>
struct Cell
{
    int coeficient;
    int indices;
    char variable;
};
class Horner
{
    Cell *cell;

public:
    Horner(Cell arr[], int length)
    {
        this->cell = arr;
        this->length = length;
    }
    void Add(Cell single)
    {
        this->cell[length + 1] = single;
        this->length++;
    }
    Cell* Calc()
    {
        int length = this->GetLength();
        for(int i = 0; i< length; i++)
        {
            if(this->cell[i].variable)
            std::cout<<this->cell[i].variable<<"||"<<this->cell[i].indices<<"||"<<this->cell[i].coeficient<<std::endl;
        }
    }
    
    int GetLength()
    {return this->length;}
private:
    int length;
};
int main()
{
    int length = 0;
    int maxLength = 50;
    Cell asd[maxLength];
    for(int i  = 0; i< maxLength; i++)
    {
        char temp;
        std::cout<<"put variable"<<std::endl;
        std::cin>>temp;
        if(temp !='-')asd[i].variable = temp;
        else break;
        std::cout<<"put indices"<<std::endl;
        std::cin>>asd[i].indices;
        std::cout<<"put coefficient"<<std::endl;
        std::cin>>asd[i].coeficient;
        system("cls");
        length++;
    }
    Horner horner(asd, length);
    horner.Calc();
}