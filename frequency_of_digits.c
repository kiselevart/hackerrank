#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *s = malloc(sizeof *s *1000);
    int nums[10] = {0};

    scanf("%s", s);
    
    for(int i=0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            nums[s[i]-'0']++;
        }
    }
    
    for (int i=0; i<10; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
