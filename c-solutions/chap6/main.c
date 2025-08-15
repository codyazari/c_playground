#include <stdio.h>

// HIGHEST NUM IN SET FOR WHILE
void question1(void) {
    float in = 0;
    float max = 0;

    printf("Enter Numbers to determine the highest, 0 to end\n");

    do {
        printf("Enter a number: ");
        scanf("%f", &in);

        if (in > max) max = in;
        continue;
    } while (in != 0);

    printf("Highest number in set: %f\n", max);
}

// EUCLIDS ALGORITHM - FIND GCD
int question2(int x, int y) {
    int rem = 0;
    
    while (x != 0) {
        rem = y % x;
        y = x;
        x = rem;
    }
    printf("The GCD is: %d\n", y);
    return y;
}

// simplify fractions
void question3 (void) {
    int numerator = 0;
    int denominator = 0;
    int gcd = 0;

    printf("Enter a fraction as n/d: ");
    scanf("%d/%d", &numerator, &denominator);
    gcd = question2(denominator, numerator);

    numerator /= gcd;
    denominator /= gcd;
    printf("Simplified: %d/%d\n", numerator, denominator);
}

int main(void) {
    // question1();
    // question2(12, 28);
    // question3();

    int test [] = {0, 1, 2, 3, 4, 5};
    int* cursor = test;
    printf("%d\n", *cursor+4);
    return 0;
}