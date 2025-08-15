#include <stdio.h>
#include <stdlib.h>

void message_length(void) {
    char ch;
    int count = 0;
    printf("Enter a message: ");
    ch = getchar();
    while (ch != '\n') {
        ch = getchar();
        count++;
    } ;

    printf("Your message was %d character(s) long.\n", count);
}

void rev_message_length(void) {
    int count = 0;

    printf("Enter message: ");
    while(getchar() != '\n') {
        count++;
    }
    printf("message is %d chars long \n", count);
}

int main(void) {
    // char ch;
    // do {
    //     ch = getchar();
    //     printf("%c\n", ch);
    // } while (ch != '\n');

    // while(getchar() != '\n');

    rev_message_length();

    return 0;
}