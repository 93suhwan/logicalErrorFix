/*
    author:  Maksim1744
    created: 25.07.2021 18:30:43
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> sw;
    for (int i = 0; i < k; ++i) {
        int ln;
        cin >> ln;
        vector<int> p(ln);
        cin >> p;
        --p;
        for (int i = 0; i < ln; ++i) {
            for (int j = 0; j + 1 < ln; ++j) {
                sw.eb(p[j], p[j + 1]);
            }
        }
    }

    show(sw);

    vector<pair<int, int>> known;
    for (auto [x, y] : sw) {
        assert(x < y);
        if (find(known.begin(), known.end(), mp(x, y)) != known.end()) continue;
        show(x, y);
        vector<int> gout(n, 0), gin(n, 0);
        for (auto [a, b] : known) {
            if (a == x) gout[b]++;
            if (a == y) gout[b]++;
            if (b == x) gin[a]++;
            if (b == y) gin[a]++;
        }
        vector<pair<int, int>> new_known;
        for (auto& [a, b] : known) {
            assert(a < b);
            if (a == x) {
                if (b > y) {
                } else {
                }
            } else if (a == y) {
                a = x;
            } else if (b == x) {
                b = y;
            } else if (b == y) {
                if (a < x) {
                } else {
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (gout[i] == 2)
                known.eb(y, i);
            if (gin[i] == 2)
                known.eb(i, x);
        }

        known.eb(x, y);
        show(known);

        vector<vector<int>> g(n);
        for (auto [a, b] : known)
            g[a].pb(b);

        for (int i = 0; i < n; ++i) {
            vector<bool> u(n, false);
            y_combinator([&](auto dfs, int v) -> void {
                u[v] = true;
                if (v != i) known.eb(i, v);
                for (int k : g[v])
                    if (!u[k])
                        dfs(k);
            })(i);
        }

        sort(known.begin(), known.end());
        known.erase(unique(known.begin(), known.end()), known.end());

        show(known);
    }
    cout << (known.size() == n * (n - 1) / 2 ? "ACCEPTED" : "REJECTED") << '\n';

    return 0;
}
