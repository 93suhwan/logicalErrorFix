#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i, val, n) for(int i = val; i <= n; i++)
#define repr(i, val, n) for(int i = n; i >= val; i--)
using namespace std;
const ll mod = 998244353;
const ll inf = 1e9 + 100;
const double eps = 1e-7;
const ld pi = acos(-1);
const int M = 3e5 + 5, N = 5e4 + 5;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void test() {
    ordered_set s;
    int n;cin>>n;
    int x[n];
    int ans = 0;
    map<int,int> f;
    s.insert(x[0]);
    f[x[0]]++;
    for(int i = 1;i < n;i++){
        cin>>x[i];
        int no = s.order_of_key(x[i]);
        ans+=min(no, i - no - f[x[i]]);
        s.insert(x[i]);
        f[x[i]]++;
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int cases = 1, c = 1;
    cin >> cases;
    while (cases--) {
        test();
    }
    return 0;
}