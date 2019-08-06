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
    Horner(Cell arr[])
    {
        this->cell = arr;
    }
    void Add(Cell single)
    {

        this->cell[length + 1] = single;
        this->length++;
    }

    Cell* Calc()
    {
        this->GetLength();
    }
    int GetLength()
    {return this->length;}
private:
    int length;
};
int main()
{
    
}