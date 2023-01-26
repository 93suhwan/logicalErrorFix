#include <bits/stdc++.h>
using namespace std;
// Compile with "(g++) -std=c++11 -Wall -Wextra -Wconversion -Wshadow -Dcychien"
#ifdef cychien
#define debug(...) do {\
	fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
#define IOS
#else
#define debug(...)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define rsz resize
#define X first
#define Y second
#define SZ(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld PI = 3.14159265358979323846264338327950288;
int n, root;
vll ans;
vi vis, p;
vvi g, dg;
void dfs(int x){
    vis[x] = 1;
    for (auto& ch : g[x]){
        if (!vis[ch]){
            dg[x].pb(ch);
            p[ch] = x;
            dfs(ch);
        }
    }
}
int attempt(int k){
    debug(k);
    int ggd = 0;
    vi res(n, 0), pt(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (SZ(dg[i]) == 0){
            q.push(i);
        }
    }
    int flag = 1;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        if (f == root){
            ggd = __gcd(ggd, pt[f]);
            break;
        }
        if (pt[f] % k == 0){
            pt[p[f]]++;
        }
        else if ((pt[f] + 1) % k == 0){
            pt[f]++;
        }
        else {
            flag = 0;
        }
        res[p[f]]++;
        if (res[p[f]] == SZ(dg[p[f]])){
            q.push(p[f]);
        }
        ggd = __gcd(ggd, pt[f]);
    }
    debug(k, ggd);
    if (!flag) return 0;
    return (ggd == k ? 1 : 0);
}
void solve(){
    cin >> n;
    if (n == 2){
        int a;
        cin >> a;
        cin >> a;
        cout << "1 0\n";
        return;
    }
    p.clear();
    p.rsz(n, -1);
    g.clear();
    g.rsz(n);
    ans.clear();
    ans.rsz(n + 1, 0);
    vis.clear();
    vis.rsz(n, 0);
    dg.clear();
    dg.rsz(n);
    FOR (i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    FOR (i, n){
        if (SZ(g[i]) >= 2){
            root = i;
            break;
        }
    }
    dfs(root);
    ll tot = 0;
    for (int k = 2; k < n; k++){
        if ((n - 1) % k == 0){
            ans[k] = attempt(k);
            if (ans[k]) tot++;
        }
    }
    debug(120);
    ll res = 1;
    FOR (i, n - 1){
        res <<= 1;
        res %= MOD;
    }
    res += MOD - tot;
    res %= MOD;
    cout << res;
    for (int i = 2; i <= n; i++){
        cout << ' ' << ans[i];
    }
    cout << '\n';
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
