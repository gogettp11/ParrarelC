#include"functions.h"
#include<omp.h>

void ParrarelSort(int*tab);
int card;

int main(int argc,char*argv[]){
    if(argc!=2){
        printf("Invalid amount of args");
        return -1;
    }
    card = atoi(argv[1]);
    int *tab=readFromFile("numbers.txt",card);
    ParrarelSort(tab);
    printTab(tab,100);
    return 0;
}

void ParrarelSort(int*tab){

    int x;
    int sorted = 0;
    int i=0;
    #pragma omp parallel num_threads(4) private(x)
    {
    while(!sorted){
        #pragma omp barrier
        sorted= 1;
        #pragma omp for
        for(i=0;i<card-1;i+=2){
            if(tab[i]>tab[i+1]){
                x=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=x;
                sorted=0;
            }
        }
        #pragma omp barrier
        #pragma omp for
        for(i=1;i<card-1;i+=2){
            if(tab[i]>tab[i+1]){
                x=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=x;
                sorted=0;
            }
        }
        #pragma omp barrier
        }
    }
}