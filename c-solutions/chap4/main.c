#include <stdio.h>

void reverse_number(void) {
    int digit_1 = 0;
    int digit_2 = 0;
    int digit_3 = 0;

    printf("Enter a three digit number: ");
    scanf("%1d%1d%1d", &digit_1, &digit_2, &digit_3);

    printf("Reversed number is: %d%d%d\n", digit_3, digit_2, digit_1);
}

int main(void) {
    reverse_number();
    return 0;
}