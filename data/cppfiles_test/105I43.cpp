#include "bits/stdc++.h"
#include <random>
#include <chrono>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;++i)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;--i)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define endk '\n'
using namespace std; typedef unsigned long long _ulong; typedef long long int lint; typedef long double ld; typedef pair<lint, lint> plint; typedef pair<ld, ld> pld;
struct fast_ios { fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
template<class T> auto add = [](T a, T b) -> T { return a + b; };
template<class T> auto mul = [](T a, T b) -> T { return a * b; };
template<class T> auto f_max = [](T a, T b) -> T { return max(a, b); };
template<class T> auto f_min = [](T a, T b) -> T { return min(a, b); };
template<class T> using V = vector<T>;
using Vl = V<lint>; using VVl = V<Vl>;
template< typename T > ostream& operator<<(ostream& os, const vector< T >& v) {
    for (int i = 0; i < (int)v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}
template< typename T >istream& operator>>(istream& is, vector< T >& v) {
    for (T& in : v) is >> in;
    return is;
}
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}
template <class F> struct rec {
    F f;
    rec(F&& f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
lint gcd(lint a, lint b) { if (b == 0) return a; else return gcd(b, a % b); }
lint digit(lint a) { return (lint)log10(a); }
lint e_dist(plint a, plint b) { return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second); }
lint m_dist(plint a, plint b) { return abs(a.first - b.first) + abs(a.second - b.second); }
bool check_overflow(lint a, lint b, lint limit) { if (b == 0) return false; return a > limit / b; } // a * b > c => true
void Worshall_Floyd(VVl& g) { REP(k, SZ(g)) REP(i, SZ(g)) REP(j, SZ(g)) chmin(g[i][j], g[i][k] + g[k][j]); }
const lint MOD1000000007 = 1000000007, MOD998244353 = 998244353, INF = 2e9;
lint dx[8] = { 0, -1, 0, 1, 1, -1, 1, -1 }, dy[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
bool YN(bool flag) { cout << (flag ? "YES" : "NO") << endk; return flag; } bool yn(bool flag) { cout << (flag ? "Yes" : "No") << endk; return flag; }
struct Edge {
    lint from, to;
    lint cost;
    Edge() {

    }
    Edge(lint u, lint v, lint c) {
        cost = c;
        from = u;
        to = v;
    }
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};
struct WeightedEdge {
    lint to;
    lint cost;
    WeightedEdge(lint v, lint c = 1) {
        to = v;
        cost = c;
    }
    bool operator<(const WeightedEdge& e) const {
        return cost < e.cost;
    }
};
using WeightedGraph = V<V<WeightedEdge>>;
typedef pair<plint, lint> tlint;
typedef pair<tlint, plint> qlint;
typedef pair<string, lint> valstr;
typedef pair<Vl, lint> valv;

int main() {
    lint T;
    cin >> T;
    while (T--) {
        lint N;
        cin >> N;
        map<lint, V<tlint>> vals;
        V<tlint> arr;
        REP(i, N) {
            lint A, B, C;
            cin >> A >> B >> C;
            vals[A + B - C].push_back({ { A - max(0ll, C - B), max(0ll, A - C)}, i });
            arr.push_back({ { A, B }, C });
        }
        V<plint> ans(N);
        lint cnt = 0;
        for (auto p : vals) {
            auto _v = p.second;
            sort(ALL(_v));
            V<tlint> tmp;
            lint idx = 0;
            while (idx < SZ(_v)) {
                lint r = _v[idx].first.first, prv = idx;
                cnt++;
                while (idx < SZ(_v) && _v[idx].first.second <= r) {
                    idx++;
                }
                FOR(k, prv, idx) {
                    lint i = _v[k].second;
                    ans[i].second = arr[i].first.first - r;
                    ans[i].first = arr[i].second - ans[i].second;
                }
                idx++;
            }
        }
        cout << cnt << endk;
        REP(i, N) {
            cout << ans[i].first << " " << ans[i].second << endk;
        }
    }
}