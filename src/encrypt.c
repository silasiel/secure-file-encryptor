#include <stdio.h>
#include "../include/file_ops.h"
#include "../include/crypto_utils.h"
#include "../include/history.h"

void encrypt_file(const char *input, const char *output, const char *password) {

    printf("Using password: %s\n", password); // TEMP debug

    simple_encrypt(input, output);

    printf("Encrypted: %s -> %s\n", input, output);

    log_action("ENCRYPT", input);
}