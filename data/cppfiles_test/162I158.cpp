#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (int i = 0; i < int(v.size()); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < int(v.size()); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << ' ';
    }
    return os;
}
struct gyouzasushi {
    gyouzasushi() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} gyouzasushi;
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> h_(n);
        cin >> h_;

        // 全部のheapをx以上にできるか？
        auto f = [&](ll x) -> bool {
            auto h = h_;
            for (int i = 2; i < n; i++) {
                ll d = 0;
                if (h[i - 2] < x) {
                    chmax(d, (x - h[i - 2] + 1) / 2);
                }
                if (h[i - 1] < x) {
                    chmax(d, x - h[i - 1]);
                }
                chmin(d, h[i] / 3);
                h[i - 2] += 2 * d;
                h[i - 1] += d;
                h[i] -= 3 * d;
            }
            return *min_element(all(h)) >= x;
        };
        ll ok = 0, ng = 2 * INF, mid;
        while (ng - ok > 1) {
            mid = (ok + ng) / 2;
            (f(mid) ? ok : ng) = mid;
        }
        cout << ok << '\n';
    }
}