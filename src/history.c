#include <stdio.h>
#include <time.h>
#include "history.h"

void log_action(const char *action, const char *file) {
    FILE *fp = fopen("logs/history.log", "a");

    if (!fp) return;

    time_t now = time(NULL);
    fprintf(fp, "[%s] %s: %s\n", ctime(&now), action, file);

    fclose(fp);
}