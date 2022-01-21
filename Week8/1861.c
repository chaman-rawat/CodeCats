// https://leetcode.com/problems/rotating-the-box/
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> rotatedBox(n, vector<char>(m));

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                rotatedBox[i][j] = box[m - 1 - j][i];

        // Apply gravity
        for (int j = 0; j < m; j++)
        {
            for (int i = n - 2, k = n - 1; i >= 0; i--)
            {
                // If no empty space found
                if (rotatedBox[k][j] != '.')
                {
                    k--;
                    continue;
                }

                // Stone found
                if (rotatedBox[i][j] == '#')
                {
                    swap(rotatedBox[i][j], rotatedBox[k][j]);
                    k--;
                    continue;
                }

                // Obstacle found
                if (rotatedBox[i][j] == '*')
                {
                    k = i - 1;
                    i--;
                }
            }
        }

        return rotatedBox;
    }
};