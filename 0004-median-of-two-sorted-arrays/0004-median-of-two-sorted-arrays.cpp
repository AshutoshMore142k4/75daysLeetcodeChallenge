// Mut1 — [BinarySearch, Partition | Forward lo/hi] | O(log min(m,n)) S(O(1))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        ios::sync_with_stdio(0); cin.tie(0);
        if (a.size() > b.size()) swap(a, b);
        int m = a.size(), n = b.size();
        int lo = 0, hi = m, half = (m + n + 1) / 2;
        while (lo <= hi) {
            int c1 = (lo + hi) >> 1;
            int c2 = half - c1;
            int l1 = (c1 == 0) ? INT_MIN : a[c1-1];
            int r1 = (c1 == m) ? INT_MAX : a[c1];
            int l2 = (c2 == 0) ? INT_MIN : b[c2-1];
            int r2 = (c2 == n) ? INT_MAX : b[c2];
            if (l1 <= r2 && l2 <= r1) {
                int lmax = max(l1, l2);
                int rmin = min(r1, r2);
                return (m + n) & 1 ? lmax : (lmax + rmin) / 2.0;
            }
            l1 > r2 ? hi = c1 - 1 : lo = c1 + 1;
        }
        return 0.0;
    }
};