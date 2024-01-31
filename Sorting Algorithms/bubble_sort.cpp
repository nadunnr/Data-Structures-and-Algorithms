#include <iostream>
#include <stdio.h>
using namespace std;

void bubble_sort(int* arr, int n){

    for (int i=n-1; i >0; i--){
        for (int j=0; j<i; j++){
            if (arr[j+1] < arr[j]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}

int main (){
    return 0;
}