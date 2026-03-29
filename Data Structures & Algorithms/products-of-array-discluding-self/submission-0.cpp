class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        int proPrefix[n];
        int proPrefixRev[n];

        proPrefix[0] = nums[0];

        for(int i = 1 ; i < n ; i++) {
            proPrefix[i] = proPrefix[i-1] * nums[i];
        }

        proPrefixRev[n - 1] = nums[n - 1];

        for(int i = n - 2 ; i >= 0 ; i--) {
            proPrefixRev[i] = proPrefixRev[i + 1] * nums[i];
        }

        output[0] = proPrefixRev[1];
        output[n-1] = proPrefix[n-2];

        for(int i = 1 ; i < n - 1 ; i++) {
            output[i] = proPrefix[i-1] * proPrefixRev[i+1];
        }
 
        return output;
    }
};
