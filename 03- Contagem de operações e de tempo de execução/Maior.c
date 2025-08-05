#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "numbervector.h"
#include "stopwatch.h"
#include "filemanager.h"

/*int getLargestNumber(numberVector_t numberVector)
{
    int largestNumber = INT_MIN;
    int actualNumber;

    for(int i = 0; i < numberVector.vectorSize; ++i)
    {
        actualNumber = numberVector.numbers[i];
        if(actualNumber > largestNumber)
            largestNumber = actualNumber;
    }

    return largestNumber;
}

void inverter_vetor(numberVector_t vetor) {
    int aux;
    int fim = vetor.vectorSize - 1;

    for(int i = 0; i < (vetor.vectorSize/2) ; i++){
      aux = vetor.numbers[i];
      vetor.numbers[i] = vetor.numbers[fim - i];
      vetor.numbers[fim -i] = aux;
    }

    return;
}

int busca_sequencial(numberVector_t vetor, int num) {
    for(int i = 0; i < vetor.vectorSize; i++) {
        if(vetor.numbers[i] == num){
            return i;
        }
    }
    return (-1200);
}

int recursive_binary_search(numberVector_t array, int number, int low_index, int high_index){

    if(low_index <= high_index){
        int mid_index = (low_index + high_index) / 2;

        if(array.numbers[mid_index] == number) return mid_index;

        else if(array.numbers[mid_index]  < number){
            return recursive_binary_search(array, number, mid_index + 1, high_index);
        }

        else if(array.numbers[mid_index] > number){
            return recursive_binary_search(array, number, low_index, mid_index - 1);
        }
    }

    return -1;
}

int busca_binaria(numberVector_t vetor, int num){
    int comeco = 0;
    int fim = vetor.vectorSize - 1;
    int meio = 0;

    while(comeco <= fim) {
        meio = (comeco + fim) / 2;

        if(vetor.numbers[meio] < num){
            comeco = meio + 1;
        }
        else if(vetor.numbers[meio] > num){
            fim = meio - 1;
        }

        else return meio;
    }

    return (-1000);
}
*/
int busca_recursiva(numberVector_t vetor, int comeco, int fim, int num) {

    int meio = (comeco + fim) / 2;

    if (comeco > fim) {
        return -1000;
    }

    if (vetor.numbers[meio] == num) {
        return meio;
    }

    if (vetor.numbers[meio] < num) { 
        return busca_recursiva(vetor, meio + 1, fim, num);


    } else {  
        return busca_recursiva(vetor, comeco, meio - 1, num);
    }
    return (-1000);
} 

int main()
{
    numberVector_t numberVector;
    int nExecutions, vectorSize;
    //int largestNumber;
    int num_qualquer = 0;
    double averageTime = 0.0;
    clock_t startTime, endTime;

    scanf("%d %d", &vectorSize, &nExecutions);

    numberVector = readNumberBinaryFile(vectorSize);

    for(int i = 0; i < nExecutions; ++i)
    {
        startTime = clock();
        //largestNumber = getLargestNumber(numberVector);
        //inverter_vetor(numberVector);
        //num_qualquer = busca_sequencial(numberVector, -10);
        num_qualquer = busca_binaria(numberVector, -1);
        //num_qualquer = busca_recursiva(numberVector, 0 , vectorSize -1, -10);
        endTime = clock();
        #ifdef DEBUG
            printf("The largest number is: %d\n", largestNumber);
        #else
            averageTime+=getExecutionTime(startTime, endTime);
        #endif
    }

    #ifndef DEBUG
        averageTime = averageTime/(double)nExecutions;
        saveTimeToFile(vectorSize, averageTime, nExecutions);
    #endif

    free(numberVector.numbers);

}
