#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    int rem;

    while (x != 0) {
        rem = y % x;
        y = x;
        x = rem;
    }
    return y;
}

void reduce(int num, int denom, int* red_num, int* red_denom) {
    int factor = gcd(num, denom);

    printf("GCD of num & denom: %d\n", factor);

    *red_num = num / factor;
    *red_denom = denom / factor;
}

void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones) {
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %=5;
    *ones = dollars;
}

int main(void) {
    // int twenties, tens, fives, ones;

    int numerator = 256;
    int denominator = 128;
    int red_num = 0;
    int red_denom = 0;

    reduce(numerator, denominator, &red_num, &red_denom);
    printf("%d/%d\n", red_num, red_denom);
    
    
    // pay_amount(81, &twenties, &tens, &fives, &ones);

    // printf("Twenties | Tens | Fives | Ones\n");
    // printf("%d %d %d %d\n", twenties, tens, fives, ones);
    return 0;
}