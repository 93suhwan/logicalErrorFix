#ifndef TIAGOSHIBATA_DEBUG
#pragma GCC optimize ("Ofast,no-stack-protector")
#define watch(...)
#define NDEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <x86intrin.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long unsigned llu;
typedef long long ll;
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
template<class T>
T maxn(T a, T b) {
    return max(a, b);
}
template<class T, class... U>
T maxn(T x , U... z) {
    return max(x, maxn(z...));
}
template<class T>
T minn(T a, T b) {
    return min(a, b);
}
template<class T, class... U>
T minn(T x , U... z) {
    return min(x, minn(z...));
}
#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)
#define ANONYMOUS_VAR CONCAT(anonymous_, __LINE__)
#define REP(i,a,b) for(decltype(b) i=a; i<b; i++)
#define REP0(i,b) for(decltype(b) i=0; i<b; i++)
#define REPN(b) for(decltype(b) ANONYMOUS_VAR=0; ANONYMOUS_VAR<b; ANONYMOUS_VAR++)
#define all(x) begin(x), end(x)
template <class ...Args> auto &read(Args& ...args) { return (cin >> ... >> args); }
template <typename T1, typename T2> auto &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <class T> auto &operator>>(istream &is, vector<T> &v) {
    for (auto &x : v)
        is >> x;
    return is;
}
#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
#define READN(var, ...)  var(__VA_ARGS__); cin >> var
template <class T> auto &operator<<(ostream &os, const vector<T> &v) {
    if (v.size()) {
        os << v[0];
        REP(i, 1, v.size())
            os << ' ' << v[i];
    }
    return os;
}
template <typename T1, typename T2> auto &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}

#ifdef TIAGOSHIBATA_DEBUG
template<typename T> void _watch(string name, T arg) {
  cerr << name << " is " << arg << '\n';
}
template<typename T1, typename... T2> void _watch(string names, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " is " << arg << " | ";
  _watch(names.substr(names.find(',') + 2), args...);
}
#define watch(...) _watch(#__VA_ARGS__, __VA_ARGS__)
#endif

static const uint64_t FIXED_RANDOM = 0x4367bea9436f550fllu ^ __rdtsc();
static constexpr uint64_t _splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
struct splitmix64 {
    uint64_t operator()(uint64_t x) const {
        return _splitmix64(FIXED_RANDOM ^ x);
    }
};
struct splitmix {
    template<typename T>
    constexpr uint64_t operator()(const T& structure) const {
        uint64_t ans{};
        constexpr auto padding = (sizeof(structure) & 7);
        if constexpr (bool(padding)) {
            for (size_t i = 0; i < padding; ++i) {
                ans |= *(reinterpret_cast<const uint8_t*>(&structure + 1) - padding + i) << i;
            }
            ans = _splitmix64(ans);
        }
        auto raw_data = reinterpret_cast<const uint64_t*>(&structure);
        for (size_t i = 0; 8 * i + 7 < sizeof(structure); ++i) {
            ans = _splitmix64(ans ^ raw_data[i]);
        }
        watch(ans);
        return ans;
    }
};
// gp_hash_table<key, type or null_type, splitmix64> safe_hash_table;
// typedef tree<int, type of null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set or ordered_map;  // find_by_order, order_of_key
const llu MOD = 1000000007;

namespace {
llu power(llu b, llu k) {
    llu ans = 1, base = b;
    while (k) {
        if (k & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        k >>= 1;
    }
    return ans;
}

llu inverse(llu n) {
    return power(n, MOD - 2);
}

llu divide(llu a, llu b) {
    return (a * inverse(b)) % MOD;
}

#define MAX 200011
llu fact[MAX], inv_fact[MAX];
llu c(llu a, llu b) {
    if (b > a)
        return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

llu solve(llu n, llu k) {
    llu ans = 1;
    llu comb{};
    for (llu i = 0; i < n; i += 2) {
       comb = (comb + c(n, i)) % MOD;
    }
    watch(comb);
    if (!(n & 1)) {
        // All one is good
        REP0(i, k) {
            ans = (power(2, i) + (comb * ans) % MOD) % MOD;
        }

        return ans;
    }

    REP0(i, k) {
        ans = ((comb + 1) * ans) % MOD;
    }
    return ans;
}

auto solve() {
    llu READ(n, k);
    return solve(n, k);
}
}

int main() {
#ifndef TIAGOSHIBATA_DEBUG
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#else
    cin.exceptions(ifstream::eofbit | ifstream::badbit);
#endif
    fact[0] = 1;
    inv_fact[0] = 1;
    REP(i, 1, MAX) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = divide(1, fact[i]);
    }
    int READ(t);
    REP(test_case, 0, t) {
        cout << solve() << '\n';
    }
    return 0;
}
