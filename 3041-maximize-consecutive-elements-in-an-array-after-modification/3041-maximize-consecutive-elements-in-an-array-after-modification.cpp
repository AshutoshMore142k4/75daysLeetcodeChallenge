
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(nums.begin() + start,
                            nums.end(), target) - nums.begin();

        if (j < n && nums[j] == target)
            return j;

        return -1;
    }

    int solve(vector<int>& nums, int i, int inc) {

        if (i >= n) return 0;

        if (memo[i][inc] != -1)
            return memo[i][inc];

        int currval = nums[i] + inc;
        int len = 1;

        // Option 1: Increment next selected element
        int j = findMethod(nums, i + 1, currval + 1);

        if (j != -1) {
            len = max(len, 1 + solve(nums, j, 0));
        }

        // Option 2: Select next element without incrementing
        j = findMethod(nums, i + 1, currval);

        if (j != -1) {
            len = max(len, 1 + solve(nums, j, 1));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        memo.assign(n, vector<int>(2, -1));

        int result = 0;

        for (int i = 0; i < n; i++) {
            result = max(result, solve(nums, i, 0));
            result = max(result, solve(nums, i, 1));
        }

        return result;
    }
};
