class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for ( int& number : nums )
        {
            frequency[number] += 1;
        }

        for ( auto & [number, count] : frequency )
        {
            buckets[count].push_back(number);
        }

        std::vector<int> result;
        int i = nums.size();
        while( result.size() < k && i > 0 )
        {
            if ( !buckets[i].empty() )
            {
                for ( int x : buckets.at(i))
                {
                    result.push_back(x);
                    if ( result.size() == k ) return result;
                }
            }
            --i;
        }
    return result;
    }
};