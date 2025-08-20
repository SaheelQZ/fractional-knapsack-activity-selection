#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50
#define Capacity 850

struct box{
    int weight;
    int profit;
    float ratio;
};

float Knapsack(struct box items[], int n, int capacity){
    float TotalProfit = 0.0;
    int CurrentWeight = 0;

    for(int i=0;i<n;i++){
        if(items[i].weight == 0){
            continue;
        }
        if(CurrentWeight + items[i].weight <= capacity){
            CurrentWeight += items[i].weight;
            TotalProfit += items[i].profit;
        }
        else{
            int remaining = capacity - CurrentWeight;
            TotalProfit += (items[i].profit) * ((float)remaining / items[i].weight);
            break;
        }
    }
    return TotalProfit;
}

int compweight(const void *a, const void *b){
    struct box *b1 = (struct box*)a;
    struct box *b2 = (struct box*)b;
    return b1->weight - b2->weight;
}

int compprofit(const void *a, const void *b){
    struct box *b1 = (struct box*)a;
    struct box *b2 = (struct box*)b;
    return b2->profit - b1->profit;
}

int compratio(const void *a, const void *b){
    struct box *b1 = (struct box*)a;
    struct box *b2 = (struct box*)b;
    if(b2->ratio > b1->ratio)
        return 1;
    else if(b2->ratio < b1->ratio)
        return -1;
    else
        return 0;
}

int main(){
    int i;
    int weights[MAX] = {7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8, 15, 42, 9, 0, 42, 47, 52, 32, 26, 48, 55,
6, 29, 84, 2, 4, 18, 56, 7, 29, 93, 44, 71, 3, 86, 66, 31, 65, 0, 79, 20, 65, 52, 13};
    int profits[MAX] = {360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147, 78, 256, 63, 17, 120,
164, 432, 35, 92, 110, 22, 42, 50, 323, 514, 28, 87, 73, 78, 15, 26, 78, 210, 36, 85, 189, 274,
43, 33, 10, 19, 389, 276, 312};
    
    struct box set[MAX];
    for(i=0;i<MAX;i++){
        set[i].weight = weights[i];
        set[i].profit = profits[i];
        if(weights[i]!=0)
            set[i].ratio = (float)profits[i] / weights[i];
        else
            set[i].ratio = 0;
    }

    clock_t start, end;
    float value, time_taken;

    //Minimum Weight
    qsort(set, MAX, sizeof(struct box), compweight);
    start = clock();
    value = Knapsack(set, MAX, Capacity);
    end = clock();
    time_taken = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Minimum weight:\nValue - %.2f \nTime - %f sec\n\n",value ,time_taken);

    //Maximum Profit
    qsort(set, MAX, sizeof(struct box), compprofit);
    start = clock();
    value = Knapsack(set, MAX, Capacity);
    end = clock();
    time_taken = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum Profit:\nValue - %.2f \nTime - %f sec\n\n",value ,time_taken);

    //Profit/Weight Ratio
    qsort(set, MAX, sizeof(struct box), compratio);
    start = clock();
    value = Knapsack(set, MAX, Capacity);
    end = clock();
    time_taken = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Profit/Weight Ratio:\nValue - %.2f \nTime - %f sec\n\n",value ,time_taken);
}