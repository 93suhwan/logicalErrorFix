#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int maxn = 1e6+1;

vector<int> g[maxn];
long long cnt[maxn], f2[maxn];
long long k, flag, gc;

long long dfs(int x, int fa) {
    long long res = 0;
    for(auto to: g[x]) {
        if (to == fa || !flag) continue;
        res += dfs(to, x);
    }
    if (res % k == 0) {
        gc = __gcd(gc, res);
        return 1ll;
    }
    else if (x != 1 && (res + 1) % k == 0) {
        gc = __gcd(gc, res+1ll);
        return 0ll;
    }
    flag = false;
    return 0ll;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f2[0] = 1;
    for(int i = 1; i < maxn; ++ i) {
        f2[i] = f2[i-1] * 2 % mod;
    }
    int T = 1;
    cin >> T;
    while(T --) {
        int n;
        cin >> n;
        for(int i = 1; i < n; ++ i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int m = n - 1;
        cnt[1] = f2[m];
        for(int i = 2; i <= m; ++ i) {
            if (m % i) continue;
            if (1ll * i * i > m) i = m;
            k = i;
            flag = true;
            gc = 0;
            dfs(1, 1);
            if (flag && gc == k) {
                cnt[i] = 1;
                cnt[1] = (mod + (cnt[1] - 1) % mod) % mod;
            }
        }
        for(int i = 1; i <= n; ++ i) {
            cout << cnt[i] << " \n"[i==n];
            cnt[i] = 0;
            g[i].clear();
        }
    }
    return 0;
}
