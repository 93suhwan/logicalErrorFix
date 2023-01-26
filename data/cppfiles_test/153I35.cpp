#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mx = 26;
const int mod = 998244353;
const int mx_step = (1 << 23);

int getbit(int mask, int i) {
    return (mask >> i) & 1;
}

int dp[mx_step][2];
int mn_id[mx_step];

int gethigherbit(int mask) {
    int l = __lg(mask);
    return l;
}

signed main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
#ifdef foo
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        a[i].resize(mx);
        for (int j = 0; j < s[i].size(); ++j) {
            a[i][s[i][j] - 'a']++;
        }
    }
    int o = (1 << n);
    for (int l = 1; l < o; ++l) {
        dp[l][1] = 1;
    }
    vector<pair<int, int>> sorted_ids[26];
    for (int i1 = 0; i1 < 26; ++i1) {
        for (int j = 0; j < n; ++j) {
            sorted_ids[i1].push_back({a[j][i1], j});
        }
        sort(sorted_ids[i1].begin(), sorted_ids[i1].end());

    }
    for (int i = mx - 1; i >= 0; --i) {
        mn_id[0] = -1;
        for (int mask = 1; mask < o; ++mask) {
            int b = gethigherbit(mask);
            mn_id[mask] = mn_id[mask ^ (1 << b)];
            if (mn_id[mask] == -1 || a[mn_id[mask]][i] > a[b][i]) {
                mn_id[mask] = b;
            }
        }
        for (int mask = 1; mask < o; ++mask) {
            int b = mn_id[mask];
            int nmask = mask ^(1 << b);
            int b1 = mn_id[nmask];
            if (b1 == -1) {
                dp[mask][0] += dp[mask][1] * (a[b][i] + 1);
                continue;
            }
            int val = dp[nmask][0] - dp[nmask][1] * (a[b][i] + 1) + dp[mask][1] * (a[b][i] + 1);
            dp[mask][0] += val;
            dp[mask][0] %= mod;
//            for (int k = 0; k < n; ++k) {
//                int id = sorted_ids[i][k].second;
//                int val = sorted_ids[i][k].first;
//                if (getbit(mask, id) == 0)continue;
//                dp[mask][0] += dp[msk][1] * (val - last);
//                dp[mask][0] %= mod;
//                msk ^= (1ll << id);
//                last = val;
//            }
        }
        for (int j = 0; j < o; ++j) {
            dp[j][1] = dp[j][0];
            dp[j][0] = 0;
        }
    }
    int ans = 0;
    for (int m = 0; m < o; ++m) {
        int k = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (getbit(m, i) == 1) {
                k++;
                sum += i + 1;
            }
        }
        ans ^= dp[m][1] * k * sum;
    }
    cout << ans;
}