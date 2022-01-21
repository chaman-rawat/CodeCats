// https://leetcode.com/problems/flipping-an-image/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
      int temp, width = image[0].size();
      for(auto &row : image) {
        for(int cell = 0; cell < (width + 1) / 2 ; cell++) {
          temp = row[cell];
          row[cell] = row[width - cell - 1] ? 0 : 1;
          row[width - cell - 1] = temp ? 0 : 1;
        }
      }
      return image;
    }
};