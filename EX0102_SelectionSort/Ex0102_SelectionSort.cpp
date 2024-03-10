#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
    int key;
    char value;
};

void MySorted(int* arr, int size){
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


bool CheckSorted(int* arr, int size){
    for (int i=0; i < size-1; i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    
    return true;
}

void Print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Print(Element* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i].key << " ";
    cout << endl;

    for (int i = 0; i < size; i++)
        cout << arr[i].value << " ";
    cout << endl;
}

int main(){
//    {
//        for(int k = 0; k < 3; k++)
//            for(int j = 0; j < 3; j++)
//                for(int i = 0; i < 3; i++){
//                    
//                    int arr[3] = {i, j, k};
//                    int size = sizeof(arr) / sizeof(arr[0]);
//                    
//                    for(int e = 0; e < size; e++){
//                        cout << arr[e] << " " << flush;
//                    }
//                    
//                    cout << " -> " << flush;
//                    
//                    // TODO: 정렬 해보기
//                    MySorted(arr, size);
//                    
//                    for (int e = 0; e < size; e++){
//                        cout << arr[e] << " " << flush;
//                    }
//                    
//                    cout << boolalpha;
//                    cout << CheckSorted(arr, size);
//                    cout << endl;
//                }
//    }
    
    
    
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        int min_number = arr[0];
        for(int i = 1; i < size; i++){
            if(arr[i] < min_number){
                min_number = arr[i];
            }
            //min_number = std::min(arr[i], min_number);
        }
        
        cout << "Min number is " << min_number << endl;
        
    }
    
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        int min_index = 0;
        for(int i = 1; i < size; i++){
            if(arr[i] < arr[min_index])
                min_index = i;
        }
        
        cout << "Min index is " << min_index << endl;
        cout << "Min number is " << arr[min_index] << endl;
    }
    
    // Selection Sort
    // 힌트: swap()
    {
        // 8 3 2 5
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        int min_index;
        for(int i = 0; i < size-1; i++){
            min_index = i;
            for(int j = i+1; j < size; j++){
                if(arr[j] < arr[min_index])
                    min_index = j;
            }
            swap(arr[i], arr[min_index]);
        }
        
        for (int e = 0; e < size; e++){
            cout << arr[e] << " " << flush;
        }
        
        cout << " -> " << flush;
        
        cout << boolalpha;
        cout << CheckSorted(arr, size);
        cout << endl;
    }
    
    {
        ofstream ofile("log.txt");
        for (int size = 1; size < 1000; size++)
        {
            int count = 0;
            int* arr = new int[size];
            for (int s = 0; s < size; s++) {
                arr[s] = size - s;
            }

            int min_index;
            for(int i = 0; i < size -1; i++){
                min_index = i;
                for(int j = i+1; j < size; j++){
                    count++;
                    
                    if(arr[j] < arr[min_index])
                        min_index = j;
                }
                swap(arr[i], arr[min_index]);
            }

            //cout << size << ", " << count << endl;
            ofile << size << ", " << count << endl;
            // Print(arr, size);

            delete[] arr;
        }

        ofile.close();
    }
    
    {
        Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size); // arr이 Element의 배열
        
        int min_index;
        for(int i = 0; i < size-1; i++){
            min_index = i;
            for(int j = i + 1; j < size; j++){
                if(arr[j].key < arr[min_index].key)
                    min_index = j;
            }
            swap(arr[i], arr[min_index]);
         
            Print(arr, size); // arr이 Element의 배열
        }
    }
    
    return 0;
}
