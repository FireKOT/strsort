#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "config.h"
#include "general.h"
#include "strsort.h"

char *ReadLine (FILE *input) {

    int line_size = 1024;
    char *str = (char*) calloc(line_size, sizeof(char));

    int i = 0, c = 0;
    for(i = 0; (c = getc(input)) != '\n' && c != EOF; i++){
        if(i+1 == line_size){
            line_size *= 2;
            str = (char*) realloc(str, line_size * sizeof(char));
        }

        str[i] = (char) c;
    }
    if(c == EOF){
        return NULL;
    }

    str[i] = '\0';

    return str;
}

char **ReadFile (FILE *input) {
    int str_count = 1024;
    char **lines = (char**) calloc(str_count, sizeof(char*));

    char *str = 0;
    int i = 0;
    for(i = 0; (str = ReadLine(input)) != NULL; i++){
        if(i+1 == str_count){
            str_count *= 2;
            lines = (char**) realloc(lines, str_count * sizeof(char*));
        }

        lines[i] = str;
    }

    lines[i] = NULL;
    return lines;
}
