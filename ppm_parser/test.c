#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "synth_1.ppm"

int main(void) {
    FILE* img;
    char* buffer;

    if ((img = fopen(FILE_NAME, "rb")) == NULL) {
        printf("File %s could not open\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    fseek(img, 0, SEEK_END);
    long file_size = ftell(img);
    rewind(img);

    if ((buffer = malloc(file_size)) != NULL) {
        fread(buffer, 1, file_size, img);
    }
    
    fclose(img);

    for (size_t i = 0; i < 100; i++) {
        printf("%c", buffer[i]);
    }

    free(buffer);
    
    return 0;
}