/*
A
B B
C C C
D D D D
E E E E E
*/
#include <stdio.h>
int main()
{
    int i, j;
    char input, alphabet = 'A';
 
    printf("ÊäÈë´óĞ´×ÖÄ¸: ");
    scanf("%c",&input);
 
    for(i=1; i <= (input-'A'+1); ++i)
    {
        for(j=1;j<=i;++j)
        {
            printf("%c", alphabet);
        }
        ++alphabet;
 
        printf("\n");
    }
    return 0;
}