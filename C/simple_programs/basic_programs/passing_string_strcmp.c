#include <stdio.h>
#include <string.h>

int strcmp_return(const void *a, const void *b){
    char *str1 = (char *)a;
    char *str2 = (char *)b;
  
    return strcmp(str1,str2); 
}
int main(){
    char *args[] = {"acid","bad","c"};
//    printf("%d\n",strcmp_return(args[0],args[1]));
    printf("%d\n",strcmp_return("cid","bad"));

    return 0;   
}
