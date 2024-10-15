class LRUCache {
public:
    map<int, std::list<pair<int,int>>::iterator>myMap;
    list<pair<int,int>> myList;
    int cap;
    LRUCache(int capacity) {
        myMap.clear();
        myList.clear();
        cap = capacity;
    }
    
    int get(int key, int value = -1) {

        if(myMap.find(key) != myMap.end())
        {
            std::list<pair<int,int>>::iterator listItr = myMap[key];
            cout<<"Ankit "<<key<<" "<<value<<" "<<&listItr<<endl;
            
            int key = (*listItr).first;
            int val = (*listItr).second;

            if(value != -1)
                val = value;

            pair<int,int> myPair = {key, val};
            myList.erase(listItr);
            myList.push_front(myPair);
            
            myMap[key] = myList.begin();
            //cout<<"ABC "<<*myList.begin()<<" "<<&listItr<<endl;
            return (*myMap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(myMap.find(key) != myMap.end())
        {
            int xxx = get(key, value);
            myMap[key] = myList.begin();
            return;
        }

        if(myList.size() == cap)
        {
            std::list<pair<int,int>>::iterator valToRemove = std::prev(myList.end());
            myMap.erase((*valToRemove).first);
            myList.pop_back();
        }
        myList.push_front(make_pair(key, value));
        myMap[key] = myList.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */