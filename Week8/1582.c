// https://leetcode.com/problems/special-positions-in-a-binary-matrix/
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int total = 0;

        vector<int> row(m);
        vector<int> col(n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }

        for (int i = 0; i < m; i++)
            if (row[i] == 1)
                for (int j = 0; j < n; j++)
                    if (mat[i][j] == 1 && col[j] == 1)
                        total++;
        return total;
    }
};