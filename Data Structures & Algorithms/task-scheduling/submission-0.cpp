class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        int count_max = 0, max_freq = 0;

        for(int i = 0 ; i < 26 ; i++) {
            if(max_freq > 0 && freq[i] == max_freq) ++count_max;

            if(freq[i] > max_freq) {
                max_freq = freq[i];
                count_max = 1;
            }
        }

        int tmp = (max_freq - 1) * (n + 1) + count_max;
        int size = tasks.size();

        return max(tmp, size);
    }
};
