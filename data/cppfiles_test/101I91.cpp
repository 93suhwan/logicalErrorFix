#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);
#define un unsigned int
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pk pop_back
#define pf push_front
#define pt pop_front
ll sum(ll a, ll b, ll n) {
    if (n == 0)
        return 0;
    if ((a + b) % 2 == 0)
        return (a + b) / 2 * n;
    else
        return n / 2 * (a + b);
}
void solve() {
    int n;
    cin >> n;
    vector < int > v[2];
    int a[n + 10], us[n + 10] = {};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 0 - B
    // 1 - R
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if (a[i] >= 1 && a[i] <= n && us[a[i]] == 0) {
            us[a[i]] = 1;
//            cout << "Welcome\n";
            continue;
        }
        if (c == 'B')
            v[0].pb(a[i]);
        else
            v[1].pb(a[i]);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    int r = 0, l = v[0].size() - 1;
    for (int i = n; i >= 1; --i) {
        if (us[i] == 1)
            continue;
        while (r < v[1].size() && v[1][r] > i)
            ++r;
//        cout << i << ' ' << r << '\n';
        if (r == v[1].size()) {
            while (l >= 0 && v[0][l] < i)
                --l;
            if (l == -1) {
                cout << "NO\n";
                return;
            }
            --l;
        }
        else
            ++r;
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//    fin("input.txt")
//    fout("output.txt")
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


