#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
class Matrix
{
private:
    int cLength;
    int rLength;

public:
    int **matrix;
    Matrix(int column, int row)
    {
        srand((unsigned int)time(0));
        std::cout << "." << std::endl;
        matrix = (int **)malloc(sizeof(int*) * column);
        for(int i = 0; i< row; i++)
            matrix[i] = (int *)malloc(sizeof(int)*row);
        std::cout << "." << std::endl;
        this->cLength = column;
        std::cout << "." << std::endl;
        this->rLength = row;
        std::cout << "." << std::endl;
        for (int i = 0; i < column; i++)
            for (int j = 0; j < row; j++)
                matrix[i][j] = (int)(rand() % 10);
        std::cout << "." << std::endl;
    }
    Matrix()
    {
        std::cout << "I'm Mat 2" << std::endl;
    }
    Matrix*  operator +(Matrix& b)
    {
        Matrix *temp;
        
        int cL = abs(this->cLength - b.cLength);
        int rL = abs(this->rLength - b.rLength);
        for(int i = 0; i < cL; i++)
            for(int j = 0; j<rL; j++)
                temp->matrix[i][j] = matrix[i][j]+ b.matrix[i][j];
                
        return  temp;
    }
    void PrintMatrix();
};
void Matrix::PrintMatrix()
{
    for (int i = 0; i < cLength; i++)
    {
        for (int j = 0; j < rLength; j++)
            std::cout << this->matrix[i][j] << " " << std::ends;
        std::cout << "\n"<< std::endl;
    }
}
int main()
{
    std::cout << "Matrix 1" << std::endl;
    Matrix *m1 = new Matrix(5, 5);
    m1->PrintMatrix();
    //free(matrix1);
    std::cout << "Matrix 2" << std::endl;
    Matrix *m2 = new Matrix(2, 2);
    m2->PrintMatrix();
    std::cout << "step3" << std::endl;
    Matrix *result = *m1 + *m2;
    std::cout << "step4" << std::endl;
    result->PrintMatrix();
    std::cout << "\n\nDone!" << std::endl;
}