class Solution {
public:
    int countBit1(int n) {
        int count = 0;
        while(n != 0) {
            n = n & (n - 1);
            ++count;
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);

        for(int i = 0 ; i <= n ; i++) {
            output[i] = countBit1(i);
        }

        return output;
    }
};
