#include <bits/stdc++.h>
using namespace std;
const int64_t Mod = 1e9 + 7, Mod1 = 998244353;
#define full(x) x.begin(), x.end()
#define fi first
#define int long long
#define se second
#define dPair(a) {cout << "Pair " << #a << ": " << '\n'; for (int i = 0;i < (int) a.size();i++) cout << i << ": " << a[i].fi << ' ' << a[i].se << '\n';}
#define de2(a) cout << "Array2D: " << #a << '\n'; for (int i = 0;i < (int) a.size();i++) {cout << i << ": "; {for (auto c:a[i]) cout << c << ' ';} cout << '\n';}
#define matrix(a,name) {if (name) cout << "Matrix: " << #a << '\n';for (int i = 0;i < n;i++) {for (int j = 0;j < n;j++) cout << a[i][j]; cout << '\n';}}
#define expose(a) cout << "Array " << #a << ':'; for (auto e:a) cout << e << " "; cout << "\n";
#define dbgE  cout << "EXISTS" << '\n';
#define dbg4(x,y,z,t) cout << #x << ": " << x << "   " << #y << ": " << y << "   " << #z << ": " << z << "   " <<  #t << ": " << t; cout << "\n";
#define dbg3(x,y,z) cout << #x << ": " << x << "   " << #y << ": " << y << "   " << #z << ": " << z; cout << "\n";
#define dbg(x) cout << #x <<": " << x << "\n";
#define dbg2(x,y) cout << #x << ": " << x << "    " << #y << ": " << y << '\n';
#define bit(x,n) {bitset<n> cccc(x); cout << #x << ": " << cccc << '\n';}
const int di[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
template <typename T>
T Power (T n, T k) {
    T x = 1;
    while (k) {
        if (k & 1) x *= n;
        n *= n;
        k >>= 1;
    }
    return x;
}
int compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    int hash = 0;
    int mul = 1;
    for (auto c : s) {
        hash = (hash + (c - 'a' + 1) * mul) % m;
        mul = (mul * p) % m;
    }
    return hash;
}
template <typename T>
long long Power(T n, T k, T M) {
    n %= M;
    T res = 1;
    while (k) {
        if (k & 1) res = res * n % M;
        n = n * n % M;
        k >>= 1;
    }
    return res;
}
signed main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int k;
    cin >> k; 
    int x = (1 << k) - 2; 
    cout << 6 * Power(4ll, x, Mod) % Mod; 
    return 0;
}