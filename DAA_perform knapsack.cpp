#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight;
    int value;
} Item;
double ratio(Item item) {
    return (double)item.value / item.weight;
}
void greedyKnapsack(Item items[], int n, int capacity) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio(items[i]) < ratio(items[j])) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int totalWeight = 0;
    int totalValue = 0;

    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: weight = %d, value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total weight: %d\n", totalWeight);
    printf("Total value: %d\n", totalValue);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    greedyKnapsack(items, n, capacity);

    return 0;
}
