#include<time.h>
#include"functions.h"
int main(){

    FILE *file = fopen("numbers.txt","w");
    srand(time(0));

    if(file==NULL){
        printf("Failed to connect to file");
        return -1;
    }

    for(int i = 0; i < MAX;i++){
        fprintf(file,"%d ", rand()%100000);
    }
    fclose(file);
}