#include <stdio.h>

void copyString(char *stng1, char *stng2, int ctr) {
    if (stng1[ctr] == '\0') {
        stng2[ctr] = '\0';
        return;
    }
    stng2[ctr] = stng1[ctr];
    copyString(stng1, stng2, ctr + 1);
}

int main() {
    char stng1[100], stng2[100];
    printf("Enter a string: ");
    scanf("%s", stng1);
    copyString(stng1, stng2, 0);
    printf("Copied string: %s\n", stng2);
    return 0;
}

