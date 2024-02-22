#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
    if (low > high)
        return -1; // Value not found

    int mid = (low + high) / 2;

    if (numbers[mid] == value)
        return mid; // Value found at mid index
    else if (numbers[mid] < value)
        return search(numbers, mid + 1, high, value); // Search right half
    else
        return search(numbers, low, mid - 1, value); // Search left half
}

void printArray(int numbers[], int sz)
{
    int i;
    printf("Number array: ");
    for (i = 0; i < sz; ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, numInputs;
    int value, index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray =malloc(countOfNums * sizeof(int));
        float average = 0;

        for (i = 0; i < countOfNums; i++)
        {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);

        if (index >= 0)
        {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        }
        else
        {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
