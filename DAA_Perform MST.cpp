#include <stdio.h>
#include <stdlib.h>
int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int values[n];
    int weights[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    int maxValue = knapsack(values, weights, n, capacity);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}
