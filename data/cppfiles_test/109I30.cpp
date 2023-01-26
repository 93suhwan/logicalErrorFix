#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

// clang-format off
struct M {
    static constexpr int MOD = 998'244'353;
    int v;
    M(int x = 0) {
        if (x < -MOD || x >= MOD) x %= MOD;
        v = (x >= 0) ? x : x + MOD;
    }
    explicit operator int() const { return v; }
    bool operator==(const M &b) const { return v == b.v; }
    M operator-() const { return M(-v); }
    M operator+=(const M &b) { if ((v += b.v) >= MOD) v -= MOD; return *this; }
    M operator-=(const M &b) { if ((v -= b.v) < 0) v += MOD; return *this; }
    M operator*=(const M &b) { v = (ll)v * b.v % MOD; return *this; }
    M operator/=(const M &b) { return *this *= b ^ (MOD - 2); }
    friend M operator^(M a, ll b) {
        M ret = 1;
        for (; b; a *= a, b >>= 1)
            if (b & 1) ret *= a;
        return ret;
    }
    friend M operator+(M a, const M &b) { return a += b; }
    friend M operator-(M a, const M &b) { return a -= b; }
    friend M operator*(M a, const M &b) { return a *= b; }
    friend M operator/(M a, const M &b) { return a /= b; }
};
// clang-format on
using Mod = M;

const Mod P_ROOT = 3;

void fft(int n, vector<Mod> &a, vector<Mod> &rt, bool inv) {
    vector<int> br(n);
    for (int i = 1, r = 0; i < n; i++) {
        for (int bit = n; !(r & bit); bit >>= 1, r ^= bit)
            ;
        if (r > i)
            swap(a[i], a[r]);
    }
    for (int len = 2; len <= n; len <<= 1)
        for (int i = 0; i < n; i += len)
            for (int j = 0; j < len / 2; j++) {
                int pos = n / len * (inv ? len - j : j);
                Mod u = a[i + j], v = a[i + j + len / 2] * rt[pos];
                a[i + j] = u + v, a[i + j + len / 2] = u - v;
            }
    if (inv) {
        Mod minv = Mod(1) / Mod(n);
        for (Mod &x : a)
            x *= minv;
    }
}

vector<Mod> multiply(vector<Mod> a, vector<Mod> b) {
    int len = 2 << __lg(a.size() + b.size());
    Mod root = P_ROOT ^ (Mod::MOD - 1) / len;
    vector<Mod> rt(len + 1, 1);
    for (int i = 0; i < len; i++)
        rt[i + 1] = rt[i] * root;
    a.resize(len, 0), b.resize(len, 0);
    fft(len, a, rt, 0);
    fft(len, b, rt, 0);
    for (int i = 0; i < len; i++)
        a[i] *= b[i];
    fft(len, a, rt, 1);
    while (a.back() == 0)
        a.pop_back();
    return a;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<Mod>> c(n);
    Mod all_BW = 1, all_WB = 1, all_no = 1;
    for (auto &i : c) {
        string s;
        cin >> s;
        i.assign(3, 0);

        Mod tBW = 0, tWB = 0, tno = 0;

        if (s[0] != 'W' && s[1] != 'W') // BB
            i[1] += 1;
        if (s[0] != 'B' && s[1] != 'W') // WB
            i[0] += 1, tWB += 1, tno += 1;
        if (s[0] != 'W' && s[1] != 'B') // BW
            i[2] += 1, tBW += 1, tno += 1;
        if (s[0] != 'B' && s[1] != 'B') // WW
            i[1] += 1;

        all_BW *= tBW, all_WB *= tWB, all_no *= tno;
    }

    while (c.size() != 1) {
        vector<vector<Mod>> d;
        if (c.size() % 2 == 1) {
            d.push_back((c.back()));
            c.pop_back();
        }
        for (int i = 0; i < c.size(); i += 2) {
            d.push_back(multiply(c[i], c[i + 1]));
        }
        c.swap(d);
    }

    cout << (c[0][n] - all_no + all_BW + all_WB).v << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int owo = 1;
    // cin >> owo;
    while (owo--)
        solve();
}
