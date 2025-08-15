#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE* open_file(const char* filename, const char* mode) {
    FILE* img = fopen(filename, mode);
    if(img == NULL) {
        fprintf(stderr, "File %s failed to open\n", filename);
        exit(EXIT_FAILURE);
    }
    return img;
}

size_t determine_file_size(FILE* img) {
    fseek(img, 0, SEEK_END);
    long file_size = ftell(img);
    rewind(img);
    printf("%ld\n", file_size);
    return file_size;
}

char* load_to_buffer(FILE* img, size_t file_size) {
    char* buffer;
    if ((buffer = malloc(file_size)) == NULL) {
        fprintf(stderr, "Could not allocate memory to buffer\n");
        fclose(img);
        free(buffer);
        exit(EXIT_FAILURE);
    }
    
    size_t bytes_read = fread(buffer, 1, file_size, img);

    if (bytes_read != file_size) {
        fprintf(stderr, "Failed to read file - only read %zu of %ld bytes\n", bytes_read, file_size);
        fclose(img);
        free(buffer);
        exit(EXIT_FAILURE);
    }
    
    return buffer;
}

char* skip_whitespace_and_comments(char* cursor, char* end_of_file) {
    while (cursor < end_of_file) {
        while (cursor < end_of_file && isblank(*cursor)) {
            ++cursor;
        }
        if (*cursor == '#') {
            while (cursor < end_of_file && *cursor != "\n" && *cursor != "\n") {
                ++cursor;
            }
        }
        else {
            break;
        }
    }
    return cursor;
}

int main(void) {
    
    FILE* img = open_file("synth_1.ppm", "rb");

    
    size_t file_size = determine_file_size(img);
    char* buffer = load_to_buffer(img, file_size);
    char* cursor = &buffer[0] + file_size;
    
    while (cursor < buffer) {
        skip_whitespace_and_comments(cursor, file_size);
        printf("%c", cursor);
        ++cursor;
    }
    
    
    fclose(img);
    free(buffer);
    return 0;
}