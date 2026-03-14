class Solution {
public:
    void solve(int n, string &curr, int k, int &count, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            curr.push_back(ch);
            solve(n, curr, k, count, result);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        solve(n, curr, k, count, result);
        return result;
    }
};
