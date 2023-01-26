#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define PI 3.141592653
#define pll pair<ll,ll>
#define V vector
#define F first
#define S second
#define INF LLONG_MAX
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll lcm(ll a, ll b){    return (a / __gcd(a, b)) * b;}

void solve(){
    ll n, d;
    cin >> n >> d;
    V<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ll flag = 0, res = 0;
    for(int i = 0; i < n; i++)
        flag |= v[i];
    while(flag && res < 9){
        flag = 0;
        V<ll> vec(n);
        for(int i = 0; i < n; i++)
            vec[i] = v[(i+n-d)%n];
        for(int i = 0; i < n; i++)
            v[i] &= vec[i], flag |= v[i];
        res++;
    }
    cout << (res < 9 ? res : -1ll) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}




