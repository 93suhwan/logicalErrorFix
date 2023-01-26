#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    auto work = [&](auto p) {
        std::vector<int> g(n);
        for (int i = 0, j = 1E9; i < n; i++) {
            if (p[i] < j) {
                j = p[i];
                g[i]++;
            }
        }
        
        std::vector<int> q, Q;
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && p[i] < p[q.back()]) {
                cnt -= (--g[q.back()] == 0);
                q.pop_back();
            }
            while (!Q.empty() && p[i] > p[Q.back()]) {
                cnt -= (--g[Q.back()] == 0);
                Q.pop_back();
            }
            q.push_back(i);
            Q.push_back(i);
            g[i] += 2;
            cnt++;
            if (cnt == i + 1) {
                assert(ans == i - 1);
                ans = i;
            }
        }
        return ans;
    };
    
    auto f = work(p), g = work(std::vector(p.rbegin(), p.rend()));
    
    if (f + g < n - 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::vector<bool> neg(n);
        for (int i = 0, j = 1E9; i < f; i++) {
            if (p[i] < j) {
                j = p[i];
                neg[i] = true;
            }
        }
        for (int i = f + 1, j = p[f]; i < n; i++) {
            if (p[i] < j) {
                j = p[i];
                neg[i] = true;
            }
        }
        for (int i = f - 1, j = p[f]; i >= 0; i--) {
            if (p[i] > j) {
                j = p[i];
                neg[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (neg[i]) {
                p[i] = -p[i];
            }
            std::cout << p[i] << " \n"[i == n - 1];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
