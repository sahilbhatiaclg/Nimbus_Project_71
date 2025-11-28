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
//SAVE CSV

void store(const char *file,thing *array,size_t n){
    FILE *f=fopen(file,"w");
    if(!f) return;
    for(size_t i=0;i<n;i++)
    fprintf(f,"%s,%.2f,%.2f,%d\n", array[i].name, array[i].watt, array[i].hrs, array[i].on);
    fclose(f);
}



