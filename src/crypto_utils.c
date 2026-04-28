#include <stdio.h>
#include "crypto_utils.h"

void simple_encrypt(const char *input, const char *output) {
    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wb");

    if (!in || !out) {
        printf("File error\n");
        return;
    }

    char c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c ^ 0xAA, out); // simple XOR
    }

    fclose(in);
    fclose(out);
}

void simple_decrypt(const char *input, const char *output) {
    simple_encrypt(input, output); // XOR reversible
}