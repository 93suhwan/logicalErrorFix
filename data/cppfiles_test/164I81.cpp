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

const int N = 2e5 + 5;

int n, k;
char c[N];
int l[N], r[N];
string s;
ve<int> st;
bool good[N];
bool ans[N];

int cost[N];

void DFS(int v = 1) {
    if(l[v]) {
        cost[l[v]] = cost[v] + 1;
        DFS(l[v]);
    }
    ans[v] |= ans[l[v]];

    // cout << v << " " << cost[v] << " " << k << " " << good[v] << "\n";

    if(!ans[v] && good[v] && cost[v] <= k) {
        k -= cost[v];
        ans[v] = 1;
    }

    if(r[v] && good[v]) {
        if(ans[v]) cost[r[v]] = 1;
        else cost[r[v]] = cost[v] + 1;

        DFS(r[v]);
        ans[v] |= ans[r[v]];
    }
}

void dfs(int v = 1) {
    if(l[v]) dfs(l[v]);
    st.pb(v);
    if(r[v]) dfs(r[v]);
}

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

    cin >> n >> k;

    fr(i, 1, n) {
        cin >> c[i];
    }

    fr(i, 1, n) {
        cin >> l[i] >> r[i];
    }

    dfs();

    // fr(i, 0, sz(st) - 1) cout << c[st[i]];
    // cout << "\n";

    rf(i, sz(st) - 2, 0) {
        if(c[st[i]] < c[st[i + 1]] || (c[st[i]] == c[st[i + 1]] && good[st[i + 1]])) {
            good[st[i]] = 1;
        }
    }

    cost[1] = 1;
    DFS();

    // fe(x, st) cout << x << " ";
    // cout << "\n";

    // fe(x, st) cout << c[x];
    // cout << "\n";

    fe(x, st) {
        cout << c[x];
        if(ans[x]) cout << c[x];
    }
    cout << "\n";


    return 0;
}