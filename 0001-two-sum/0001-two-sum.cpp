//Mut1-[hash->sort+2ptr, map->static arrays]|O(nlogn)S(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int goal) {
        int n = (int)a.size();
        static int val[10005], id[10005];
        int i = 0;
        while (i < n) {
            val[i] = a[i];
            id[i] = i;
            ++i;
        }

        int gap = 1;
        while (gap < n) gap <<= 1;

        static int tmpVal[10005], tmpId[10005];
        int len = 1;
        while (len < n) {
            int l = 0;
            while (l < n) {
                int m = l + len;
                int r = m + len;
                if (m > n) m = n;
                if (r > n) r = n;

                int p = l, q = m, k = l;
                while (p < m && q < r) {
                    if (val[p] <= val[q]) {
                        tmpVal[k] = val[p];
                        tmpId[k] = id[p];
                        ++p;
                    } else {
                        tmpVal[k] = val[q];
                        tmpId[k] = id[q];
                        ++q;
                    }
                    ++k;
                }
                while (p < m) {
                    tmpVal[k] = val[p];
                    tmpId[k] = id[p];
                    ++p;
                    ++k;
                }
                while (q < r) {
                    tmpVal[k] = val[q];
                    tmpId[k] = id[q];
                    ++q;
                    ++k;
                }
                l = r;
            }

            int t = 0;
            while (t < n) {
                val[t] = tmpVal[t];
                id[t] = tmpId[t];
                ++t;
            }
            len <<= 1;
        }

        int left = 0, right = n - 1;
        while (left < right) {
            long long cur = (long long)val[left] + val[right];
            if (cur == goal) return {id[left], id[right]};
            if (cur < goal) ++left;
            else --right;
        }
        return {};
    }
};