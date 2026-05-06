int canSplit(int* nums, int numsSize, int k, int maxSum) {
    int count = 1;   // at least one subarray
    int currSum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (currSum + nums[i] <= maxSum) {
            currSum += nums[i];
        } else {
            count++;
            currSum = nums[i];

            if (count > k) {
                return 0; // not possible
            }
        }
    }
    return 1; // possible
}

int splitArray(int* nums, int numsSize, int k) {
    int low = nums[0], high = 0;

    // find max element and sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase
        }
    }

    return ans;
}
