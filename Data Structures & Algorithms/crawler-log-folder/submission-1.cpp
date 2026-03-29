class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(const string& log : logs) {
            if(log == "../") {
                if(ans > 0) ans -= 1;
            }else if(log != "./"){
                ans += 1;
            }
        }

        return ans;
    }
};