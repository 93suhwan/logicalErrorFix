#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define inf LONG_LONG_MAX
#define ninf LONG_LONG_MIN
#define int long long int

const int maxn = 1e5 + 5;
const int modn = 1e9 + 7;
const double pi = acos(-1);

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n - 3; i += 2) {
        int l = lcm(abs(a[i + 1]), abs(a[i]));
        b[i] = (l / abs(a[i])) * (a[i] < 0 ? -1 : 1);
        b[i + 1] = (l / abs(a[i + 1])) * (a[i + 1] < 0 ? 1 : -1);
    }

    if (n % 2 == 0) {
        int l = lcm(abs(a[n - 2]), abs(a[n - 1]));
        b[n - 2] = (l / abs(a[n - 2])) * (a[n - 2] < 0 ? -1 : 1);
        b[n - 1] = (l / abs(a[n - 1])) * (a[n - 1] < 0 ? 1 : -1);
    } else {
        int l = lcm(abs(a[n - 3]), lcm(abs(a[n - 2]), abs(a[n - 1])));
        b[n - 3] = (l / abs(a[n - 3])) * (a[n - 3] < 0 ? -1 : 1);
        b[n - 2] = (l / abs(a[n - 2])) * (a[n - 2] < 0 ? -1 : 1);
        b[n - 1] = (l / abs(a[n - 1])) * (a[n - 1] < 0 ? 1 : -1);
        b[n - 1] *= 2;
    }

    for (int i : b) {
        cout << i << ' ';
    }

    cout << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    // compute();
    for (int i = 1; i <= test_case; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}