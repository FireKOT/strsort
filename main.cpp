#include <stdio.h>
#include <malloc.h>
#include "strsort.h"


int main () {

    FILE *read_file = fopen("hamlet.txt", "r");
    char **text = ReadFile(read_file);

    for(int i = 0; i < 30; i++){
        printf("%s\n", text[i]);
    }

    return 0;
}
