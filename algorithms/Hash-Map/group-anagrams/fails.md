class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> ht;
        for(auto now: strs) {
            vector<int> sym(26, 0);
            for(char c: now) {
                int position = c - 'a';
                ++sym[position];
            }
            string key = "";
            for(auto n: sym) {
                key += to_string(n); // <-- Попался в ловушку этом месте :)
            }
            
            ht[key].push_back(now);
        }
        
        vector<vector<string>> result;
        for(auto vs: ht) {
            result.push_back(vs.second);
        }
        
        return result;
    }
};