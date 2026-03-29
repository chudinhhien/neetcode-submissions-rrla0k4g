class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int l = 0;
        int r = n * m - 1;

        while(l <= r) {
            int tmp = l  + (r - l) / 2;
            cout << tmp << endl;
            int i = tmp / n;
            int j = tmp % n;

            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) r = tmp - 1;
            else l = tmp + 1;
        }

        return false;
    }
};
