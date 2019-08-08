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
        
    }
    int GetLength()
    {return this->length;}
private:
    int length;
};
int main()
{
    struct Cell cell[50];
    for (int i = 0; i < 50; i++)
    {
        int temp = 0;
        std::cout << "Insert params for expression. If you insert 0, insertion ends\ncoeficieient: " << std::ends;
        std::cin >> temp;
        if (temp == 0)
            break;
        else
            cell[i].coeficient = temp;
        std::cout << "Indices: " << std::ends;
        std::cin >> temp;
        if (temp == 0)
            break;
        else
            cell[i].coeficient = temp;
        std::cout << "variable: " << std::ends;
        std::cin >> cell[i].variable;
        system("cls");
    }
    Horner horner(cell);
    horner.Calc();

}