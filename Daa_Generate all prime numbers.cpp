#include <stdio.h>
int is_prime(int n, int i) {
    
    if (n <= 2) {
        if (n == 2) return 1;
        return 0; 
    }
    if (n % i == 0) return 0; 
    if (i * i > n) return 1; 

    return is_prime(n, i + 1);
}
void generate_primes(int n, int i) {
    if (i > n) return;

    if (is_prime(i, 2)) {
        printf("%d ", i); 
    }
    generate_primes(n, i + 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d: ", n);
    generate_primes(n, 2);
    printf("\n");

    return 0;
}
