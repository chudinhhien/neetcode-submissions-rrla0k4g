/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });        

        for(auto interval : intervals) {
            if(!pq.empty() && interval.start >= pq.top()) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};
