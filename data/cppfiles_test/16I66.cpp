/**
 * @Auther: Jayce.
 * @Date: 2021/09/28/22:41
 * @Title：
 * @Description：
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

inline int read() {
    char ch = getchar();
    int f = 1, x = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f * x;
}
struct node {
    int val, index;
    bool operator < (node & another) {
        return val < another.val;
    }
}nums[maxn];
void solve() {
    int a, n = read();
    priority_queue<node> q;
    rep_(i, 1, n) {
        a = read();
        nums[i] = {a, i};
    }
    sort(nums + 1, nums + n + 1);
    int l = 1, r = n, cur = nums[n].val;
    vector<pair<int, int> > ans;
    while (l < n) {
        while (l < n && nums[l].val == 0) l++;
        if (nums[r].val == cur) {
            ;
        } else if (l < r - 1 && nums[r - 1].val == cur) {
            r--;
        } else {
            r = n;
            cur--;
        }
        if (l < r) {
            nums[r].val--;
            nums[l].val--;
            ans.push_back({nums[l].index, nums[r].index});
        }
    }
    cout << ans.size() << endl;
    for (auto item : ans)
        cout << item.first << ' ' << item.second << endl;
}
int main() {
#define OJ
#ifndef OJ
    freopen("E:\\ProgramData\\CppProjects\\ACM\\input.txt", "r", stdin);
#endif
    int t = read();
    while (t--) solve();
    return 0;
}
/*
2 5 1 4 3
2 1 4 3 5
2 1 3 4 5
1 2 4 3 5
 */