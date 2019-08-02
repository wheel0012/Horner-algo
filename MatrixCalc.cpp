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
        this->matrix = (int**)malloc(sizeof(int*) * column);
        for(int i = 0; i < column; i++)
            this->matrix[i] = (int*)malloc(sizeof(int)*row);
        this->cLength = column;
        this->rLength = row;
    }
    Matrix()
    {
        std::cout<<"I'm Mat 2"<<std::endl;
    }
    void InitialRandom()
    {
        for(int i = 0; i<this->cLength; i++)
            for(int j = 0; j<this->rLength; j++)
                this->matrix[i][j] = (int)(rand() %10);
    }
    Matrix&  operator+(const Matrix& b)
    {
        int cLength = this->cLength > b.cLength ? b.cLength : this->cLength;
        int rLength = this->rLength > b.rLength ? b.rLength : this->rLength;
        Matrix *temp = new Matrix(cLength, rLength);
        for(int i = 0; i < cLength; i++)
            for(int j = 0; j<rLength; j++)
                temp->matrix[i][j] = this->matrix[i][j]+ b.matrix[i][j];
        return *temp;
    };
    void PrintMatrix()
    {
        for(int i = 0; i< this->rLength; i++)
        {
            for(int j = 0; j<this->cLength; j++)
                std::cout<<this->matrix[j][i]<<" "<<std::ends;
            std::cout<<"\n"<<std::endl;
        }  
    }
    private: 
};

int main()
{
    srand((unsigned int)time(0));
    std::cout<<"Matrix 1"<<std::endl;
    Matrix* matrix1= new Matrix(2, 3);
    matrix1->InitialRandom();
    matrix1->PrintMatrix(); 
    //delete matrix1;
    //free(matrix1);
    std::cout<<"Matrix 2"<<std::endl;
    Matrix *m2 = new Matrix(3, 2);
    m2->InitialRandom();
    m2->PrintMatrix();
    std::cout<<"Results"<<std::endl;
    Matrix result = *matrix1 + *m2;
    result.PrintMatrix();
    std::cout<<"\n\nDone!"<<std::endl;
}