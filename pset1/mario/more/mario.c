#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int h = -1;
    while (h < 0 || h > 23)
    {
        h = get_int("Height: ");
    }

    for (int i = 0; i < h; i++)//main loop
    {
        for (int j = i; h - j - 1 > 0; j++)
        {
            printf(" ");//for spaces
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");//for hashes
        }

        printf("  ");

        for (int g = 0; g <= i; g++)
        {
            printf("#");//for hashes
        }

        printf("\n");//for chnaging line
    }
}