#include <iostream>

const int MOD = 1000000007;

using namespace std;
using ll = long long;

ll pow(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    ll prev = pow(b, e / 2);
    return (((prev * prev) % MOD) * ((e % 2 == 1) ? (b) : (1))) % MOD;
}

ll solve(int n, int k, const ll& win, const ll& tie) {
    if (k == 0) return 1;
    // win
    ll w = (win * pow(pow(2, n), k - 1)) % MOD;
    // win later
    ll wl = (tie * solve(n, k - 1, win, tie)) % MOD;
    return (w + wl) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    ll kk = pow(2, n - 1);
    ll win, tie;
    if (n % 2 == 0) {
        win = 1;
        tie = kk - 1;
    } else if (n % 2 == 1) {
        win = 0;
        tie = kk + 1;
    }
    ll r = solve(n, k, win, tie);
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}