
#include "argcheck.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int argcheck(char *exe_path, char *argument)
{
    char *parent = 0, *baseDir = 0;
    char *lastSlash;
    
    lastSlash = strrchr(exe_path, '/'); // you need escape character
    parent = strndup(exe_path, lastSlash - exe_path);
    lastSlash = strrchr(parent, '/');
    baseDir = strndup(parent, lastSlash - parent);
    free(parent);
    if (strcmp(argument, "-compile-info") == 0 ||
        strcmp(argument, "-showme:compile") == 0 ||
        strcmp(argument, "-showme") == 0
       )
    {
        return 1;
    }

    if (strcmp(argument, "-show") == 0)
    {
        printf("-I%s/include -L%s/lib -lmpi\n", baseDir, baseDir);
        return 0;
    }
    free(baseDir);

    return -1;
}

