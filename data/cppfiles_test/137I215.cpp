#include <bits/stdc++.h>
#include <sys/types.h>
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define sc second
#define ft first
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define sz(s) s.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<pi, null_type, less<pi>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
const ll N = 1e6+5,MOD = 998244353, INF = 2e18;
ll n, m, t, ans;
deque<int> a,b;
map<deque<int>,int> dp;
bool check(deque<int> x)
{
    return x == b;
}
bool solve(deque<int> x)
{
    if(sz(x) > sz(b))
        return false;
    if(dp.find(x) != dp.end()){
        return dp[x];
    }
    while(sz(x) && x.front() == 0)
        x.pop_front();
    dp[x] = check(x);
    deque<int> tmp1 = x,tmp2 = x,tmp3 = x;
    tmp1.pb(1);
    tmp2.pb(1);
    reverse(all(tmp1));
    reverse(all(tmp3));
    return dp[x] |=(solve(tmp1) || solve(tmp2) || solve(tmp3));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(n)
    {
        a.pb((n%2));
        n/=2;
    }
    reverse(all(a));
    while(m)
    {
        b.pb((m%2));
        m/=2;
    }
    reverse(all(b));
    cout << (solve(a)?"YES\n":"NO\n");
}
