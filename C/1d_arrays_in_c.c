#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);

    int *nums = malloc(sizeof *nums * n);

    for (int i=0; i<n; i++) {
        if (scanf("%d", &nums[i]) != 1) {break;}
    }
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += nums[i];
    }

    printf("%d", sum);

    return 0;
}