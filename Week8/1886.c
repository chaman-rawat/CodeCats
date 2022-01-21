// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
class Solution
{
public:
    int n;
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        n = mat.size();
        for (int i = 0; i < 4; i++)
        {
            if (areEqual(mat, target))
                return true;
            rotate(mat);
        }
        return false;
    }

    bool areEqual(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[i][j])
                    return false;
        return true;
    }

    void rotate(vector<vector<int>> &mat)
    {
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    break;
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[i][n - j - 1];
                mat[i][n - j - 1] = temp;
            }
    }
};