#ifndef 1_H
#define 1_H

extern int my_strlen(char *);
extern char *my_strcpy(char *dest,char *source);
 extern char *my_strncpy(char *dest,char *source,int t_num);
  extern char *my_strcat(char *dest,char *source);
char *my_strncat(char *dest,char *source,int endPoint);
int my_strcmp(char *s1,char *s2);
int my_strncmp(char *s1,char *s2,int number);
char *my_strchr(char *str,char character);
char *my_strrchr(char *str,char character);
char *my_strstr(char *s1,char *s2);
char *my_strtok(char *s1,char delimiter)；
#endif 