#include <stdio.h>  
 
#define MAX_SIZE 300000  
  
long long merge_count(int arr[], int temp[], int left, int mid, int right) {  
    int i = left, j = mid + 1, k = left;  
    long long count = 0;  
  
    while (i <= mid && j <= right) {  
        if (arr[i] <= arr[j]) {  
            temp[k++] = arr[i++];  
        } else {  
            temp[k++] = arr[j++];  
            count += (mid - i + 1);  
        }  
    }  
  
    while (i <= mid)  
        temp[k++] = arr[i++];  
  
    while (j <= right)  
        temp[k++] = arr[j++];  
  
    for (i = left; i <= right; i++)  
        arr[i] = temp[i];  
  
    return count;  
}  
  
long long sort_count(int arr[], int temp[], int left, int right) {  
    long long count = 0;  
    if (left < right) {  
        int mid = (left + right) / 2;  
  
        count += sort_count(arr, temp, left, mid);  
        count += sort_count(arr, temp, mid + 1, right);  
        count += merge_count(arr, temp, left, mid, right);  
    }  
    return count;  
}  
  
int main() {  
    int n;  
    scanf("%d", &n);  
    int arr[MAX_SIZE], temp[MAX_SIZE];  
  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
  
    long long result = sort_count(arr, temp, 0, n - 1);  
    printf("%lld\n", result);  
  
    return 0;  
}  