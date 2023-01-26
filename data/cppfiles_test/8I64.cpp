/*
 * File created on 10/09/2021 at 19:25:04.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: ---
 * Copyright: Ⓒ 2021 Francois Vogel
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define size(x) (int)(x.size())
#define pb push_back
#define ins insert
#define cls clear

#define int ll
#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int siz = 1e5+40;
const int p2 = 1<<20;
const int inf = 1e18;

vi graph [siz];
int b [siz];
int st [siz];
int en [siz];
int rf [siz];

struct LCA {
    LCA() {
        t = new pii [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = pii(inf, inf);
    }
    void upd(int x, pii v) {
        x += p2;
        t[x] = v;
        for (x /= 2; x; x /= 2) t[x] = min(t[x*2], t[x*2+1]);
    }
    int get(int b, int e) {
        b += p2;
        e += p2;
        pii v = pii(inf, inf);
        while (b <= e) {
            if (b%2 == 1) {
                v = min(v, t[b]);
                b++;
            }
            if (e%2 == 0) {
                v = min(v, t[e]);
                e--;
            }
            b /= 2;
            e /= 2;
        }
        return v.s;
    }
    pii* t;
};

struct Segtree {
    Segtree() {
        t = new int [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    void upd(int b, int e, int v) {
        b += p2;
        e += p2;
        while (b <= e) {
            if (b%2 == 1) {
                t[b] += v;
                b++;
            }
            if (e%2 == 0) {
                t[e] += v;
                e--;
            }
            b /= 2;
            e /= 2;
        }
    }
    int get(int x) {
        int sum = 0;
        for (x += p2; x; x/= 2) sum += t[x];
        return sum;
    }
    int* t;
};

int tim = 0;
void dfs(int x, int p, vi& path) {
    st[x] = en[x] = tim++;
    path.pb(x);
    for (int y : graph[x]) if (y != p) {
        dfs(y, x, path);
        path.pb(x);
        en[x] = en[y];
    }
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, nbQ;
    cin >> n >> nbQ;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = max(b[i], -b[i]);
    }
    for (int i = 0; i < n-1; i++) {
        int na, nb;
        cin >> na >> nb;
        na--;
        nb--;
        graph[na].pb(nb);
        graph[nb].pb(na);
    }
    vi path;
    dfs(0, -1, path);
    LCA lca = LCA();
    for (int i = 0; i < size(path); i++) {
        lca.upd(i, pii(path[i], i));
        rf[i] = i;
    }
    Segtree q = Segtree();
    for (int i = 0; i < n; i++) q.upd(st[i], en[i], b[i]);
    for (int i = 0; i < nbQ; i++) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x, v;
            cin >> x >> v;
            v = max(v, -v);
            x--;
            q.upd(st[x], en[x], v-b[x]);
            b[x] = v;
        }
        else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            int z = lca.get(min(rf[x], rf[y]), max(rf[x], rf[y]));
            int loc = q.get(st[x])+q.get(st[y])-2LL*q.get(st[z]);
            loc += b[z];
            loc *= 2LL;
            loc -= b[x];
            loc -= b[y];
            cout << loc;
            cout << '\n';
        }
    }

    cout.flush();
    int d = 0;
    d++;
}