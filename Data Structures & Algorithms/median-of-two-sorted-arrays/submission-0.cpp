class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;
        while(low <= high) {
            int partitionX = low + (high - low) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            double l1 = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            double r1 = (partitionX == m) ? INT_MAX : nums1[partitionX];

            double l2 = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            double r2 = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if(l1 <= r2 && l2 <= r1) {
                if((m + n) % 2 != 0) {
                    return max(l1, l2);
                }else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }else if(l1 > r2) {
                high = partitionX - 1;
            }else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};
