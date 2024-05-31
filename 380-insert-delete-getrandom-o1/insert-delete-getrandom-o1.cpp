class RandomizedSet {
private:
    vector<int> vect;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        vect.push_back(val);
        mp[val] = vect.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int last = vect.back();
        mp[last] = mp[val];
        vect[mp[val]] = last;
        vect.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {  int randomIndex = rand() % vect.size();
        return vect[randomIndex]; }
};