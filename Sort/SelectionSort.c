#include <stdio.h>

// Big theta(N^2)
// stable if use < operator in comparison condition
// -> elements with equal values will not be swapped.
// not stable if use <= operator in comparison condition
// in-place

void swap(int *a, int *b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Selection_Sort(int *arr, int N){
    int i = 0;
    int j = 0;
    int smallest = 0;

    for (i = 0; i < N - 1; i++){
        smallest = i;
        for (j = i + 1; j < N; j++){
            if ( arr[j] < arr[smallest] ){
                smallest = j;
            }
        }
        swap(&arr[i], arr[smallest]);
    }
}

int main(){
    int Array[20] = {4, 5, 6, 1, 8, 3, 8, 9, 99, 1, -5, 1, 0, 5, 10, 33, 2, 5, 2, 11};
    int N = 20;
    
    for (int i = 0; i < N; i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");
    Selection_Sort(Array, 20);
    for (int i = 0; i < N; i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");

    return 0;
}