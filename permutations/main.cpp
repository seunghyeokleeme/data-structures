#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char *arr, int left, int right)
{
    // arr[left], ..., arr[right]

    if (left == right)
    {
        for (int i = 0; i <= right; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(arr[left], arr[i]);
            RecurPermutations(arr, left + 1, right);
            swap(arr[left], arr[i]);
        }
    }
}

/*
    0...1
    swap(0, 0)
    r1(1, 1);
    swap(0,0)

    1...0
    swap(0, 1);
    r1(1, 1);
    swap(1, 1);

    0..1..2
    swap(0, 0)
    r(1, 2);
        swap(1, 1)
     -> r(2, 2);
        swap(1, 1);

        swap(1, 2);
        r(2, 2);
        swap(1, 2);
    swap(0, 0);

*/

int main()
{
    /* a 한 글자의 순열 (Permutations)
        a
    */

    /* ab 두 글자의 순열 (Permutations)
        a b
        b a
    */

    /*  abc 3 글자의 순열 (Permutations)
        a b c
        a c b
        b a c
        b c a
        c b a
        c a b
    */

    // Permutations
    char arr[] = "abcd";

    RecurPermutations(arr, 0, 0);
    cout << endl;

    RecurPermutations(arr, 0, 1);
    cout << endl;

    RecurPermutations(arr, 0, 2);
    cout << endl;

    RecurPermutations(arr, 0, 3);
    cout << endl;

    return 0;
}