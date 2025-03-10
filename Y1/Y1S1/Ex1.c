#include <string.h>
#include <stdio.h>

fun(char *w, int n)
{
    char t, *s1, *s2;
    s1 = w;
    s2 = w + n - 1;
    while (s1 < s2)
    {
        t = *s1++;
        *s1 = *s2--;
        *s2 = t;
    }
}