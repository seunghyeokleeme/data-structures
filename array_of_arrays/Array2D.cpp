#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols)
{
    // TODO:
    arrays_ = new float *[num_rows];
    this->num_rows_ = num_rows;
    this->num_cols_ = num_cols;

    for (int i = 0; i < num_rows; i++)
    {
        arrays_[i] = new float[num_cols];
        for (int j = 0; j < num_cols; j++)
        {
            arrays_[i][j] = 0.0f;
        }
    }
}

// 복사 생성자 (b를 복사)
Array2D::Array2D(const Array2D &b)
{
    // TODO:
    arrays_ = new float *[b.num_rows_];
    this->num_rows_ = b.num_rows_;
    this->num_cols_ = b.num_cols_;

    for (int i = 0; i < num_rows_; i++)
    {
        arrays_[i] = new float[num_cols_];
        for (int j = 0; j < num_cols_; j++)
        {
            this->arrays_[i][j] = b.arrays_[i][j];
        }
    }
}

Array2D::~Array2D()
{
    // TODO:
    if (arrays_ != nullptr)
    {
        for (int r = 0; r < num_rows_; r++)
        {
            delete[] arrays_[r];
        }

        delete[] arrays_;
        arrays_ = nullptr;

        num_rows_ = 0;
        num_cols_ = 0;
    }
}

void Array2D::SetValue(int row, int col, float value)
{
    // TODO:
    assert(row < num_rows_);
    assert(col < num_cols_);

    arrays_[row][col] = value;
}

float Array2D::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    assert(row < num_rows_);
    assert(col < num_cols_);

    return arrays_[row][col]; // TODO:
}

Array2D Array2D::Transpose()
{
    Array2D temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Array2D Array2D::Add(const Array2D &b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Array2D temp(num_rows_, num_cols_);

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Array2D::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";

        cout << endl;
    }
}