class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<vector<int>> stack;
        stack.push({temperatures[0], 0});
        
        for(int i = 1; i < temperatures.size(); ) {
            if(stack.empty()) {
                stack.push({temperatures[i], i});
                ++i;
                continue;
            }
            
            vector<int> v = stack.top();
            
            if(v[0] < temperatures[i]) {
                result[v[1]] = i - v[1];
                stack.pop();
                
            } else {
                stack.push({temperatures[i], i});
                ++i;
            }
        }
        
        return result;
    }
};