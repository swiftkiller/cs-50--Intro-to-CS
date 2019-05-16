#include<stdio.h>
#include<cs50.h>

int main(void)
{
    float h;
    do
    {
        h = get_float("Change owed ");
    }
    while (h < 0);

    int x = (h * 100) + 0.5;

    int coin = 0;

    coin += x / 25;
    x %= 25;

    coin += x / 10;
    x %= 10;

    coin += x / 5;
    x %= 5;

    coin += x / 1;

    printf("%i", coin);

}