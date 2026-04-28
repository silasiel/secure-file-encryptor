#ifndef FILE_OPS_H
#define FILE_OPS_H

void encrypt_file(const char *input, const char *output, const char *password);
void decrypt_file(const char *input, const char *output, const char *password);
void preview_file(const char *input, const char *password);

#endif