#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

#include "argcheck.h"

int main(int argc, char* argv[])
{
    char command[16384];
    int i = 1;
    int argCheckResult = -1;

    if (argc > 1)
    {
        argCheckResult = argcheck(argv[0], argv[1]);
    }

    if (argCheckResult != -1)
    {
        return argCheckResult;
    }

    strcpy(command, "g++");
    for (;i < argc;++i)
    {
        strcat(command, " ");
        strcat(command, argv[i]);
    }
    //printf("%s\n", command);
    return system(command);
}

