#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

int Sum(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int RecurSum(int *arr, int n)
{
    if (n == 0)
        return 0;

    return RecurSum(arr, n - 1) + arr[n - 1];
}

/**
 * r(10) sum = 10 + r(9)
 * r(9)  sum = 9 + r(8)
 * r...  sum = ....
 *
 * r(2) sum = 2 + r(1)
 * r(1) sum = 1 + r(0);
 * r(0)  return 0;
 * sum = 10 + 9+8+7+......1 +0
 */

int main()
{
    // Sum vs RecurSum

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << Sum(arr, n) << endl;
    cout << RecurSum(arr, n) << endl;

    return 0;
}