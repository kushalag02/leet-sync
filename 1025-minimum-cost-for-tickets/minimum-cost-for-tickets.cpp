class Solution {
public:
    int solve(int day, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (day >= days.size()) {
            return 0;
        }

        if (dp[day] != -1) {
            return dp[day];
        }

        int cost1 = costs[0] + solve(day + 1, days, costs, dp);

        int i = day;
        while (i < days.size() && days[i] < days[day] + 7) {
            i++;
        }
        int cost2 = costs[1] + solve(i, days, costs, dp);

        i = day;
        while (i < days.size() && days[i] < days[day] + 30) {
            i++;
        }
        int cost3 = costs[2] + solve(i, days, costs, dp);

        return dp[day] = min({cost1, cost2, cost3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        return solve(0, days, costs, dp);
    }
};
