// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char a = fraction[0], b = fraction[2];
    int s0 = atoi(&a), s1 = atoi(&b);
    s1 /= 10;
    //checking denominator
    if (s1 == 4)
    {
        return s0 * 2;
    }
    else if (s1 == 2)
    {
        return s0 * 4;
    }
    else
    {
        return s0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char a = note[0], b = note[1], c = note[2];

    //checking sharp flat or normal
    int m = 0, x;
    if (b == 'b')
    {
        m = -1;
        x = atoi(&c);
    }

    else if (b == '#')
    {
        m = 1;
        x = atoi(&c);
    }

    else
    {
        x = atoi(&b);
    }
    //finding n value
    double n = 0;
    if (a == 'A')
    {
        n = (x - 4) * 12 + m;
    }

    else if (a == 'B')
    {
        n = (x - 4) * 12 + 2 + m;
    }

    else if (a == 'C')
    {
        n = (x - 4) * 12 - 9 + m;
    }

    else if (a == 'D')
    {
        n = (x - 4) * 12 - 7 + m;
    }

    else if (a == 'E')
    {
        n = (x - 4) * 12 - 5 + m;
    }

    else if (a == 'F')
    {
        n = (x - 4) * 12 - 4 + m;
    }

    else if (a == 'G')
    {
        n = (x - 4) * 12 - 2 + m;
    }

    double l = n / 12;
    double h = pow(2, l) * 440.0;//putting it to power
    int g = h + 0.5;//rounding of
    return g;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)// checking blank
    {
        return true;
    }
    else
    {
        return false;
    }
}
