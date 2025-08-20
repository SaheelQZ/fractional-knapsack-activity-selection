#include<stdio.h>
#include<stdlib.h>

#define MAX 11

struct Activity{
    int start;
    int finish;
    char name[5];
    int profit;
};

int compare(void const *a, void const*b){
    struct Activity *a1 = (struct Activity *)a;
    struct Activity *a2 = (struct Activity *)b;
    return a1->finish - a2->finish;
}

void ActivitySelection(struct Activity arr[], int n){
    qsort(arr, n, sizeof(struct Activity), compare);
    printf("Selected Activities:\n");
    int i = 0;
    printf("%s (Start:%d, Finish:%d, Profit:%d)\n", arr[i].name, arr[i].start, arr[i].finish, arr[i].profit);
    int lastFinish = arr[i].finish;
    int totalProfit = arr[i].profit;

    for(int j = 1; j < n; j++){
        if(arr[j].start >= lastFinish){
            printf("%s (Start:%d, Finish:%d, Profit:%d)\n", arr[j].name, arr[j].start, arr[j].finish, arr[j].profit);
            totalProfit += arr[j].profit;
            lastFinish = arr[j].finish;
        }
    }
    printf("\nTotal Profit = %d\n", totalProfit);
}

int main(){
    struct Activity arr[MAX] = {
        {1, 4, "A1", 10},
        {3, 5, "A2", 15},
        {0, 6, "A3", 14},
        {5, 7, "A4", 12},
        {3, 9, "A5", 20},
        {5, 9, "A6", 30},
        {6, 10, "A7", 32},
        {8, 11, "A8", 28},
        {8, 12, "A9", 30},
        {2, 14, "A10", 40},
        {12, 16, "A11", 45}
    };

    ActivitySelection(arr, MAX);
    return 0;
}