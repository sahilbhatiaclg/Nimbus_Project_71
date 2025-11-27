#include<stdio.h>
#include<string.h>
#include<stdlib.h>


 //STRUCTURE DEFINATION

 
typedef struct {
    char name[50];
    double watt;
    double hrs;
    int on;

}thing;

// LOADING CSV 

thing* loading(const char *file, size_t *n){
    FILE *f=fopen(file,"r");
    if(!f) return NULL;
    thing t,*array = NULL;
    *n=0;
