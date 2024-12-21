#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
    int key;
    char value;
};

bool CheckSorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
};

void MySwap(int *arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int small = arr[i];
        for (int j = i; j < size - 1; j++)
        {
            if (small > arr[j + 1])
            {
                small = arr[j + 1];
                arr[j + 1] = arr[i];
                arr[i] = small;
            }
        }
    }
}

void Print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Print(Element *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i].key << " ";
    cout << endl;

    for (int i = 0; i < size; i++)
        cout << arr[i].value << " ";
    cout << endl;
}

int main()
{

    {
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int arr[3] = {i, j, k};
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; e++)
                    {
                        cout << arr[e] << " " << flush;
                    }

                    cout << " -> " << flush;

                    // TODO: 정렬 해보기
                    MySwap(arr, size);

                    for (int e = 0; e < size; e++)
                    {
                        cout << arr[e] << " " << flush;
                    }

                    cout << boolalpha;
                    cout << CheckSorted(arr, size);
                    cout << endl;
                }
            }
        }
    }
    {
        // 8 4 2 8 3
        int arr[5] = {3, 2, 4, 5, 1};
        int size = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " " << flush;
        }

        cout << endl;

        for (int i = 0; i < size - 1; i++)
        {
            int small_idx = i;
            int small = arr[small_idx];
            for (int j = i; j < size; j++)
            {
                if (small > arr[j])
                {
                    small = arr[j];
                    small_idx = j;
                }
            }

            std::swap(arr[i], arr[small_idx]);
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " " << flush;
        }

        cout << endl;
    }

    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0);

        int min_number = arr[0];
        for (int i = 1; i < size; i++)
        {
            // if (min_number > arr[i])
            //     min_number = arr[i];

            min_number = std::min(arr[i], min_number);
        }

        cout << "Minimum number is " << min_number << endl;
    }

    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0);

        int min_index = 0;
        for (int i = 1; i < size; i++)
        {
            if (arr[min_index] > arr[i])
            {
                min_index = i;
            }
        }

        cout << "The index of min is " << min_index << endl;
        cout << "Minimum number is " << arr[min_index] << endl;
    }

    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; CheckSorted(arr, size) != true; i++)
        {
            int min_index = i;

            for (int j = i + 1; j < size; j++)
            {
                if (arr[min_index] > arr[j])
                {
                    min_index = j;
                }
            }

            std::swap(arr[i], arr[min_index]);

            Print(arr, size);
            cout << boolalpha;
            cout << CheckSorted(arr, size);
            cout << endl;
        }
    }

    // 비교 횟수 세보기, 더 효율적인 방법은 없을까?
    // https://en.wikipedia.org/wiki/Sorting_algorithm
    {
        ofstream ofile("log2.txt");
        for (int size = 1; size < 1000; size++)
        {
            int count = 0;
            int *arr = new int[size];
            for (int s = 0; s < size; s++)
            {
                arr[s] = size - s;
            }

            // TODO: count ++;
            int min_index;
            for (int i = 0; CheckSorted(arr, size) != true; i++)
            {
                min_index = i;

                for (int j = i + 1; j < size; j++)
                {
                    count++;

                    if (arr[min_index] > arr[j])
                        min_index = j;
                }
                swap(arr[i], arr[min_index]);
            }

            // cout << size << ", " << count << endl;
            ofile << size << ", " << count << endl;
            // Print(arr, size);

            delete[] arr;
        }

        ofile.close();
    }

    // 안정성 확인(unstable)
    {
        Element arr[] = {{2, 'a'}, {2, 'b'}, {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size); // arr이 Element의 배열

        int min_index;
        for (int i = 0; i < size - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j].key < arr[min_index].key)
                    min_index = j;
            }
            swap(arr[i], arr[min_index]);

            Print(arr, size);
        }
    }

    return 0;
}