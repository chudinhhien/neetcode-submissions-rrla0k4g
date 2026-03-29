class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> cars;
        for(int i = 0 ; i < n ; i++) {
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b){
            return a.first > b.first;
        });

        stack<double> rs;
        for(const auto& car : cars) {
           if(rs.empty()) {
            rs.push(car.second);
           }else {
            if(car.second > rs.top()) {
                rs.push(car.second);
            }
           }
        }

        return rs.size();
    }
};
