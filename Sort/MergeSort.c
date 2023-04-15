#include <stdio.h>

// Big theta(NlogN)
// stable
// not in-place

// O(N)
void Merge(int *arr, int *aux_arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    int l = 0;

    while( i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            aux_arr[k++] = arr[i++];
        }
        else{
            aux_arr[k++] = arr[j++];
        }
    }

    if (i > mid){
        for (l = j; l <= right; l++){
            aux_arr[k++] = arr[l];
        }
    }
    else{
        for (l = i; l <= mid; l++){
            aux_arr[k++] = arr[l];
        }
    }

    for (l = left; l <= right; l++){
        arr[l] = aux_arr[l];
    }
}

// T(N) = 2T(N/2) + T(Merge)
void Merge_Sort(int *arr, int *aux_arr,int left, int right){
    int mid = 0;

    if (left < right){
        mid = (left + right)/2;
        Merge_Sort(arr, aux_arr, left, mid);
        Merge_Sort(arr, aux_arr,mid + 1, right);
        Merge(arr, aux_arr,left, mid, right);
    }
}


int main(){
    int Array[20] = {4, 5, 6, 1, 8, 3, 8, 9, 99, 1, -5, 1, 0, 5, 10, 33, 2, 5, 2, 11};
    int N = 20;
    int auxiliray_arr[20];

    Merge_Sort(Array, auxiliray_arr, 0, 19);
    for (int i = 0; i < N; i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");

    return 0;
}