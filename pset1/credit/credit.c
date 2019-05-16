#include<stdio.h>
#include<cs50.h>

int main(void)
{
    long long h, a;

    do
    {
        h = get_long_long("Number: ");
    }
    while (h < 0);

    a = h;

    int odd = 0, even = 0, d = 1, no, sum1, sum2;

    for (; h != 0; d++)//counting using the formula
    {
        no = h % 10;

        if (d % 2 == 0)
        {
            no *= 2;
            even += no / 10;
            even += no % 10;
        }
        else
        {
            odd += no;
        }

        h /= 10;
        if ((h / 10) == 0 && (h / 1) != 0)
        {
            sum1 = h;
        }
        if ((h / 100) == 0 && (h / 10) != 0)
        {
            sum2 = h;
        }

    }

    d -= 1;

    if ((even + odd) % 10 != 0)//checking validity
    {
        printf("INVALID\n");
    }

    else//cheching which card
    {
        if (d == 15 && (sum2 == 34 || sum2 == 37))
        {
            printf("AMEX\n");
        }

        else if ((d == 16 || d == 13) && sum1 == 4)
        {
            printf("VISA\n");
        }

        else if (d == 16 && (sum2 == 51 || sum2 == 52 || sum2 == 53 || sum2 == 54 || sum2 == 55))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }

    }
    return 0;
}