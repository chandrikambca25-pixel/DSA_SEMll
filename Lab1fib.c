#include <stdio.h>

int fibonacci(int n)
{
    if(n == 0)   // Base condition 1
        return 0;
    else if(n == 1)   // Base condition 2
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive calls
}

int main()
{
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}