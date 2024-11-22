    #include <unordered_map>

    class Solution {
    public:

        vector<int> topKFrequent(vector<int>& nums, int k) {
    
            unordered_map<int, int> ht;

            for(const auto &iht: nums)  {
                ++ht[iht];
            }
        
            vector<vector<int>> v(nums.size());  // <-- Создал вектор неправильного размера
        
            for(auto now: ht) {
                v[now.second].push_back(now.first);
            }
        
            vector<int> result;
            for(int i = nums.size(); i >= 0 && result.size() != k; --i) {
                if(!v[i].empty()) {
                    for(auto now: v[i]) {
                        result.push_back(now);
                    }
                }
            }
        
            return result;
        }
    };
