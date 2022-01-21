// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<pair<int,int>> weak (m);

        for (int i = 0; i < m; i++) {
            weak[i].second = i;
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    weak[i].first++;
        }

        sort(weak.begin(), weak.end());
        vector <int> result (k);

        for (int i = 0; i < k; i++)
            result[i] = weak[i].second;

        return result;
    }
};