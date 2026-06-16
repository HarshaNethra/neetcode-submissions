class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=hash.find(key);
        if(it==hash.end()) return -1;

        auto node=it->second;
        cache.splice(cache.begin(), cache, node);
        
        return node->second;
    }
    
    void put(int key, int value) {
        auto it=hash.find(key);
        if(it!=hash.end()) {
            auto node=it->second;
            node->second=value;
            cache.splice(cache.begin(), cache, node);
        }
        else {
            cache.push_front({key, value});
            hash[key]=cache.begin();
            if(cache.size()>cap) {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */