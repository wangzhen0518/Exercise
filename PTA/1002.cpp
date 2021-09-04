#include <iostream>
#include <cmath>

int *divide(int n)
{
    int len = log10(n) + 1;
    int *ar = new int[len];
    int i = 0;
    while (n != 0)
    {
        ar[i] = n % 10;
        n = n / 10;
        i++;
    }
    return ar;
}

void Print(int n)
{
    int len = log10(n) + 1;
    int *ar = divide(n);
    const char *out[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int i = len - 1; i > 0; i--)
        std::cout << out[ar[i]] << " ";
    std::cout << out[ar[0]];
    delete[] ar;
}

int main()
{
    char in[100];
    int len = 0;
    while ((in[len] = std::cin.get()) != '\n')
        len++;
    in[len] = '\0';
    int *ar = new int[len];
    for (int i = 0; i < len; i++)
        ar[i] = int(in[i]) - 48;
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += ar[i];
    Print(sum);
    delete[] ar;
    return 0;
}