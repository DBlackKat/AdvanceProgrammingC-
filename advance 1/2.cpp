#include "stdlib.h"
#include "stdio.h"
#include "my_string.h"
#include "my_strlen.h"
#include "my_strcpy.h"

int main(){
    char test[] = "Hello World";
    char *empty2;
    char empty[50] = {'\0'};
    printf(" %d\n",my_strlen(test));
    
    empty2 = my_strcpy(empty,test);
    puts(empty2);
    printf("\n");
    puts(empty);
    
    empty2 = my_strncpy(empty,test,5);
    puts(empty2);
    printf("\n");
    puts(empty);
    
    empty2 = my_strcat(empty, test);
    puts(empty2);
    printf("\n");
    puts(empty);
    printf("\n");
    
    empty2 = my_strncat(empty, test,5);
    puts(empty);
    printf("\n");
    puts(empty2);
    
    char test1[] = "This is larger";
    char test2[] = "This is smaller";
    char test3[] = "This is jarger";
    
    printf("\nThe result for test 1 and test 2 is %d\n",my_strcmp(test1, test2));
    printf("The result for test 2 and test 2 is %d\n",my_strcmp(test2, test2));
    printf("The result for test 1 and test 3 is %d\n",my_strcmp(test1, test3));
    printf("The result for test 2 and test 1 is %d\n",my_strcmp(test2, test1));
    printf("my_strncmp!\n");
    printf("The result for test 1 and test 2 is %d\n",my_strncmp(test1, test2,5));
    printf("The result for test 2 and test 2 is %d\n",my_strncmp(test2, test2,5));
    printf("The result for test 1 and test 3 is %d\n",my_strncmp(test1, test3,11));
    
    
    char *find;
    printf("\nstrchr!\n");
    find = my_strchr(test2, 's');
    puts(find);
    find = my_strrchr(test2, 's');
    puts(find);
    printf("\nstrstr!\n");
    char test4[] = "is";
    find = my_strstr(test1, test4);
    puts(find);
    
    printf("\nstrtok!\n");
    char lorem[] = "Lorem ipsum dolor sit amet";
    find = my_strtok(lorem, ' ');
    puts(find);
    
    while(find!=NULL){
        find = my_strtok(NULL, ' ');
        puts(find);
    }
    return 0;
}