#include <stdio.h>
#include<cs50.h>
#include<stdlib.h>

int main(void)
{
    string s = {"123"};
    char x = (s[3]);
    int y = atoi(&x);
    printf("%c %i\n", x, y);
}