#include <stdio.h>

int main(){
    char inp[11],inp1[11];
    puts("Enter a string... scanf... ");
    scanf("%10s %10s",inp,inp1);
    printf("\n%s\n%s\n",inp,inp1);
/*
    puts("Enter a string... fgets... ");
    fgets(inp,sizeof(inp),stdin);
    printf("Ouput:\n%s\n",inp);
    */
    return 0;
}
