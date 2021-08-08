#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N;
    FILE *file_pointer;
    file_pointer = fopen("data.txt", "w+");
    srand(time(NULL));

    printf("How many numbers ? : ");
    scanf("%d", &N);

    for(int i = 0;i < N;i++)
        fprintf(file_pointer,"%d\n", rand()%1000);

    fclose(file_pointer);
    return 0;
}



