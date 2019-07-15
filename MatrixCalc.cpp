#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
class Matrix
{
    private:
    int cLength= 0;
    int rLength = 0;
    public:
    int  **matrix;
    Matrix(int column, int row)
    {
        std::cout<<"."<<std::endl;
        this ->matrix = (int**)malloc(sizeof(int) * column  * sizeof(int) * row);
        std::cout<<"."<<std::endl;
        this->cLength = column;
        std::cout<<"."<<std::endl;
        this->rLength = row;
        std::cout<<"."<<std::endl;
        for(int i = 0; i<column; i++)
            for(int j = 0; j<row; j++)
                this->matrix[i][j] = (int)(rand() %10);
                std::cout<<"."<<std::endl;
    }
    Matrix  operator+(const Matrix& b)
    {
        Matrix *temp = new Matrix(this->cLength, this->rLength);
        int cLength = abs(this->cLength - b.cLength);
        int rLength = abs(this->rLength - b.rLength);
        for(int i = 0; i < cLength; i++)
            for(int j = 0; j<rLength; j++)
                temp->matrix[i][j] = this->matrix[i][j]+ b.matrix[i][j];
        return *temp;
    };
    void PrintMatrix()
    {
        for(int i = 0; i< this->cLength; i++)
        {
            for(int j = 0; j<this->rLength; j++)
                std::cout<<this->matrix[i][j]<<" "<<std::ends;
            std::cout<<"\n"<<std::endl;
        }  
    }

};

int main()
{
    srand((unsigned int)time(0));
    std::cout<<"Matrix 1"<<std::endl;
    //Matrix *matrix1= new Matrix(2, 3);
    //matrix1->PrintMatrix();
    //free(matrix1);
    std::cout<<"Matrix 2"<<std::endl;
    Matrix *matrix2 = new Matrix(3,2);
    matrix2->PrintMatrix();
    std::cout<<"step3"<<std::endl;
    //Matrix result = *matrix1 + *matrix;
    std::cout<<"step4"<<std::endl;
    //matrix1->PrintMatrix();
    std::cout<<"\n\nDone!"<<std::endl;
}