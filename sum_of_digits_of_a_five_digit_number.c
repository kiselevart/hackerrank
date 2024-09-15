    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>

    int main() {
        
        int n;
        scanf("%d", &n);

        int sum = 0; 

        for (int i=1; i<=5; i++) {
            int divisor = pow(10, i);
            int remainder = n%divisor;

            divisor = divisor/10;

            int digit = remainder/divisor;
            sum += digit;
        }

        printf("%d", sum);

        return 0;
    }