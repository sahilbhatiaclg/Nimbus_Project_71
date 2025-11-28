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


    while (fscanf(f,"%49[^,],%lf,%lf,%d\n",t.name,&t.watt,&t.hrs,&t.on)==4){
        array =realloc(array,(*n+1)*sizeof(thing));
        array[*n]=t;
        (*n)++;
    }
    fclose(f);
    return array;
}
