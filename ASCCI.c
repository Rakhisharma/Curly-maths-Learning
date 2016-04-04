#include <stdio.h>

int main()
{
	
    FILE *fh;
    int  ch;
    int i;
     
    fh = fopen("ascii.txt","r");
 
    for(i=0;i<2;i++)
     fprintf(fh,"\n%d - %c",i,i);
 
    fclose(fh);
    return 0;
}
