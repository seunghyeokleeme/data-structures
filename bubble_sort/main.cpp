#include <iostream>

using namespace std;

struct Element
{
    int key;
    char value;
};

void Print(Element *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i].key << " ";
    cout << endl;

    for (int i = 0; i < size; i++)
        cout << arr[i].value << " ";
    cout << endl;
}

bool CheckSorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

void Print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // int arr[] = {5, 1, 4, 2, 8}; // 위키피디아 예시
    // int arr[] = {5, 4, 3, 2, 1}; // Worst Case
    int arr[] = {1, 2, 3, 5, 4}; // Best Case
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);
    cout << endl;

    // Bubble Sort
    {
        // 힌트: Print()로 진행상황 확인하면서 구현
        // 힌트: 2중 for 루프
        // 힌트: for 루프 범위 주의

        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }

                Print(arr, n);
            }
            cout << endl;

            if (!swapped)
                break;
        }
    }

    // Best case
    // Stability
    // 안정성 확인(unstable)
    {
        Element arr[] = {{2, 'a'}, {2, 'b'}, {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size); // arr이 Element의 배열

        int min_index;
        for (int i = 0; i < size - 1; i++)
        {

            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j].key > arr[j + 1].key)
                    swap(arr[j], arr[j + 1]);
            }

            Print(arr, size); // arr이 Element의 배열
        }
    }
}