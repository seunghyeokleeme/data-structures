#include <iostream>

using namespace std;

void MySwap(int *i, int *j)
{
    int temp = *i;

    *i = *j;
    *j = temp;
}

void MySwapRef(int &i, int &j)
{
    // TODO: ...
    int temp = i;
    i = j;
    j = temp;
}

bool CheckSorted(int i, int j)
{
    if (i > j)
        return false;

    return true;
}

int main()
{
    // Swap
    {
        int a = 3;
        int b = 2;

        // cout << a << " " << b << endl;

        // ToDo:

        // MySwap(&a, &b);
        MySwapRef(a, b);

        // cout << a << " " << b << endl;
    }

    // 정렬(sorting)
    {
        int arr[] = {9, 3};

        // cout << arr[0] << " " << arr[1] << endl;

        // TODO:
        if (arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);
        // cout << arr[0] << " " << arr[1] << endl;
    }

    {
        cout << boolalpha; // boolalpha 설정

        int arr[2];

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                arr[0] = j;
                arr[1] = i;

                if (arr[0] > arr[1])
                    std::swap(arr[0], arr[1]);

                cout << arr[0] << " " << arr[1] << " " << CheckSorted(arr[0], arr[1]) << endl;
            }
        }
    }

    return 0;
}