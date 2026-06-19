class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalti = 0 ;
        int curralti = 0 ;
        for ( int i = 0 ; i < gain.size(); i++){
            curralti += gain[i];
            maxalti = max( maxalti , curralti);
        }
        return maxalti;
        
    }
};