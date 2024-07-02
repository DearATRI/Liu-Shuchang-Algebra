#include "algebra.h"
#include <stdio.h>
#include <math.h>

#define MAX 100
double DET(double arr1[MAX][MAX], int n);
double Minor(double arr1[MAX][MAX], int i, int n);

double DET(double arr1[MAX][MAX], int n)
{
    int i;
    double M,sum = 0.0;
    if (n == 1)
        return arr1[0][0];
    else if (n > 1)
    {
        for (i = 0; i < n; i++)
        {
            M = Minor(arr1, i, n);
            sum += pow(-1, i + 2) * arr1[0][i] * M;
        }
    }
    return sum;
}

double Minor(double arr1[MAX][MAX],int i,int n)
{
    int  j, k;
    double arr2[MAX][MAX];
    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (k < i)
                arr2[j][k] = arr1[j + 1][k];
            else if (k >= i)
                arr2[j][k] = arr1[j + 1][k + 1];
        }
    }

    return DET(arr2, n - 1);
}

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b) {
    // ToDo
    if(a.cols==b.cols&&a.rows==b.rows) {
        Matrix k=create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++) {
            for(int j=0;j<a.cols;j++) {
                k.data[i][j]=a.data[i][j]+b.data[i][j];
            }
        }
        return k;
    }
    else {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}
Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    if(a.cols==b.cols&&a.rows==b.rows) {
        Matrix k=create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++) {
            for(int j=0;j<a.cols;j++) {
                k.data[i][j]=a.data[i][j]-b.data[i][j];
            }
        }
        return k;
    }
    else {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if(a.cols==b.rows&&a.rows==b.cols) {
        Matrix k=create_matrix(a.rows,b.cols);
        for(int i=0;i<a.rows;i++) {
            for(int j=0;j<b.cols;j++) {
                for(int l=0;l<a.cols;l++) {
                    k.data[i][j]+=a.data[i][l]*b.data[l][j];
                }
            }
        }
        return k;
    }
    else {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0, 0);
    }
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    Matrix w=create_matrix(a.rows,a.cols);
    for(int i=0;i<a.rows;i++) {
            for(int j=0;j<a.cols;j++) {
                w.data[i][j]=a.data[i][j]*k;
            }
    }
        return w;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix k=create_matrix(a.cols,a.rows);
    for(int i=0;i<a.rows;i++) {
        for(int j=0;j<a.cols;j++) {
            k.data[j][i]=a.data[i][j];
        }
    }
    return k;
}

double det_matrix(Matrix a)
{
    // ToDo
    if(a.rows==a.cols) {
        return DET(a.data,a.rows);
    }
    else {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return 0;
    }
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}
