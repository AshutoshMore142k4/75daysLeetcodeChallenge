#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int sz = nums.size();
        vector<int> eq_L(sz, -1);
        vector<pair<int, int>> v(sz);
        
        for(int j = 0; j < sz; ++j) {
            v[j] = {nums[j], j};
        }
        
        sort(v.begin(), v.end());
        
        for(int j = 1; j < sz; ++j) {
            if(v[j].first == v[j - 1].first) {
                eq_L[v[j].second] = v[j - 1].second;
            }
        }
        
        vector<int> L(sz, -1);
        int last_pos[31];
        fill(last_pos, last_pos + 31, -1);
        
        for(int j = 0; j < sz; ++j) {
            int mx = eq_L[j];
            int inv = ~nums[j] & 0x3FFFFFFF;
            
            while(inv) {
                int b = __builtin_ctz(inv);
                mx = mx > last_pos[b] ? mx : last_pos[b];
                inv &= inv - 1;
            }
            L[j] = mx;
            
            int val = nums[j];
            while(val) {
                int b = __builtin_ctz(val);
                last_pos[b] = j;
                val &= val - 1;
            }
        }
        
        int next_pos[31];
        fill(next_pos, next_pos + 31, sz);
        long long res = 0;
        
        for(int j = sz - 1; j >= 0; --j) {
            int mn = sz;
            int inv = ~nums[j] & 0x3FFFFFFF;
            
            while(inv) {
                int b = __builtin_ctz(inv);
                mn = mn < next_pos[b] ? mn : next_pos[b];
                inv &= inv - 1;
            }
            
            res += 1LL * (j - L[j]) * (mn - j);
            
            int val = nums[j];
            while(val) {
                int b = __builtin_ctz(val);
                next_pos[b] = j;
                val &= val - 1;
            }
        }
        
        return res;
    }
};