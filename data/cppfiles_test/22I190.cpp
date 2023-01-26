/*
    author:  Maksim1744
    created: 25.07.2021 21:44:09
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
#include "/home/maksim/cpplibs/print.cpp"
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k);
    for (int i = 0; i < k; ++i) {
        int l;
        cin >> l;
        v[i].resize(l);
        cin >> v[i];
        --v[i];
    }

    vector<int> p(n, 1);

    y_combinator([&](auto calc, vector<int> &p, int ind) -> void {
        show(p, ind);
        if (ind == k) {
            if (!is_sorted(p.begin(), p.end()) || (count(p.begin(), p.end(), 1) && n != 1)) {
                show(p);
                cout << "REJECTED\n";
                exit(0);
            }
            return;
        }
        auto &inds = v[ind];
        vector<int> cur;
        for (int i = 0; i < inds.size(); ++i)
            cur.pb(p[inds[i]]);
        int k = count(cur.begin(), cur.end(), 1);
        sort(cur.begin(), cur.end());
        for (int cc = 0; cc <= k; ++cc) {
            int left = cc;
            for (int i = 0; i < cur.size(); ++i) {
                p[inds[i]] = (cur[i] != 1 ? cur[i] : (left-- > 0 ? 0 : 2));
            }
            calc(p, ind + 1);
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] == 1)
                    p[inds[i]] = 1;
            }
        }
    })(p, 0);
    cout << "ACCEPTED\n";

    return 0;
}
