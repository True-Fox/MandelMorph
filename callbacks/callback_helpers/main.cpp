#include "../../headers/header.h"

void CallbackHelpers::log_error(const char *description) {
    FILE *log_file = fopen("file.log", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);

    fprintf(log_file, "[%s] Error: %s\n", time_str, description);
    fclose(log_file);
}
