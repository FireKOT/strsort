#include <stdio.h>
#include <malloc.h>
#include "strsort.h"


int main () {

    FILE *read_file = fopen("hamlet.txt", "r");
    char **text = ReadFile(read_file);



    return 0;
}
