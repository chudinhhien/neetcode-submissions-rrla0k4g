class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            ý tưởng là tạo cycle linked list
            nums[i]: next của i
            -> dùng thuật toán "Rùa và thỏ"
            -> tìm được điểm giao nhau
            -> tìm result 
        */ 

        int fast = 0;
        int slow = 0;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast != slow);

        slow = 0;

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};
