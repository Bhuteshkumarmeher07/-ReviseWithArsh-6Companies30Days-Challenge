    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>st;
        int size = nums.size();

        for(int i=0; i<size; i++){
            for(int j = i; j < size; j++){
                string temp;
                int cnt = 0;

                for(int m = i; m <= j; m++){
                    temp.push_back(nums[m]);
                    if(nums[m] % p == 0){
                        cnt++;
                    }
                    if(cnt <= k){
                        st.insert(temp);
                    }
                }
            }
        }
        return st.size();
    }
