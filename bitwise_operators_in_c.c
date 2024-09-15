#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int and, or, xor = 0;
  int maxAnd = 0;
  int maxOr = 0;
  int maxXor = 0;
  
  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
        and = i&j;
        or = i|j;
        xor = i^j;

        if (and<k && and>maxAnd) {maxAnd = and;}
        if (or<k && or>maxOr) {maxOr = or;}
        if (xor<k && xor>maxXor) {maxXor = xor;}
    }
  }

  printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
