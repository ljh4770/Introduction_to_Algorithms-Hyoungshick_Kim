#include <stdio.h>

// Worst case: Big theta(N^2)
// -> if proportionality of length of splited partitions is not a constant
// Average case: O(N logN)
// -> gathered by considering all partition cases(0:n-1, 1:n-2, ..., n-2:1, n-1:0) with the same probability(i.e. 1/n)
// Best case: Big theta(N logN)
// -> if proportionality of length of splited partitions is a constant
// not stable
// inplace

void swap(int *a, int *b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int arr[], int left, int right, int method) {
    int pivot = 0;

    // leftmost is pivot
    if (method == 0){
        pivot = left;

        while(left < right) {
            while(arr[left] <= arr[pivot] && left < right) {
                left++;
            }
            while(arr[right] > arr[pivot]) {
                right--;
            }
            if(left < right) {
                swap(&arr[left], &arr[right]);
            }
        }
        swap(&arr[pivot], &arr[right]);
        pivot = right;
    }
    return pivot;
}

void Quick_Sort(int *arr, int left, int right, int method){
    int pivot = 0;

    if (left < right){
        pivot = Partition(arr, left, right, method);
        Quick_Sort(arr, left, pivot - 1, method);
        Quick_Sort(arr, pivot + 1, right, method);
    }

}

int main(){
    int Array[20] = {4, 5, 6, 1, 8, 3, 8, 9, 99, 1, -5, 1, 0, 5, 10, 33, 2, 5, 2, 11};
    int N = 20;

    Quick_Sort(Array, 0, 19, 0);
    for (int i = 0; i < N; i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");

    return 0;
}