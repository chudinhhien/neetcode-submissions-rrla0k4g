class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string log : logs) {
            if(log == "../") {
                if(ans > 0) ans -= 1;
                else ans = 0;
            }else if(log != "./"){
                ans += 1;
            }
        }

        return ans;
    }
};