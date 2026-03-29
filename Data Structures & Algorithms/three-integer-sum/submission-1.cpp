class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> st;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    st.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }else if(sum > 0){
                    end--;
                }else{
                    start++;
                }
            }
        }

        for(auto v : st){
            result.push_back(v);
        }

        return result;
    }
};
