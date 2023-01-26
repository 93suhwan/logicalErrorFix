#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll  long long int
#define ld  long double

#define ordered_set tree<pair<ll ,int>, null_type,greater<pair<ll ,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1e18

#define N 1000010

#define MOD 1000000007
using namespace std;

using namespace __gnu_pbds;
const long double pi = 3.141592653589793238;

const int MAXN = 1010;

int n;
ll par[MAXN], siz[MAXN];
ll par2[MAXN], siz2[MAXN];

// zero based
void init() {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
}

// zero based
void init2() {
    for (int i = 0; i < n; i++) {
        par2[i] = i;
        siz2[i] = 1;
    }
}

ll find(ll x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}


ll find2(ll x) {
    return x == par2[x] ? x : par2[x] = find(par2[x]);
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

bool same2(ll a, ll b) {
    return find2(a) == find2(b);
}


void unit(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (siz[b] > siz[a])
        swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}

void unit2(ll a, ll b) {
    a = find2(a);
    b = find2(b);

    if (siz2[b] > siz2[a])
        swap(a, b);
    siz2[a] += siz2[b];
    par2[b] = a;
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif

    int m1, m2, u, v;

    cin >> n >> m1 >> m2;
    map<pair<int, int>, bool> mp;
    init();
    for (int i = 0; i < m1; ++i) {
        cin >> u >> v;
        u--, v--;
        unit(u, v);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (same(i, j)) mp[{i, j}] = true, mp[{j, i}] = true;
        }
    }

    init2();
    for (int i = 0; i < m2; ++i) {
        cin >> u >> v;
        u--, v--;
        unit2(u, v);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (same2(i, j)) {
                mp[{i, j}] = true;
                mp[{j, i}] = true;
            }
        }
    }
    int ans = 0;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!mp[{i, j}])
                ans++, vec.push_back({i, j});
        }
    }
    int mx = max(m1, m2);
    ans = min(ans, n - 1 - mx);
    cout << ans << endl;
    int cnt = 0;
    for (int i = 0; cnt < ans; ++i) {
        int a = vec[i].first;
        int b = vec[i].second;

        if (!same(a, b) && !same2(a, b)) {
            unit(a, b);
            unit2(a, b);
            mp[{a, b}] = true;
            mp[{b, a}] = true;
            cout << a + 1 << " " << b + 1 << endl;
            cnt++;
        }
    }

    return 0;
}