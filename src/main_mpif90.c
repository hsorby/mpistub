#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 


int main(int argc, char* argv[])
{
char command[1024];
int i = 1;
char *parent = NULL, *baseDir = NULL;
char *lastSlash;

if (argc > 1)
{
lastSlash = strrchr(argv[0], '/'); // you need escape character
parent = strndup(argv[0], lastSlash - argv[0]);
lastSlash = strrchr(parent, '/');
baseDir = strndup(parent, lastSlash - parent);
free(parent);
if (strcmp(argv[1], "-showme:compile") == 0)
{
printf("-I%s/include\n", baseDir);
return 0;
}

if (strcmp(argv[1], "-showme:link") == 0)

{
printf("-Wl,-rpath -Wl,%s/lib -lmpi\n", baseDir);
return 0;
}
}
strcpy(command, "gfortran");
for (;i < argc;++i)
{
strcat(command, " ");
strcat(command, argv[i]);
}
free(baseDir);
printf("%s\n", command);
    return system(command);
}

