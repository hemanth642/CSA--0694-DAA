#include <stdio.h>

void reverseString(char *str, int len) {
    if (len == 0) {
        return;
    }
    printf("%c", str[len - 1]);
    reverseString(str, len - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    printf("Reverse of the string: ");
    reverseString(str, len);
    printf("\n");

    return 0;
}
