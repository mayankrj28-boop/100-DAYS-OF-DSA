int maxSubArray(int* nums, int numsSize) {
    
    int max_current = nums[0];
    int max_global = nums[0];
    
    for(int i = 1; i < numsSize; i++) {
        
        // Either extend the previous subarray or start new from current element
        if(max_current + nums[i] > nums[i]) {
            max_current = max_current + nums[i];
        } else {
            max_current = nums[i];
        }
        
        // Update global maximum
        if(max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}
