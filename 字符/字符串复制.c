//²»Ê¹ÓÃstrcpy
#include <stdio.h>
 
int main()
{
    char s1[100], s2[100], i;
 
    printf("×Ö·û´® s1: ");
    scanf("%s",s1);
 
    for(i = 0; s1[i] != '\0'; ++i)
    {
        s2[i] = s1[i];
    }
 
    s2[i] = '\0';
    printf("×Ö·û´® s2: %s", s2);
 
    return 0;
}