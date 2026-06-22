class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //map insert  coynt freq if matches ++
        vector<int>count( 26 , 0);
        for ( char c : text){
            count [c - 'a']++;
        }
         return min({
            count['b' -'a'],
            count['a' -'a'],
            count['l' -'a']/2,
            count['o' -'a']/2,
            count['n' -'a'],

         });
    }
};