#include <stdio.h>
#include <stdlib.h>
#define HEADER_SIZE 8

void detectFileType(const char *filePath);


void detectFileType(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filePath);
        return;
    }

    unsigned char header[HEADER_SIZE];
    size_t bytesRead = fread(header, 1, HEADER_SIZE, file);
    if (bytesRead < HEADER_SIZE) {
        fprintf(stderr, "Error: File '%s' is too small to determine type.\n", filePath);
        fclose(file);
        return;
    }
    fclose(file);

    // Check for JPEG
    if (header[0] == 0xFF && header[1] == 0xD8) {
        printf("The file type is: JPEG\n");
        return;
    }

    // Check for PNG
    if (header[0] == 0x89 && header[1] == 0x50 &&
        header[2] == 0x4E && header[3] == 0x47 &&
        header[4] == 0x0D && header[5] == 0x0A &&
        header[6] == 0x1A && header[7] == 0x0A) {
        printf("The file type is: PNG\n");
        return;
        }

    // Check for GIF
    if (header[0] == 0x47 && header[1] == 0x49 && header[2] == 0x46) {
        printf("The file type is: GIF\n");
        return;
    }

    // Check for BMP
    if (header[0] == 0x42 && header[1] == 0x4D) {
        printf("The file type is: BMP\n");
        return;
    }

    // Check for TIFF (little-endian and big-endian)
    if ((header[0] == 0x49 && header[1] == 0x49 && header[2] == 0x2A && header[3] == 0x00) ||
        (header[0] == 0x4D && header[1] == 0x4D && header[2] == 0x00 && header[3] == 0x2A)) {
        printf("The file type is: TIFF\n");
        return;
        }

    printf("Unknown file type\n");
}

int main(void) {
    char filePath[256];

    printf("Enter the file path: ");
    if (scanf("%255s", filePath) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    detectFileType(filePath);

    return EXIT_SUCCESS;
}