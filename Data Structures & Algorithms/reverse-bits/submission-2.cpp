class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int left = 31;
        int right = 0;

        while(left > right) {
            uint32_t bitRight = (n >> right) & 1;
            uint32_t bitLeft = (n >> left) & 1;

            if(bitRight != bitLeft) {
                n = n ^ (1U << right);
                n = n ^ (1U << left); 
            }

            ++right;
            --left;
        }

        return n;
    }
};
