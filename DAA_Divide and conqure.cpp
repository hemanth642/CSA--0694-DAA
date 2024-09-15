#include <stdio.h>
void find_max_min(int arr[], int low, int high, int* max, int* min) {
    if (low == high) {
        *max = *min = arr[low];
    } else {
        int mid = (low + high) / 2;
        int max_left, min_left, max_right, min_right;
        find_max_min(arr, low, mid, &max_left, &min_left);

        find_max_min(arr, mid + 1, high, &max_right, &min_right);

        *max = (max_left > max_right) ? max_left : max_right;
        *min = (min_left < min_right) ? min_left : min_right;
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    find_max_min(arr, 0, n - 1, &max, &min);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
