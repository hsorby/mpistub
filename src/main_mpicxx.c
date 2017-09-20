#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 


int main(int argc, char* argv[])
{
char command[1024];
int i = 1;
strcpy(command, "g++");
for (;i < argc;++i)
{
strcat(command, " ");
strcat(command, argv[i]);
}
printf("%s\n", command);
    return system(command);
}

