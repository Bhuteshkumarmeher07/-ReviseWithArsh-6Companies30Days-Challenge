class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(int i=0; i<arr1.size(); i++){
            int first = arr1[i];
            bool flag = false;
            for(int j=0; j<arr2.size(); j++){
                int second = arr2[j];
                if(abs(second-first) <= d){
                    flag = true;
                    break;
                }
            }
            if(flag == false) count++;
        }
        return count;
    }
};
