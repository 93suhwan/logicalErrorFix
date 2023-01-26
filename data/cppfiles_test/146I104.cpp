#include <bits/stdc++.h>

#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(x, y) for(auto& x : y)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define pw(x) (1LL << (x))
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo find_by_order
#define ook order_of_key

template<typename T>
bool umn(T& a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T>
bool umx(T& a, T b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ve = vector<T>;

const int N = 1e5 + 5;

int ROOT;
int n, q;
int to[N];
int par[N];

int go[N];

int main() {
#ifndef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    cin >> n >> q;

    ROOT = sqrt(n);

    fr(i, 0, n - 1) {
        cin >> to[i];
        to[i]--;
        par[to[i]] = i;
    }

    fr(i, 0, n - 1) {
        int v = i;
        fr(j, 1, ROOT) {
            v = to[v];
        }
        go[i] = v;
    }

    fr(i, 0, q - 1) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            swap(par[to[x]], par[to[y]]);
            swap(to[x], to[y]);

            int v = x;
            fr(j, 1, ROOT) v = par[v];
            go[v] = x;
            while(v != x) {
                go[to[v]] = to[go[v]];
                v = to[v];
            }
            v = y;
            fr(j, 1, ROOT) v = par[v];
            go[v] = y;
            while(v != y) {
                go[to[v]] = to[go[v]];
                v = to[v];
            }
        }
        if(t == 2) {
            int v, k;
            cin >> v >> k;
            v--;

            while(k - ROOT >= 0) {
                v = go[v];
                k -= ROOT;
            }
            while(k > 0) {
                v = to[v];
                k--;
            }
            cout << v + 1 << "\n";
        }
    }

    return 0;
}