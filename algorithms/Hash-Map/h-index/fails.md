class Solution {
public:
    int hIndex(vector<int>& citations) {
        int array_size = citations.size();
        vector<int> freq(array_size + 1, 0);
        
        for(int cit: citations) {
            freq[min(cit ,array_size)]++;
        }
        
        int H = 0;
        for(int i = array_size; i >= 0; i--) {  
            H += freq[i];

            if(H >= i) {
                return H; // <- Надо индекс возвращать
            }
        }
        
        return H;
    }
};