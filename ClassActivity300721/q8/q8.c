#include <stdio.h>
#include "qsort.c"

int main(){
    FILE *fp1;
    char buffer[255];
    int line = 0;
    int x,y;
    fp1 = fopen("/home/s6301012620197/Documents/ClassActivity300721/q7/data.txt", "r");
    
    //open file and create array ***********************
    if(fp1 == NULL) printf("Error Can't Open File\n");
    else
    {
        printf("File is Opened\n");
        while(fgets(buffer, 255, fp1) != NULL)
        {
            printf(buffer);
            line++;
        }
        printf("%d lines\nFinished\n", line);
     
        int data[line];

        printf("Create Data Array size = %d\n", line);
        int linew = 0;
        rewind(fp1);
        while(linew < line)
            {
                fscanf(fp1, "%d", &x);
                data[linew] = x;
                printf("Read String %d\n", data[linew]);
                linew++;
            }
        printf("Read File Completed\n");
        fclose(fp1);
        //**********************************************

        //quicksort
        printf("Order of Sorted elements: ");
        quicksort(data, 0, linew-1);
        for(int i = 0;i < linew;i++) printf(" %d",data[i]);
        printf("\n");
        //**********************************************

        //file saving process
        FILE *fp2;
        fp2 = fopen("data_sorted.txt", "w+");
        for(int i = 0;i < linew;i++)
        {
            printf("Save String %d\n", data[i]);
            fprintf(fp2, "%d\n", data[i]);
        }
        fclose(fp2); 
    }
    return 0;
}
