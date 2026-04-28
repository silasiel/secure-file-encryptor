#include <stdio.h>
#include "../include/file_ops.h"

void preview_file(const char *input, const char *password) {

    printf("Using password: %s\n", password); // TEMP debug

    FILE *fp = fopen(input, "rb");

    if (!fp) {
        printf("Cannot open file\n");
        return;
    }

    printf("Preview:\n");

    int c;
    int count = 0;

    while ((c = fgetc(fp)) != EOF && count < 100) {
        printf("%c", c ^ 0xAA);  // still XOR for now
        count++;
    }

    printf("\n");

    fclose(fp);
}