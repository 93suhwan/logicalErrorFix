/* Author: Thallium54 {{{
 * Blog: https://blog.tgc-thallium.com/
 * Code library: https://github.com/thallium/acm-algorithm-template
 * }}}*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(x) begin(x),end(x) //{{{
#ifndef LOCAL // https://github.com/p-ranav/pprint
#define de(...)
#define de2(...)
#endif
using ll = long long;
using pii = pair<int, int>; //}}}

template <int MOD>
struct ModInt {
    int val;
    // constructor
    ModInt(ll v = 0) : val(int(v % MOD)) {
        if (val < 0) val += MOD;
    };
    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }
    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(ll n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }
    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = int(ll(val) * x.val % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }
    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};
using mint = ModInt<int(1e9+7)>;
void test_case() {
    int n;
    cin >> n;

    map<char, int> ctoi{{'o', 0}, {'b', 1}, {'y', 2}, {'r', 3}, {'g', 4}, {'w', 5}};
    unordered_map<ll, array<mint, 6>> dp;
    int m;
    cin >> m;
    unordered_map<ll, int> marked;
    for (int i=0; i<m; i++) {
        int u, v;
        string c;
        cin >> u >> c;
        v=ctoi[c[0]];
        marked[u]=v;
        while (u/2>=1 && !marked.count(u/2)) {
            marked[u/2]=-1;
            u/=2;
        }
    }
    de(marked);
    auto dfs=[&](auto& slf, int u) -> array<mint, 6> {
        array<mint, 6> dp;
        fill(all(dp), 1);
        for (auto v : {u*2, u*2+1}) {
            if (marked.count(v)) {
                auto res = slf(slf, v);
                for (int j=0; j<6; j++) {
                    mint sum=0;
                    for (int i=0; i<6; i++) {
                        if (j%3==i%3) continue;
                        sum+=res[i];
                    }
                    dp[j]*=sum;
                }
            }
        }
        if (marked[u]!=-1)
            for (int i=0; i<6; i++) {
                if (i!=marked[u]) dp[i]=0;
            }
        de(u, dp);
        return dp;
    };
    auto res = dfs(dfs, 1);
    de(res);
    ll ver=(1LL<<n)-1;
    cout << accumulate(all(res), mint(0))*mint(4).pow(ver-size(marked)) << endl;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;
    while (tt--) {
        test_case();
    }
}
