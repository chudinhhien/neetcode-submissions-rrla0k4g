class Solution {
public:

//brute, sort, compare segments
//map, window
    bool checkInclusion(string s1, string s2) {
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        if (n1 > n2 || n1 == 0  || n2 == 0)
        {
            return false;
        }
        std::sort(s1.begin(), s1.end());

        for (int i = 0; i <= n2 - n1; ++i)
        {
            std::string segment = s2.substr(i, n1);
            std::sort(segment.begin(), segment.end());
            if (segment == s1)
            {
                return true;
            }
        }
        return false;
    }
};
