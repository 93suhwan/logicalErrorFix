//『 朝日が升れば离ればなれ
//   终着駅のような朝が来る 』
// AC自动机Fail树上DFS序建可持久化线段树
// 后缀自动机Next指针DAG图上求SG函数
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a),rend(a)
#define all(a) begin(a),end(a)
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define pb emplace_back
#define int long long
using namespace std;
const int N = 2e5 + 10, p = 1e9 + 7;
int a[N];
void solve()
{
    int n, g; cin >> n;
    rep(i, 1, n) cin >> a[i];
    g = 0; rep(i, 1, n) g = gcd(g, a[i]), ++i;
    rep(i, 2, n) if (!(a[i++] % g)) { g = 0; break; }
    if (g) return cout << g << '\n', void();
    g = 0; rep(i, 2, n) g = gcd(g, a[i]), ++i;
    rep(i, 1, n) if (!(a[i++] % g)) { g = 0; break; }
    cout << g << '\n';
}
signed main()
{
    cout.tie(0)->sync_with_stdio(0);
    int _;for (cin >> _; _--; ) solve();
    return 0;
}