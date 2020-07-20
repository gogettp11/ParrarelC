#include"functions.h"

void QuickSort(int*tab,int low,int high);
int partition(int*tab,int low,int high);

int card;

int main(int argc,char*argv[]){
    if(argc!=2){
        printf("Invalid amount of args");
        return -1;
    }
    card = atoi(argv[1]);
    int *tab=readFromFile("numbers.txt",card);

    QuickSort(tab,0,card-1);
    printTab(tab,100);
}

void QuickSort(int *tab,int low,int high){
    if(low < high){
        int divider = partition(tab,low,high);
        QuickSort(tab,low,divider-1);
        QuickSort(tab,divider+1,high);
    }
}
int partition(int*tab,int low,int high){
    int pivot=tab[high];
    int i=low-1;
    for (int j = low; j < high; j++){
        if (tab[j] < pivot){
            i++;
            int x=tab[i];
            tab[i]=tab[j];
            tab[j]=x;
        }
    }
    int x=tab[i + 1];
    tab[i+1]=tab[high];
    tab[high]=x;
    return (i + 1);
}