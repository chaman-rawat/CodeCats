// https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int wealth, maximum = 0;
      for(auto i: accounts) {
        wealth = 0;
        for(auto j: i)
          wealth += j;
        maximum = max(maximum,wealth);
      }
      return maximum;
    }
};