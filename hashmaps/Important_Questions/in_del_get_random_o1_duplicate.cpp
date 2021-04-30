class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    map<int, map<int, bool> > m;
    int size;
    vector<int> arr;
    RandomizedCollection() {
        m.clear();
        size = 0;
        arr.clear();   
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if(m.find(val) == m.end())
            ret = true;
        m[val][size] = true;
        size++;
        arr.push_back(val);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        int li = size-1;
        int i = m[val].begin()->first;
        
        m[val].erase(i);
        m[arr[li]][i] = true;
        m[arr[li]].erase(li);

        swap(arr[i], arr[li]);
        
        arr.pop_back();
        size--;
        if(m[val].empty())
            m.erase(val);
        return true;        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(size == 1)
            return arr[0];
        int r = rand();
        r = r%size;
        return arr[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */