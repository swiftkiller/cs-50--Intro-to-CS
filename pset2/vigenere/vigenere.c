#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)//if more input
    {
        printf("Error!!!\n");//outputting error
        return 1;
    }

    int z = 0;

    for (; argv[1][z] != '\0'; z++)//if not alphabet
    {
        if (!isalpha(argv[1][z]))
        {
            printf("Error!!!\n");//outputting error
            return 1;
        }
    }

    string a = get_string("plaintext: ");//geting the string
    int k, j = 0;
    char b;
    for (int i = 0; a[i] != '\0'; i++)
    {
        b = toupper(argv[1][j]);
        k = b - 65;//creating one charecter key
        if (a[i] <= 'Z' && a[i] >= 'A') //checking range
        {
            a[i] = ((a[i] - 'A' + k) % 26) + 'A';
            j++;
        }
        else if (a[i] <= 'z' && a[i] >= 'a')
        {
            a[i] = ((a[i] - 'a' + k) % 26) + 'a';
            j++;
        }
        j = j % z;//reniewinng key
    }
    printf("ciphertext: %s\n", a);
    return 0;

}