#include"functions.h"

int *readFromFile(char* filename,int card){

    int *tab = (int*) malloc(sizeof(int)*card);
    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("Invalid or not existing file");
        exit(-1);
    }
    if(card>NUM_CARDINALITY){
        printf("too small amount of numbers to read");
        exit(-1);
    }
    for(int i=0;i<card;i++){
        fscanf(file,"%d", &tab[i]);
    }
    fclose(file);
    return tab;
}

void printTab(int *tab,int cardinality){
    for(int i=0;i<cardinality;i++){
        printf("%d ",tab[i]);
    }
}