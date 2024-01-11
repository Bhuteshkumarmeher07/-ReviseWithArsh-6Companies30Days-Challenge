class Solution {
public:
    int incremovableSubarrayCount(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Iterate through all possible subarrays
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                bool isIncreasing = true;
                int lastElement = -1;
                
                // Check each element within or outside the subarray
                for (int k = 0; k < n; k++) {
                    if (k >= start && k <= end) {
                        continue; // Skip elements within the subarray
                    }
                    isIncreasing &= (lastElement < nums[k]); // Check if the current element is greater than the last one
                    lastElement = nums[k]; // Update the last element
                }
                
                count += isIncreasing; // Increment count if the subarray is "incremovable"
            }
        }
        return count; // Return the total count of "incremovable" subarrays
    }
};
