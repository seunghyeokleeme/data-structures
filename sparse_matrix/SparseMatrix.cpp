#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
    // TODO:
    terms_ = new MatrixTerm[capacity];

    this->capacity_ = capacity;
    this->num_rows_ = num_rows;
    this->num_cols_ = num_cols;
    this->num_terms_ = 0;
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix &b)
{
    // TODO:
    terms_ = new MatrixTerm[b.capacity_];
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    capacity_ = b.capacity_;
    num_terms_ = 0;

    for (int i = 0; i < capacity_; i++)
    {
        terms_[i].row = b.terms_[i].row;
        terms_[i].col = b.terms_[i].col;
        terms_[i].value = b.terms_[i].value;
        num_terms_++;
    }
}

SparseMatrix::~SparseMatrix()
{
    // TODO:
    if (terms_ != nullptr)
    {
        delete[] terms_;
        terms_ = nullptr;
        num_terms_ = 0;
    }
}

void SparseMatrix::SetValue(int row, int col, float value)
{
    if (value == 0.0f)
        return; // value가 0이 아닌 term만 저장

    // TODO:
    assert(row < num_rows_);
    assert(col < num_cols_);
    assert(num_terms_ + 1 <= capacity_);

    int key = col + row * num_cols_;

    if (GetValue(row, col) != 0.0f)
    {
        int i = 0;
        for (; i < num_terms_; i++)
        {
            if (key == terms_[i].col + terms_[i].row * num_cols_)
                break;
        }

        terms_[i].value = value;
        return;
    }

    int i = num_terms_;
    for (; i > 0 && (terms_[i - 1].row * num_cols_ + terms_[i - 1].col) > key; i--)
        terms_[i] = terms_[i - 1];

    terms_[i].row = row;
    terms_[i].col = col;
    terms_[i].value = value;

    num_terms_++;
}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    // TODO: key = col + num_cols * row;

    for (int i = 0; i < num_terms_; i++)
    {
        if (terms_[i].row == row && terms_[i].col == col)
        {
            return terms_[i].value;
        }
    }

    return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

    // TODO:
    for (int i = 0; i < capacity_; i++)
    {
        temp.SetValue(terms_[i].col, terms_[i].row, terms_[i].value);
    }

    return temp;
}

void SparseMatrix::PrintTerms()
{
    for (int i = 0; i < num_terms_; i++)
        cout << "(" << terms_[i].row
             << ", " << terms_[i].col
             << ", " << terms_[i].value
             << ")" << endl;
}

void SparseMatrix::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}