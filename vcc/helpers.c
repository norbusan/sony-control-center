/*
 * Sony VAIO Control Center for Linux
 *
 * Copyright (C) 2011 Tu Vuong <vanhtu1987@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include "helpers.h"

int check_file(char const* path) {
    struct stat st;

    return !stat(path, &st);
}

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
        fprintf(stderr, "read_int_from_file (%s): fscanf() failed - %s\n",
                path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);

    return result;
}
void write_int_to_file(char const* path, int val) {
    FILE* const fd = open_file(path, "w");
    if (fprintf(fd, "%i", val) < 0) {
        fprintf(stderr, "write_int_to_file (%s): fprintf failed - %s\n",
                path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);
}

char const* read_str_from_file(char const* path, char* buf, size_t buf_size) {
    FILE* const fd = open_file(path, "r");
    if (getline(&buf, &buf_size, fd) < 0) {
        fprintf(stderr, "read_str_from_file (%s): getline() failed - %s\n",
                path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);

    return buf;
}

void write_str_to_file(char const* path, char const* val) {
    FILE* const fd = open_file(path, "w");
    if (fprintf(fd, "%s", val) < 0) {
        fprintf(stderr, "write_str_to_file (%s): fprintf failed - %s\n",
                path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fd);
}

