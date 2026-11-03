class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxnum = INT_MIN;
        int sum = 0;
        for( int num : nums){
            sum += num ;
            maxnum = max( num , maxnum );

        }
        return nums.size() * maxnum - sum;
        
    }
};