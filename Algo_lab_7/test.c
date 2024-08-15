#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    
    // Input the number of runners
    printf("Enter the number of runners (1 <= n <= 50): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 50) {
        printf("Invalid input. n should be between 1 and 50.\n");
        return 1;
    }
    
    // Scenario 1: No ties between runners
    unsigned long long outcomes_no_ties = factorial(n);
    
    // Scenario 2: Ties between runners allowed
    unsigned long long outcomes_with_ties = 1;
    
    printf("Number of outcomes with no ties: %llu\n", outcomes_no_ties);
    printf("Number of outcomes with ties allowed: %llu\n", outcomes_with_ties);
    
    return 0;
}
