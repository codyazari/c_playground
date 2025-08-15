#include <stdio.h>

void date_formatter(void) {
    int day = 0;
    int month = 0;
    int year = 0;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date: %d%d%d\n", year, month, day);
}

void isbn_lexer(void) {
    int gs1 = 0;
    int group_id = 0;
    int publisher_code = 0;
    int item_number = 0;
    int check_digit = 0;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &group_id, &publisher_code, &item_number, &check_digit);

    printf("GS1 prefix: %d\n", gs1);
    printf("Group ID: %d\n", group_id);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item Number: %d\n", item_number);
    printf("Check digit: %d\n", check_digit);
}

int main (void) {
    // date_formatter();
    isbn_lexer();
    return 0;
}