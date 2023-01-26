#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(I,v,b) for(int I=v;I<b;I++)
#define ROF(I,v,b) for(int I=v;I>=b;I--)
#define vec vector
#define vi vec<int>
#define pb push_back
#define pp pop_back
#define all(x) x.begin(),x.end()
#define sgm(x) x.begin(),x.begin()
#define testcases int tc;cin>>tc;while(tc--)
#define mem(v,k) memset(v,k,sizeof(v))
#define FF first
#define SS second
#define rt return
#define br break
#define ct continue
#define endl "\n"
#define ii pair<int,int>
#define vecin(v,n,index) for(int I=index;I<n;I++)cin>>v[I];
#define vecout(v,n,index) for(int I=index;I<n;I++)cout<<v[I]<<" ";cout<<endl;

int isPossible(vi &k, int n, int prev, int x, int cur, auto &dp) {
    if (dp[n][cur][prev] != -1)rt dp[n][cur][prev];
    if (cur == x)rt dp[n][cur][prev] = 1;
    if (n == 0)rt dp[n][cur][prev] = 0;
    int res = isPossible(k, n - 1, prev, x, cur, dp);
    if (prev > k[n - 1])res |= isPossible(k, n - 1, k[n - 1], x, cur ^ (k[n - 1]), dp);
    rt dp[n][cur][prev] = res;
}
void solve() {
    int n;
    cin >> n;
    vi v(n);
    vecin(v, n, 0);
    map<int, int> vs;
    vi k;
    FOR(i, 0, n) {
        if (vs[v[i]]) {
            if (v[i] > k.back())k.pb(v[i]);
            ct;
        }
        k.pb(v[i]);
        vs[v[i]] = 1;
    }
    n = k.size();
    int maxe = *max_element(all(k));
    int s = ceil(log2(maxe));
    int mxor = (1LL << (s + 1)) - 1;
    vi ans(1);
    FOR(x, 1, mxor + 1) {
        int cur = 0;
        vec<vec<vi>> dp(n + 1, vec<vi> (mxor + 1, vi(502, -1)));
        if (isPossible(k, n, 501, x, cur, dp)) {
            ans.pb(x);
        }
    }
    vecout(ans, ans.size(), 0);
}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

    // testcases
    solve();
}



