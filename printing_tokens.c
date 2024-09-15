#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    char *token;
    char *rest = s;
    
    while((token = strtok_r(rest, " ", &rest))) {
        printf("%s\n", token);
    }
    //Write your logic to print the tokens of the sentence here.
    return 0;
}