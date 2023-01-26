#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <chrono>
#include <functional>
#include <numeric>
#include <utility>

#include <array>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

namespace dutinmeow {
    namespace types {
        using int8 = int_fast8_t;
        using int16 = int_fast16_t;
        using int32 = int_fast32_t;
        using int64 =  int_fast64_t;
        using ll = int_fast64_t;

        #define int int32

        using uint8 = uint_fast8_t;
        using uint16 = uint_fast16_t;
        using uint32 = uint_fast32_t;
        using uint64 =  uint_fast64_t;
        using ull = uint_fast64_t;

        using pii = pair<int, int>;
        using piii = pair<int, pii>;
        using pll = pair<ll, ll>;
        using plll = pair<ll, pll>;

        template<class K, class V> 
        using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>; 

        template<class K> 
        using ordered_set = ordered_map<K, null_type>; 
    }

    using namespace types;

    namespace constants {
        const int inf = 2000000011;
        const ll  llinf = 999999999999999989;
        const int MOD = 1e9 + 7;
        const double PI = acos(-1);

        const int di[] = {-1, 0, 1, 0};
        const int dj[] = {0, 1, 0, -1};
    }

    using namespace constants;

    namespace macros {
        #define PB push_back
        #define PF push_front
        #define PPB pop_back
        #define PPF pop_front
        #define EB emplace_back
        #define EF emplace_front
        #define MP make_pair
        #define FF first
        #define SS second
    }

    using namespace macros;

    namespace hash {
        struct chash { 
            const uint64_t C = ll(2e18 * PI) + 71; 
            const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count(); 

            inline ll operator()(ll x) const { return __builtin_bswap64((x ^ RANDOM) * C); }

            inline ll operator()(pll p) const { return (*this)(p.FF) ^ (*this)(p.SS); }
        };

        template<class K, class V> 
        using fast_map = gp_hash_table<K, V, chash>;

        template<class K> 
        using fast_set = fast_map<K, null_type>;
    }

    using namespace hash;

    namespace functions {
        inline void stop() { assert(0); }

        template<typename T>
        inline void sort(T& c) { sort(c.begin(), c.end()); }

        template<typename T, typename S> 
        inline void sort(T& c, S s) { sort(c.begin(), c.end(), s); }

        template<typename T>
        inline void reverse(T& c) { reverse(c.begin(), c.end()); }

        // lambda template: [](const C& a, const C& b) { return a > b; }

        inline ll  ceil0(ll a, ll b) { 
            return a / b + ((a ^ b) > 0 && a % b); 
        } 

        inline ll floor0(ll a, ll b) { 
            return a / b - ((a ^ b) < 0 && a % b); 
        }

        ll pow0(ll a, ll b) { 
            ll res = 1; 
            for (a %= MOD; b; b >>= 1) { 
                if(b & 1) res = res * a % MOD; 
                a = a * a % MOD; 
            } 
            return res; 
        }

        template<typename T>
        string binary(T b) {
            string res = "";
            for (int i = sizeof(T) * 8 - 1; i >= 0; i--)
                res += (b & (1 << i) ? '1' : '0');
            return res;
        }

        template<typename T>
        string binary(T b, int k) {
            string res = "";
            for (int i = k; i >= 0; i--)
                res += ((b & (1 << i)) ? '1' : '0');
            return res;
        }
    }

    using namespace functions;

    namespace input {
        void filein(const string FILENAME) { freopen(FILENAME.c_str(), "r", stdin); }

        inline void read() {}

        template<typename T, typename... U> 
        inline void read(T& F, U&... S) {
            cin >> F;
            read(S...);
        }

        // pair
        template<typename T1, typename T2>
        inline istream& operator>>(istream& is, pair<T1, T2>& p) {
            return is >> p.FF >> p.SS;
        }

        // std::array<T, N>
        template<typename T, size_t sz>
        inline istream& operator>>(istream& is, array<T, sz>& a) {
            for (auto& x : a)
                is >> x;
            return is;
        }

        template<typename T, size_t sz>
        void read(array<T, sz>& a, int n) {
            assert(0 <= n && n < a.size());
            for (int i = 0; i < n; i++)
                cin >> a[i];
        }

        template<typename T, size_t sz>
        void read(array<T, sz>& a, int l, int r) {
            assert(0 <= l && l <= r && r < a.size());
            for (int i = l; i <= r; i++)
                cin >> a[i];
        }

        // std::vector<T>
        template<typename T>
        inline istream& operator>>(istream& is, vector<T>& v) { 
            for (auto& x : v)
                is >> x;
            return is;
        }

        template<typename T> 
        void read(vector<T>& v, int n) {
            assert(0 <= n && n < v.size());
            for (int i = 0; i < n; i++)
                cin >> v[i];
        }

        template<typename T>
        void read(vector<T>& v, int l, int r) {
            assert(0 <= l && l <= r && r < v.size());
            for (int i = l; i <= r; i++)
                cin >> v[i];
        }
    }

    using namespace input;

    namespace output {
        void fileout(const string FILENAME) { freopen(FILENAME.c_str(), "w", stdout); }
        void fileerr(const string FILENAME) { freopen(FILENAME.c_str(), "w", stderr); }

        template<typename T1, typename T2>
        ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
            return os << '(' << p.FF << ", " << p.SS << ')';
        }

        template<typename T>
        ostream& operator<<(ostream& os, const vector<T>& v) {
            os << '[';
            if (v.size()) {
                os << *v.begin();
                for (auto i = ++v.begin(); i != v.end(); i++)
                    os << ", " << (*i);
            }
            return os << ']';
        }

        template<typename T>
        ostream& operator<<(ostream& os, const ordered_set<T>& s) {
            os << '[';
            if (s.size()) {
                os << *s.begin();
                for (auto i = ++s.begin(); i != s.end(); i++)
                    os << ", " << (*i);
            }
            return os << ']';
        }

        template<typename T>
        ostream& operator<<(ostream& os, const fast_set<T>& s) {
            os << '[';
            if (s.size()) {
                os << *s.begin();
                for (auto i = ++s.begin(); i != s.end(); i++)
                    os << ", " << (*i);
            }
            return os << ']';
        }

        template<typename T>
        ostream& operator<<(ostream& os, const multiset<T>& s) {
            os << '[';
            if (s.size()) {
                os << *s.begin();
                for (auto i = ++s.begin(); i != s.end(); i++)
                    os << ", " << (*i);
            }
            return os << ']';
        }

        template<typename T1, typename T2>
        ostream& operator<<(ostream& os, const ordered_map<T1, T2>& s) {
            os << '[';
            if (s.size()) {
                os << '(' << s.begin()->FF << " : " << s.begin()->SS << ')';
                for (auto i = ++s.begin(); i != s.end(); i++)
                    os << ", " << '(' << i->FF << " : " << i->SS << ')';
            }
            return os << ']';
        }

        template<typename T1, typename T2>
        ostream& operator<<(ostream& os, const fast_map<T1, T2>& s) {
            os << '[';
            if (s.size()) {
                os << '(' << s.begin()->FF << " : " << s.begin()->SS << ')';
                for (auto i = ++s.begin(); i != s.end(); i++)
                    os << ", " << '(' << i->FF << " : " << i->SS << ')';
            }
            return os << ']';
        }

        #define fixfloat(d) fixed << setprecision(d)

        void print() {}

        template<typename T, typename... U> 
        void print(T F, U... S) {
            cout << F;
            print(S...);
        }

        void printl() {}

        template<typename T, typename... U> 
        void printl(T F, U... S) {
            cout << F << '\n';
            printl(S...);
        }

        template<typename T>
        void prints(T F) {
            cout << F;
        }

        template<typename T, typename... U> 
        void prints(T F, U... S) {
            cout << F << ' ';
            prints(S...);
        }

        void printc(string c) {}

        template<typename T, typename... U> 
        void printc(const string c, T F, U... S) {
            cout << F << c;
            printc(c, S...);
        }

        void println() { cout << '\n'; }

        template<typename T, typename... U>
        void println(T F, U... S) {
            cout << F << ' ';
            println(S...);
        }

        template<typename T, size_t sz>
        void print(array<T, sz>& a, string s = " ", string e = "\n") {
            for (int i = 0; i < a.size(); i++)
                print(a[i], s);
            print(e);
        }

        template<typename T, size_t sz>
        void print(array<T, sz> a, int n, string s = " ", string e = "\n") {
            assert(0 <= n && n <= a.size());
            for (int i = 0; i < n; i++) 
                print(a[i], s);
            print(e);
        }

        template<typename T, size_t sz>
        void print(array<T, sz> a, int l, int r, string s = " ", string e = "\n") {
            assert(0 <= l && l < r && r < a.size());
            for (int i = l; i <= r; i++) 
                print(a[i], s);
            print(e);
        }

        template<typename T>
        void print(vector<T>& v, string s = " ", string e = "\n") {
            for (int i = 0; i < v.size(); i++)
                print(v[i], s);
            print(e);
        }

        template<typename T>
        void print(vector<T>& v, int n, string s = " ", string e = "\n") {
            assert(0 <= n && n <= v.size());
            for (int i = 0; i < n; i++)
                print(v[i], s);
            print(e);
        }

        template<typename T>
        void print(vector<T>& v, int l, int r, string s = " ", string e = "\n") {
            assert(0 <= l && l <= r && r < v.size());
            for (int i = l; i <= r; i++)
                print(v[i], s);
            print(e);
        }

        template<typename T>
        void print(ordered_set<T>& v, string s = " ", string e = "\n") {
            for (auto x : v) 
                print(x, s);
            print(e);
        }

        template<typename T>
        void print(fast_set<T>& v, string s = " ", string e = "\n") {
            for (auto x : v) 
                print(x, s);
            print(e);
        }
    }

    using namespace output;

    namespace debugs {
        // https://codeforces.com/blog/entry/91347

        #define debug(...) logger(__PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__, __VA_ARGS__)

        template<typename ...Args>
        void logger(string function, int line, string vars, Args&&... values) {
            print(function, " - (line: ", line, "): {", vars, "} = {");
            string delim = "";
            (..., (print(delim, values), delim = ", "));
            printl("}");
        }
    }

    using namespace debugs;
}

using namespace dutinmeow;

//#define USACO 1
//#define FILEIO 1

#if !defined(USACO) 
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif

// code

ll N;

int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += ans % 10;
        ans /= 10;
    }
    return ans;
}

void solve() {  
    read(N);
    cout << N / 10 << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef USACO
    const string ___filename___ = "";
    filein(___filename___ + ".in");
    fileout(___filename___ + ".out");
#endif

#ifdef FILIO
    filein("input.txt");
    fileout("output.txt");
    fileerr("error.txt");
#endif

    int T = 1;
    read(T); 
    for (int t = 1; t <= T; t++) {
        // print("Case #", t, ": ");
        solve();
    }
}