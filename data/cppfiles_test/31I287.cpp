#include <bits/stdc++.h>
using namespace std;

vector<int> Get(int a, int b, int c) {
    int g = __gcd(abs(a), abs(b));
    for (int i = -10000; i <= 10000; ++i) {
        int r = -(a * i + c * g) / b;
        if (a * i + r * b + c * g == 0 && -10000 <= r && r <= 10000) {
            return {i, r, g};
        }
    }
    exit(1);
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            cout << -a[i + 1] << ' ' << a[i] << ' ';
        }
        cout << '\n';
        return;
    } else {
        for (int i = 0; i < n - 3; i += 2) {
            cout << -a[i + 1] << ' ' << a[i] << ' ';
        }
        auto ans = Get(a[n - 3], a[n - 2], a[n - 1]);
        for (int i = 0; i < 3; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
