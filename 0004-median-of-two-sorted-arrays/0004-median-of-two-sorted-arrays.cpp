// Mut2 — [BinarySearch, Partition | Reverse search direction, renamed] | O(log min(m,n)) S(O(1))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& p, vector<int>& q) {
        ios::sync_with_stdio(0); cin.tie(0);
        if (p.size() > q.size()) swap(p, q);
        int sz1 = p.size(), sz2 = q.size();
        int bot = 0, top = sz1, mid = (sz1 + sz2 + 1) >> 1;
        while (bot <= top) {
            int s1 = bot + ((top - bot) >> 1);
            int s2 = mid - s1;
            int lp = s1 ? p[s1-1] : INT_MIN;
            int rp = s1 < sz1 ? p[s1] : INT_MAX;
            int lq = s2 ? q[s2-1] : INT_MIN;
            int rq = s2 < sz2 ? q[s2] : INT_MAX;
            if (lp <= rq && lq <= rp) {
                int mx = max(lp, lq), mn = min(rp, rq);
                return (sz1 + sz2) & 1 ? (double)mx : (mx + mn) / 2.0;
            }
            (lp > rq) ? (top = s1 - 1) : (bot = s1 + 1);
        }
        return 0.0;
    }
};