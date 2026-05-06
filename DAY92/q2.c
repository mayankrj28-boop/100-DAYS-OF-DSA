#include <stdlib.h>

// swap helper
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    int target = numsSize - k;

    while (left <= right) {
        // random pivot
        int pivot = nums[left + rand() % (right - left + 1)];

        int lt = left, i = left, gt = right;

        // 3-way partition
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[i], &nums[lt]);
                i++; lt++;
            } 
            else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } 
            else {
                i++;
            }
        }

        // decide which side to go
        if (target >= lt && target <= gt) {
            return pivot;
        } 
        else if (target < lt) {
            right = lt - 1;
        } 
        else {
            left = gt + 1;
        }
    }

    return -1; // should never happen
}
