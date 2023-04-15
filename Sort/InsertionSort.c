#include <stdio.h>

// Big theta(N^2)
// stable
// inplace

void Insertion_Sort(int *arr, int N){
    int j = 0;
    int t = 0;
    for (int i = 1; i < N; i++){
        t = arr[i];
        for (j = i - 1; j >= 0 && t < arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = t;
    }
}

int main(){
    int Array[20] = {4, 5, 6, 1, 8, 3, 8, 9, 99, 1, -5, 1, 0, 5, 10, 33, 2, 5, 2, 11};
    int N = 20;

    Insertion_Sort(Array, N);
    for (int i = 0; i < N; i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");
    
    return 0;
}