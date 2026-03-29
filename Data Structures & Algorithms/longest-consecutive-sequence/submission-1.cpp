class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        if(nums.size() == 0) return 0;

        int longest_steak = 1;
        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()){
                int start_num = num;
                int current_steak = 1;

                while(numSet.find(start_num + 1) != numSet.end()) {
                    current_steak += 1;
                    start_num = start_num + 1;
                }

                longest_steak = max(longest_steak, current_steak);
            }
        }        

        return longest_steak;       
    }
};
