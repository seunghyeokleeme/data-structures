#include <iostream>

using namespace std;

void MySwap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void MySwapRef(int& i, int& j){
    // ToDo
//    int tmp = i;
//    i = j;
//    j = tmp;
    if(i != j){
        i ^= j;
        j ^= i;
        i ^= j;
    }
}

bool CheckSorted(int i, int j){
    return !(i > j);
}

int main()
{
    // Swap
    {
        int a = 3;
        int b = 2;
        
        cout << a << " " << b << endl;
        
        // TODO:
        
        // MySwap(&a, &b);
        MySwapRef(a, b);
        
        cout << a << " " << b << endl;
    }
    
    // 정렬(sorting)
    {
        int arr[] = { 9, 3 };

        cout << arr[0] << " " << arr[1] << endl;

        // TODO:
        if(arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);

        cout << arr[0] << " " << arr[1] << endl;
    }
    
    {
        int arr[2];
        
        for(int i=0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                arr[0] = i;
                arr[1] = j;
                
                if(arr[0] > arr[1])
                    swap(arr[0], arr[1]);
                
                cout << boolalpha;
                cout << arr[0] << " " << arr[1] << " " << CheckSorted(arr[0], arr[1]) << endl;
            }
        }
    }

    
    return 0;
}
