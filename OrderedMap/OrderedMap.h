#include<exception>
#include <list>
#include <map>
#include <utility>

template<typename key_type, typename value_type>
class OrderedMapIterator;

template<typename key_type, typename value_type>
class OrderedMap {
  friend class OrderedMapIterator<key_type, value_type>;
public:
  void put(key_type k, value_type v);
  value_type get(key_type k);
  void remove(key_type k);
  OrderedMapIterator<key_type, value_type> iterator();
private:
  std::map<key_type, std::pair<value_type, typename std::list<key_type>::iterator>> data;
  std::list<key_type> order; // order of keys
};

template<typename key_type, typename value_type>
void OrderedMap<key_type, value_type>::put(key_type k, value_type v) {
  if (data.find(k) != data.end()) {
    order.erase(data[k].second);
  }
  order.push_back(k);
  data[k].first = v;
  data[k].second = order.end() - 1;
}

template<typename key_type, typename value_type>
value_type OrderedMap<key_type, value_type>::get(key_type k) {
  if (data.find(k) != data.end()) {
    return data[k].first;
  } else {
    throw std::exception();
  }
}

template<typename key_type, typename value_type>
void OrderedMap<key_type, value_type>::remove(key_type k) {
  if (data.find(k) != data.end()) {
    order.erase(data[k].second);
    data.erase(k);
  }
}

template<typename key_type, typename value_type>
OrderedMapIterator<key_type, value_type> OrderedMap<key_type, value_type>::iterator() {
  return OrderedMapIterator<key_type, value_type>(this);
}

template<typename key_type, typename value_type>
class OrderedMapIterator {
public:
  OrderedMapIterator(OrderedMap<key_type, value_type> *data) : m(data) {
    n = data->order.begin();
  }
  std::pair<key_type, value_type> next();
  bool hasNext();
private:
  OrderedMap<key_type, value_type> *m;
  typename std::list<key_type>::iterator n;
};

template<typename key_type, typename value_type>
std::pair<key_type, value_type> OrderedMapIterator<key_type, value_type>::next() {
  if (hasNext()) {
    std::pair<key_type, typename std::list<key_type>::iterator> entry = m->data[*n];
    ++n;
    return make_pair(*n, entry.first);
  } else {
    throw std::exception();
  }
}

template<typename key_type, typename value_type>
bool OrderedMapIterator<key_type, value_type>::hasNext() {
  return n != m->order.end();
}
