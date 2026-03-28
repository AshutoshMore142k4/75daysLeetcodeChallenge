// Mut1-FIXED — verified on [10,6,4,2] → 6
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);
        int n = nums.size();
        long long ans = 0;
        // segs[i] = {or_val, leftmost_L}  ordered: segs[0] newest (largest OR, smallest L)
        // Actually: segs[0] = {nums[r], r}, segs.back() = full OR, L=0
        vector<pair<int,int>> segs;
        unordered_map<int,int> last;

        for (int r = 0; r < n; r++) {
            last[nums[r]] = r;

            // Build: start fresh with just nums[r]
            vector<pair<int,int>> ns;
            ns.push_back({nums[r], r});
            for (auto& [v, l] : segs) {          // segs[0] has smallest L (oldest)
                int nv = v | nums[r];
                if (nv != ns.back().first) {
                    ns.push_back({nv, l});         // new distinct OR level
                } else {
                    ns.back().second = l;          // extend leftward, same OR
                }
            }
            segs = move(ns);
            // segs[0] = {nums[r], r}, segs.back() = {full_or, 0-side}

            // Count: right boundaries
            int hi = r;
            for (auto& [v, lo] : segs) {
                // This group covers l ∈ [lo, hi]
                auto it = last.find(v);
                if (it != last.end() && it->second >= lo) {
                    ans += min(it->second, hi) - lo + 1;
                }
                hi = lo - 1;                      // next group's right boundary
            }
        }
        return ans;
    }
};