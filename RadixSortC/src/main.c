#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));
    int vaux[tamanho];

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
    
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    vaux[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = vaux[i];
    	exp *= 10;
    }

    free(b);
}



void quickSort(int vetor[], int tamanho, int start, int end){
    
    int aux;
    int pivot = vetor[start];
    int l = start;
    int r = end;
    
    while( r >= l ){
        while( vetor[l] < pivot ){
            l++;
        }
        while(vetor[r] > pivot){
            r--;
        }
        if ( r >= l){
            aux = vetor[l];
            vetor[l] = vetor[r];
            vetor[r] = aux;
            l++;
            r--;
        }
        
        
    }
    
    if(start < r){
        quickSort(vetor, tamanho, start, r);
    }
    if(l < end){
        quickSort(vetor,tamanho, l, end );
    }
    
    
}

int main()
{
    srand (time(NULL));
    int tamanho=1000000;
    /*
    printf("Tamanho: ");
    scanf("%d",&tamanho);*/
    
    int vet[tamanho]; 
    
    double totalr=0.0,totalq=0.0;
    
    for(int i=0;i<50;i++){
        
    
        for(int i=0;i<tamanho;i++){
            vet[i] = rand() % 9999;
            //printf("%d ",vet[i]);
        }
        
        double time_spent = 0.0;
    	clock_t begin = clock();
        
        radixSort(vet, tamanho);
        
        clock_t end = clock();
    	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    	totalr+=time_spent;
    	printf("\n\nTempo Gasto radixSort: %lf", time_spent);
        
        /*printf("\n\nVetor ordenado:\n");
        for (int i = 0; i < tamanho; i++)
        printf("%d " ,vet[i]);
        
        int arr[] = { 10, 7, 8, 9, 1, 5 };
        int N = sizeof(arr) / sizeof(arr[0]);
        printf("\n\nN: %d",N);*/
        
        
        for(int i=0;i<tamanho;i++){
            vet[i] =  rand() % 9999;
          //  printf("%d ",vet[i]);
        }
        
        time_spent = 0.0;
        begin = clock();
        
        quickSort(vet, tamanho, 0, tamanho-1);
        
        end = clock();
    	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    	totalq+=time_spent;
    	printf("\n\nTempo Gasto quickSort: %lf", time_spent);
    	
    /*	printf("\n\nVetor ordenado:\n");
        for (int i = 0; i < tamanho; i++)
        printf("%d " ,vet[i]);*/
    }
    
    printf("\n\nTempo Total Gasto radixSort: %lf", totalr);
    printf("\n\nTempo Total Gasto quickSort: %lf", totalq);
    
    printf("\n\nTempo Médio Gasto radixSort: %lf", totalr/50);
    printf("\n\nTempo Médio Gasto quickSort: %lf", totalq/50);
    return 0;
}
