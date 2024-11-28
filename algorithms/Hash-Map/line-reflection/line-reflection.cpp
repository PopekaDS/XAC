/*
356. Line Reflection

Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.
In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points' set is the same as the reflected ones.
Note that there can be repeated points.

Example 1:
Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Example 2:
Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.
 
Constraints:

* n == points.length
* 1 <= n <= 10^4
* -10^8 <= points[i][j] <= 10^8
 
Follow up: Could you do better than O(n2)?
*/

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int _min = points[0][0];
        int _max = points[0][0];
        
        for(auto elem: points) {
            _min = min(elem[0], _min);
            _max = max(elem[0], _max);
        }
        
        unordered_map<int, int> grid;
        for(auto dot: points) {
            grid[dot[0]] = dot[1];
        }

        for(auto dot: grid) {
            int x = _max + _min - dot.first;
            if(grid.find(x) == grid.end()) {
                return false;
            }
            
            if(dot.second != grid[x]) {
                return false;
            }
        }
        
        return true;
    }
};

// Время: O(n)
// Память: O(n)