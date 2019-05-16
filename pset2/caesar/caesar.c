#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error!!!\n");//outputting error
        return 1;
    }

    else
    {
        string a = get_string("plaintext: ");//geting the string
        int k = atoi(argv[1]);// convertion
        for (int i = 0; a[i] != '\0'; i++)
        {
            if (a[i] <= 'Z' && a[i] >= 'A') //checking range
            {
                a[i] = ((a[i] - 'A' + k) % 26) + 'A';
            }
            else if (a[i] <= 'z' && a[i] >= 'a')
            {
                a[i] = ((a[i] - 'a' + k) % 26) + 'a';
            }
        }
        printf("ciphertext: %s\n", a);
        return 0;
    }
}