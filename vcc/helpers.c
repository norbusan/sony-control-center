#include "helpers.h"

FILE* open_file(char const* path, char const* mode) {
    FILE* const fd = fopen(path, mode);
    if (!fd) {
        fprintf(stderr, "open_file: can't open %s: %s\n",
                path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return fd;
}

int read_int_from_file(char const* path) {
    FILE* const fd = open_file(path, "r");
    int result = -1;
    if (fscanf(fd, "%i", &result) != 1) {
        fprintf(stderr, "read_int_from_file: fscanf() failed - %s\n",
                strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);

    return result;
}
void write_int_to_file(char const* path, int val) {
    FILE* const fd = open_file(path, "w");
    if (fprintf(fd, "%i", val) < 0) {
        fprintf(stderr, "write_int_to_file: fprintf failed - %s\n",
                strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);
}
