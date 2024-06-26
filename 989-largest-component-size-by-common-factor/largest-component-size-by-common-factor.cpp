class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot) {
            if (rank[aRoot] < rank[bRoot]) {
                parent[aRoot] = bRoot;
            } else if (rank[aRoot] > rank[bRoot]) {
                parent[bRoot] = aRoot;
            } else {
                parent[aRoot] = bRoot;
                rank[bRoot]++;
            }
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        parent.resize(maxNum + 1);
        rank.resize(maxNum + 1, 0);

        for (int i = 0; i <= maxNum; i++) {
            parent[i] = i;
        }

        for (int num : nums) {
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    unionSets(num, i);
                    unionSets(num, num / i);
                }
            }
        }

        // Test Case 2 - 
        // 20 - 2,4
        // 50 - 2, 5
        // 9 - 3
        // 63 - 3,7

        // We will start making the sets 
        // 20(Parent) -> 2 , 4 , 5 , 10 , 20 , 50
        // 9(Parent) -> 3 , 7 , 9 , 63

        // So total 2 sets are formed
        int maxi = 0;
        unordered_map<int, int> mp; // Count the total number of sets formed

        for (auto num : nums) {
            int root = find(num); 
            mp[root]++;
        }

        for (auto i : mp) {
            maxi = max(maxi, i.second);
        }

        return maxi;
    }
};
