#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i = -n + 1; i < n; i++)
    {
        for (int j = -n + 1; j < n; j++)
        {
            int max = (abs(i) > abs(j)) ? abs(i) : abs(j); 
            printf("%d ", max+1);
        }
        printf("\n");
    }

    return 0;
}