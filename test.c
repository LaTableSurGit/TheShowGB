#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\033[1mNew Game\n" "\033[0m");
    printf("\033[1;31m" "Ce texte est rouge et en gras.\n" "\033[0m");
}
