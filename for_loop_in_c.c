#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    char * numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i=a; i<=b; i++) {
        if (i < 10) {
            printf("%s\n", numbers[i]);
        }
        else {
            if (i%2 == 0) {
                printf("even\n");
            }
            else {
                printf("odd\n");
            }
        }
    }
    return 0;
}

