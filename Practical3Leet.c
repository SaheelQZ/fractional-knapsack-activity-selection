#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int *rowA = *(int**)a;
    int *rowB = *(int**)b;
    return rowB[1] - rowA[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), comp);

    int total = 0;
    for (int i = 0; i < boxTypesSize && truckSize > 0; i++) {
        int count = boxTypes[i][0];
        int units = boxTypes[i][1];
        int take = (count < truckSize) ? count : truckSize;
        total += take * units;
        truckSize -= take;
    }
    return total;
}

int main() {
    int arr[][2] = {{5,10},{2,5},{4,7},{3,9}};
    int boxTypesSize = 4;
    int truckSize = 10;

    int* boxTypes[boxTypesSize];
    for (int i = 0; i < boxTypesSize; i++) {
        boxTypes[i] = arr[i];
    }

    int boxTypesColSize[boxTypesSize];
    for (int i = 0; i < boxTypesSize; i++) {
        boxTypesColSize[i] = 2;
    }

    int result = maximumUnits(boxTypes, boxTypesSize, boxTypesColSize, truckSize);
    printf("Maximum Units on the Truck = %d\n", result);

    return 0;
}