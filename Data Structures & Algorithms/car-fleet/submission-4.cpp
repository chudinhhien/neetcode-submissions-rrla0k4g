class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        
        // 1. Tạo mảng pair {vị trí, thời gian}
        for(int i = 0 ; i < n ; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // 2. Sắp xếp giảm dần theo vị trí (gần đích nhất lên đầu)
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b){
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = 0.0; // Thay thế cho Stack

        for(const auto& car : cars) {
            // Nếu thời gian xe này > thời gian của đoàn trước -> Tạo đoàn mới
            if(car.second > maxTime) {
                fleets++;
                maxTime = car.second; // Cập nhật "đội trưởng" mới
            }
            // Ngược lại: car.second <= maxTime thì nó tự động nhập đoàn (bị bỏ qua)
        }

        return fleets;
    }
};