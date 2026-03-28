//Mut4-[cycle-math,direct-write]|O(n)S(n)
class Solution {
public:
    string convert(string src_txt, int row_cap) {
        int n_all = (int)src_txt.size();
        if (row_cap <= 1 || row_cap >= n_all) return src_txt;

        string out_txt(n_all, ' ');
        int put_at = 0;
        int cyc = (row_cap << 1) - 2;

        int r_id = 0;
        while (r_id <= row_cap - 1) {
            int j = r_id;
            while (j <= n_all - 1) {
                out_txt[put_at] = src_txt[j];
                ++put_at;

                int mid = j + cyc - (r_id << 1);
                if (r_id > 0 && r_id < row_cap - 1 && mid <= n_all - 1) {
                    out_txt[put_at] = src_txt[mid];
                    ++put_at;
                }
                j += cyc;
            }
            ++r_id;
        }
        return out_txt;
    }
};