#include"functions.h"

void BubbleSort(int*tab,int size);
int card;

int main(int argc,char*argv[]){
    if(argc!=2){
        printf("Invalid amount of args");
        return -1;
    }
    card = atoi(argv[1]);
    int *tab=readFromFile("numbers.txt",card);
    BubbleSort(tab, card);
    printTab(tab,100);
    return 0;
}
void BubbleSort(int*table,int size){
    int i, j, temp;
	for (i = 0; i<size-1; i++){
		for (j=0; j<size-1-i; j++){
			if (table[j] > table[j+1]){
				temp = table[j+1];
				table[j+1] = table[j];
				table[j] = temp;
			}
		}
    }
}