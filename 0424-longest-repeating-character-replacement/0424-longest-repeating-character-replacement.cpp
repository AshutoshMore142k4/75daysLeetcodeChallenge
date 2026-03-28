class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0 , maxlen = 0 ;

        int mf = 0 ;

        vector<int>freq( 26 , 0 );

        for ( int r = 0 ; r < n ; r++){
             freq[s[r] - 'A']++; //converingt into num for storing the index of corresponding alsphabet

             mf = max(mf , freq[ s[r] - 'A']);

             while ( r -l + 1 -mf > k){
                freq[s[l] - 'A']--;
                l++;

             }
             maxlen = max( maxlen , r- l + 1);

        }

        return maxlen;

        
    }
};