//Mut1-[for->while,rename]|O(n^2)S(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& buf, int aim) {
        int m = (int)buf.size();
        int p = 0;
        while (p <= m - 1) {
            int q = p + 1;
            while (q <= m - 1) {
                long long mix = (long long)buf[p] + buf[q];
                if (mix == aim) return {p, q};
                ++q;
            }
            ++p;
        }
        return {};
    }
};