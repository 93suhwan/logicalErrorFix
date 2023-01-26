#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define si set<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define add push_back
#define REP(i,a) for (int i = 0; i < (a); i++)
using namespace std;
 
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
const int INF = 1005000000; 
const ll MOD = 1000000007LL;
//const ll MOD = 998244353LL;
 
int ni() {
    int x; cin >> x;
    return x;
}
 
ll nl() {
    ll x; cin >> x;
    return x;
}
 
double nd() {
    double x; cin >> x;
    return x;
}
 
string next() {
    string x; cin >> x;
    return x;
}

ll solve(vi& nums) {
    ll ans = 0;
    for (int n: nums) {
        for (int m: nums) {
            ans += __gcd(n,m);
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = ni();
    vi nums(N);
    REP(i,N) nums[i] = ni();

    vi extra(N+1);
    iota(all(extra),0);

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        vi take;
        for (int j = i; j <= N; j += i) {
            take.add(nums[j-1]);
            if (j > i) extra[j] -= extra[i];
        }
        ans += extra[i]*solve(take);
    }
    cout << ans;
}