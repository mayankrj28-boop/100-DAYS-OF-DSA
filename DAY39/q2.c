//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    Pair arr[numsSize];
    int count = 0;

    // Count frequency
    for(int i = 0; i < numsSize; i++) {
        int found = 0;
        
        for(int j = 0; j < count; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[count].num = nums[i];
            arr[count].freq = 1;
            count++;
        }
    }

    // Sort by frequency descending
    qsort(arr, count, sizeof(Pair), cmp);

    int* result = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}
