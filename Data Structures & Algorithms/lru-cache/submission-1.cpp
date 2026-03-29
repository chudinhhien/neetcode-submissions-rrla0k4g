class LRUCache {
    int cap;
public:
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMp;

    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (cacheMp.find(key) == cacheMp.end()) return -1;

        // Đưa lên ĐẦU (Mới nhất)
        cacheList.splice(cacheList.begin(), cacheList, cacheMp[key]);
        return cacheMp[key]->second;
    }
    
    void put(int key, int value) {
        // TRƯỜNG HỢP 1: Key đã có -> Cập nhật và đưa lên đầu
        if (cacheMp.find(key) != cacheMp.end()) {
            cacheMp[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMp[key]);
            return; // Xong rồi thì về, không chạy xuống dưới nữa!
        }

        // TRƯỜNG HỢP 2: Key mới -> Phải thêm vào
        // Nếu đầy thì đuổi thằng ở CUỐI (LRU - Least Recently Used)
        if (cacheMp.size() == cap) {
            int lastKey = cacheList.back().first;
            cacheMp.erase(lastKey);
            cacheList.pop_back();
        }

        // Thêm đứa mới vào ĐẦU
        cacheList.push_front({key, value});
        cacheMp[key] = cacheList.begin();
    }
};