#include <stdio.h>

void how_many_digits(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0 && num <= 9) {
        printf("The number has 1 digit\n");
    } else if (num >= 10 && num <= 99) {
        printf("The number has 2 digits\n");
    } else if (num >= 100 && num <= 999) {
        printf("The number has 3 digits\n");
    } else if (num >= 1000 && num <= 9999) {
        printf("The number has 4 digits\n");
    } else if (num >= 10000 && num <= 99999) {
        printf("The number has 5 digits\n");
    }
}

void military_to_civ_time(void) {
    int hour, minute;

    printf("Enter military time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour > 12) {
        printf("Civilian time: %d:%.2d PM\n", hour-12, minute);
    } else if (hour == 12) {
        printf("Civilian time: %d:%.2d PM\n", hour, minute);
    } else if (hour < 12) {
        printf("Civilian time: %d:%.2d AM\n", hour, minute);
    }
}

void beaufort_scale(void) {
    int wind_speed;
    printf("Enter windspeed in knots: ");
    scanf("%d", &wind_speed);
    
    if (wind_speed < 1) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Calm\n", wind_speed);
    } else if (wind_speed <= 3) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Light air\n", wind_speed);
    } else if (wind_speed <= 27) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Breeze\n", wind_speed);
    } else if (wind_speed <= 47) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Gale\n", wind_speed);
    } else if (wind_speed <= 63) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Storm\n", wind_speed);
    } else if (wind_speed >= 63) {
        printf("Speed (knots)\tDescription\n");
        printf("%d knots\t Hurricane\n", wind_speed);
    }
}

// Question 7
void high_and_low_num() {
    int x = 0;
    int y = 0; 
    int z = 0;
    int a = 0;
    printf("Enter 4 integers: ");
    scanf("%d %d %d %d", &x, &y, &z, &a);

    int high = x;
    int low = x;
    
    if (y > high) high = y;
    if (y < low) low = y;

    if (z > high) high = z;
    if (z < low) low = z;

    if (a > high) high = a;
    if (a < low) low = a;

    printf("Largest in set: %d\n", high);
    printf("Smallest in set: %d\n", low);
}

void letter_grade(void) {
    int grade;
    printf("Enter a grade: ");
    scanf("%d", &grade);
    
    switch (grade/10) {
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        case 5: case 4: case 3: case 2: case 1: case 0:
            printf("F\n");
            break;
    }
}

void number_to_word (void) {
    int num;
    printf("Enter a two digit number: ");
    scanf("%d", &num);

    switch (num/10) {
        case 9:
            printf("Ninety ");
            break;
        case 8:
            printf("Eighty ");
            break;
        case 7:
            printf("Seventy ");
            break;
        case 6:
            printf("Sixty ");
            break;
        case 5:
            printf("Fifty ");
            break;
    }
    switch (num%10) {
        case 9:
            printf("Nine\n");
            break;
        case 8:
            printf("Eight\n");
            break;
        case 7:
            printf("Seven\n");
            break;
    }
}

int main(void) {
    // how_many_digits();
    // military_to_civ_time();
    // beaufort_scale();
    // high_and_low_num();
    // letter_grade();
    number_to_word();
    return 0;
}