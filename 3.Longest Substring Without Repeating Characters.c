#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring_n2(char * s)
{
    char ch;
    int list[127];
    for (int i = 0; i < 127; i++)
        list[i] = -1;
    int length = 0;
    int max = 0;
    int index = 0;
    int i = 0;
    while (*(s + index))
    {
        ch = *(s + index);
        i = ch;
        if (list[i] == -1)
        {
            list[i] = index;
            length++;
            index++;
        }
        else
        {
            if (length > max)
                max = length;
            length = 0;
            index = list[i] + 1;
            for (int j = 0; j < 127; j++)
                list[j] = -1;
        }
    }
    if (length > max)
        return length;
    return max;
}

int lengthOfLongestSubstring(char * s)
{
    char ch;
    int list[127];
    for (int i = 0; i < 127; i++)
        list[i] = -1;
    int length = 0;
    int max = 0;
    int index = 0;
    int start = 0;
    while (*(s + index))
    {
        ch = *(s + index);
        if (list[ch] < start)
        {
            list[ch] = index;
            length++;
            index++;
        }
        else
        {
            if (length > max)
                max = length;
            length = index - list[ch];
            start = list[ch] + 1;
            list[ch] = index;
            index++;
        }
    }
    if (length > max)
        return length;
    return max;
}

int main()
{
    int len = 5000000;
    char str[len];
    for (int i = 0; i < len - 1; i++)
        str[i] = rand() % 26 + 97;
    str[len - 1] = '\0';
    int res = 0;
    clock_t t;
    double time_taken;
    t = clock();
    res = lengthOfLongestSubstring(str);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("n: %d, %f\n", res, time_taken);
    t = clock();
    res = lengthOfLongestSubstring_n2(str);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("n^2: %d, %f\n", res, time_taken);
}