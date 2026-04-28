#include <stdio.h>
#include <string.h>
#include "../include/file_ops.h"

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage:\n");
        printf("encryptor encrypt <input> <output> <password>\n");
        printf("encryptor decrypt <input> <output> <password>\n");
        printf("encryptor preview <input> <password>\n");
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0 && argc == 5) {
        encrypt_file(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "decrypt") == 0 && argc == 5) {
        decrypt_file(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "preview") == 0 && argc == 4) {
        preview_file(argv[2], argv[3]);
    }
    else {
        printf("Invalid command\n");
    }

    return 0;
}