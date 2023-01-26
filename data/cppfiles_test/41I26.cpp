#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;

        vector ans(n, vector<int>(n));

        int c = 0, p = 1;

        while (p < n) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (i / p % k != j / p % k) {
                        ans[i][j] = c;
                    }
                }
            }
            c++;
            p *= k;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << ans[i][j] + 1 << " \n"[i == n - 2 && j == n - 1];
        }
        }
    };
    
    solve();
    
    return 0;
}
