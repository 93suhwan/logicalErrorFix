#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 5;
int d[N + 1];
std::vector<int> p[N + 1];
std::vector<std::pair<int, int>> v[N];
struct Tree {
    int n;
    std::vector<int> t, upd;
    Tree(int n) : n(n), t(2 * n, -1E9) {}
    void update(int p, int x) {
        upd.push_back(p);
        p += n;
        t[p] = std::max(t[p], x);
        for (; p > 1; p >>= 1) {
            t[p >> 1] = std::max(t[p], t[p ^ 1]);
        }
    }
    void place(int p) {
        p += n;
        t[p] = -1E9;
        for (; p > 1; p >>= 1) {
            t[p >> 1] = std::max(t[p], t[p ^ 1]);
        }
    }
    void ch() {
        for (auto x : upd) {
            place(x);
        }
        upd.clear();
    }
    int get(int l, int r) {
        int res = -1E9;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = std::max(res, t[l++]);
            if (r & 1) res = std::max(res, t[--r]);
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 2; i <= N; i++) {
        if (d[i] == 0) {
            for (int j = i; j <= N; j += i) {
                d[j] = i;
            }
        }
    }
    
    int n;
    std::cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int x = a[i];
        while (d[x]) {
            p[d[x]].push_back(i);
            x /= d[x];
        }
    }
    
    std::string b;
    std::cin >> b;
    
    Tree t(N);
    
    for (int i = 2; i <= N; i++) {
        if (p[i].empty()) {
            continue;
        }
        int m = p[i].size();
        int pre[m + 1] {};
        for (int j = 0; j < m; j++) {
            pre[j + 1] = pre[j];
            if (b[p[i][j]] == '*') pre[j + 1]++;
            else pre[j + 1]--;
        }
        
        for (int j = 0; j < m; j++) {
            if (pre[j + 1] < 0) {
                v[0].emplace_back(1, p[i][j]);
                v[p[i][j] + 1].emplace_back(0, p[i][j]);
            } else {
                int x = t.get(pre[j + 1] + 1, N);
                if (x >= 0) {
                    v[x].emplace_back(1, p[i][j]);
                    v[p[i][j]].emplace_back(0, p[i][j]);
                }
                t.update(pre[j + 1], p[i][j]);
            }
        }
        t.ch();
    }
    
    std::multiset<int> s{n};
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto [typ, x] : v[i]) {
            if (typ == 0) {
                s.erase(s.find(x));
            } else {
                s.insert(x);
            }
        }
        if (!(b[i] == '/' && a[i] > 1))
            ans += *s.begin() - i;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
