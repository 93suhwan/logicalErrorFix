#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define ld  long double
#define st first
#define nd second
#define ar array
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
//#define matrix vector<vector<int> >
//#define FILENAME
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1000000007;
const ld E=1e-10;
const ld PI=acos(-1);
typedef pair<int,int> pa;
typedef pair<ld,ld> pd;
int pw(int a,int b){
    int res=1;
    while(b){
        if (b%2) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}
const int mxn=4e5+7;
struct node {
    int w, x, y;
};
int pre[mxn], n, m, par[mxn], rnk[mxn], isa[mxn], ans, q, mx[mxn], res[mxn];
pa qr[mxn], a[mxn];
int f(int u) {
    while (u != par[u]) u = par[u];
    return u;
}
int sum(int l, int r) {
    if (l>r) return 0;
    return pre[r] - pre[l-1];
}
void join(int u, int v) {
    u = f(u); v = f(v);
    if (u == v) return;
    if (rnk[u] < rnk[v]) swap(u, v) ;
    rnk[u] += rnk[v];
    par[v] = u;
    ans -= sum(mx[u] - isa[u] + 1, mx[u]);
    ans -= sum(mx[v] - isa[v] + 1, mx[v]);
    isa[u] += isa[v];
    mx[u] = max (mx[u], mx[v]);
    ans += sum(mx[u] - isa[u] + 1, mx[u]);
}
vector<node> edge;
bool ss(node u, node v) {
    return u.w > v.w;
}

signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>n>>q;
    for (int i=1; i<=m; i++) cin>>a[i].st, a[i].nd = 1;
    for (int i=1; i<=n; i++) cin>>a[m+i].st;
    sort(a+1, a+n+m+1);
    for (int i=1; i<=m+n; i++) {
        par[i] = mx[i] = i;
        rnk[i] = 1;
        pre[i] = pre[i-1] + a[i].st;
        if (a[i].nd ==1 ) isa[i] = 1, ans += a[i].st;
    }
    for (int i=1; i<m+n; i++) edge.pb({a[i+1].st - a[i].st, i, i+1});
    sort(edge.begin(), edge.end(), ss);
    for (int i=1; i<=q; i++) cin>>qr[i].st, qr[i].nd = i;
    sort(qr+1, qr+1+1);
    for (int i=1; i<=q; i++) {
        while (edge.back().w <= qr[i].st) {
            node p = edge.back();
            join (p.x, p.y);
            edge.pop_back();
        }
        res[qr[i].nd] = ans;
    }
    for (int i=1; i<=q; i++) cout<<res[i]<<endl;
    return 0;
}

