class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int start = nums[i];
            if (uset.find(start - 1) != uset.end()) {
                continue;
            }
            int currAns = 1;
            while(uset.find(start + 1) != uset.end()){
                start++;
                currAns++;
            }
            if(currAns > ans){
                ans = currAns;

            }           
        }
        
        return ans;
    }
};
