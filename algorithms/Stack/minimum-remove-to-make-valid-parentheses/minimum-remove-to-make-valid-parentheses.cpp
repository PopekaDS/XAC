class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        
        for(char& sym: s) {
            if(sym >= 'a' && sym <= 'z') {
                continue;
            } else if(sym == '(') {
                ++count;
            } else if(sym == ')') {
                if(count == 0) {
                    sym = '#';
                } else {
                    --count;
                }
            }
        }
        
        count = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                continue;
            } else if(s[i] == ')') {
                ++count;
            } else if(s[i] == '(') {
                if(count == 0) {
                    s[i] ='#';
                } else {
                    --count;
                }
            }
        }
        
        int slow = 0, fast = 0;
        while(fast < s.size()) {
            if(s[fast] != '#') {
                s[slow] = s[fast];
                ++slow;
            }
            
            ++fast;
        }
        
        s.resize(slow);
                
        return s;
    }
};
