class LRUCache{
public:
    LRUCache(int capacity) : capa(capacity) {
        
    }
    
    int get(int key) {
        if (data.find(key) != data.end()) {
            order.erase(data[key].second);
            order.push_back(key);
            auto it = order.end();
            data[key].second = --it;
            return data[key].first;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
         if (data.find(key) != data.end()) {
            order.erase(data[key].second);
        } else {
            while (order.size() >= capa) {
                data.erase(order.front());
                order.pop_front();
            }
        }
        order.push_back(key);
        auto it = order.end();
        data[key].second = --it;
        data[key].first = value;
    }
private:
    int capa;
    list<int> order;
    map<int, pair<int, list<int>::iterator> > data;
};