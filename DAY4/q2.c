int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int k = numsSize;

    while (i < k) {
        if (nums[i] == val) {
            nums[i] = nums[k - 1];
            k--;
        } else {
            i++;
        }
    }
    return k;
}
