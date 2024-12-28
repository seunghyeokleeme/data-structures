#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
    // TODO:
    this->num_rows_ = num_rows;
    this->num_cols_ = num_cols;

    int size = this->num_rows_ * this->num_cols_;

    values_ = new float[size];

    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
        {
            SetValue(r, c, 0.0f);
        }
    }
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix &b)
{
    // TODO:
    this->num_rows_ = b.num_rows_;
    this->num_cols_ = b.num_cols_;

    values_ = new float[b.num_rows_ * b.num_cols_];

    for (int r = 0; r < this->num_rows_; r++)
    {
        for (int c = 0; c < this->num_cols_; c++)
        {
            float value = b.GetValue(r, c);
            SetValue(r, c, value);
        }
    }
}

Matrix::~Matrix()
{
    // TODO:
    if (values_ != nullptr)
    {
        delete[] values_;

        values_ = nullptr;
        num_rows_ = 0;
        num_cols_ = 0;
    }
}

void Matrix::SetValue(int row, int col, float value)
{
    assert(col + num_cols_ * row < num_rows_ * num_cols_);
    // values_[TODO] = value;

    values_[col + num_cols_ * row] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    assert(col + num_cols_ * row < num_rows_ * num_cols_);
    float value = values_[col + num_cols_ * row];

    return value;
}

Matrix Matrix::Transpose()
{
    Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

    // TODO:
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
        {
            float value = this->GetValue(r, c);

            temp.SetValue(c, r, value);
        }
    }

    return temp;
}

Matrix Matrix::Add(const Matrix &b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    // TODO:

    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
        {
            float value1 = this->GetValue(r, c);
            float value2 = b.GetValue(r, c);
            temp.SetValue(r, c, value1 + value2);
        }
    }

    return temp;
}

void Matrix::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";

        cout << endl;
    }
}