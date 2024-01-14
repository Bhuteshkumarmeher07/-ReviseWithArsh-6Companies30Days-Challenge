class Solution {
public:
    int maxRotateFunction(std::vector<int>& A) {
        if (A.empty()) return 0;
        int sum = 0, ret = 0, k = 0, len = A.size();
        
        if (len == 1) return 0;
        
        // Calculate the initial sum and F(0)
        for (int n : A) {
            sum += n;
            ret += n * k++;
        }
        
        int result = ret;
        
        // Calculate F(i) for each rotation and find the maximum
        for (int i = len - 1; i >= 1; i--) {
            int current = ret + sum - len * A[i];
            ret = current;
            result = std::max(result, current);
        }
        
        return result;
    }
};
