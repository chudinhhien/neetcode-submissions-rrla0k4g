class Solution {
public:
    int check(vector<int>& piles, int rate) {
        int res = 0;
        for(int pile : piles){
            res += (pile + rate - 1) / rate;
        }

        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int l = 1;
        int r = 0;
        for(int pile : piles) {
            r = max(r, pile);
        }

        while(l <= r) {
            int tmp = l + (r - l) / 2;
            
            if(check(piles, tmp) > h) {
                l = tmp + 1;
            }else {
                k = tmp;
                r = tmp - 1;
            }
        } 
        return k;
    }
};
