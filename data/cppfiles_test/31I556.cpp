#include <bits/stdc++.h>
using namespace std;
using ll  =  long long;
using ld  =  long double;
const ll   MOD        =  1e+9 + 7;

void MAIN() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    ll lcm;
    vector<int> b(n);
    for (int i = 0; i < n - 3; i += 2) {
        lcm = abs(v[i]) * abs(v[i + 1]) / __gcd(abs(v[i]), abs(v[i + 1]));
        b[i] = (lcm / abs(v[i])) * (v[i] < 0 ? -1 : 1);
        b[i + 1] = (lcm / abs(v[i + 1])) * (v[i + 1] < 0 ? 1 : -1);
    }
    if (n % 2) {
        lcm = abs(v[n - 1]) * abs(v[n - 2]) / __gcd(abs(v[n - 1]), abs(v[n - 2]));
        lcm = abs(v[n - 3]) * lcm / __gcd(lcm, abs(v[n - 3]));
        b[n - 3] = (lcm / abs(v[n - 3])) * (v[n - 3] < 0 ? -1 : 1);
        b[n - 2] = (lcm / abs(v[n - 2])) * (v[n - 2] < 0 ? -1 : 1);
        b[n - 1] = 2 * (lcm / abs(v[n - 1])) * (v[n - 1] < 0 ? 1 : -1);
    }
    else {
        int i = n - 2;
        lcm = abs(v[i]) * abs(v[i + 1]) / __gcd(abs(v[i]), abs(v[i + 1]));
        b[i] = (lcm / abs(v[i])) * (v[i] < 0 ? -1 : 1);
        b[i + 1] = (lcm / abs(v[i + 1])) * (v[i + 1] < 0 ? 1 : -1);
    }

    for (int i : b) {
        cout << i << ' ';
    }

    cout << '\n';
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed; cout << setprecision(10);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) MAIN();
}