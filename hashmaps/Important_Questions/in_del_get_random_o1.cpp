class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    int size;
    vector<int> arr;
    RandomizedSet() {
        m.clear();
        size = 0;
        arr.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m[val] == 0){
            size++;
            m[val] = size;
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m[val] != 0){
            int i = m[val] - 1;
            m[arr[size-1]] = i + 1;
            swap(arr[size-1], arr[i]);
            m[val] = 0;
            size--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(size == 1)
            return arr[0];
        int r = rand();
        r = r%size;
        return arr[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */