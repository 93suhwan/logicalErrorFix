#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ss second
#define ff first
#define EPS (ld)(0.00000000000000000001)
#define needForSpeed cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define y1 fuckyoufuckyou
#define yes cout << "YES\n"
#define no cout << "NO\n"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<pair<pair<ll, ll>, ll>> ans;
    set<ll> cur;
    ll val = a[n - 1];
    cur.insert(a[n - 1]);
    for (long long i = n - 2; i >= 0; i--){
        if (a[i] <= val){
            val = a[i];
        } else{
            auto pos = cur.lower_bound(a[i]);
            ll ind = distance(cur.begin(), pos);
            ans.push_back ({{i, i + ind}, 1});
        }
        cur.insert(a[i]);
    }
    cout << ans.size() << endl;
    for(auto c : ans){
        cout << c.ff.ff + 1 << " " << c.ff.ss + 1 << " " << c.ss << endl;
    }
}

int main(){
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    long long DoYoUlIkEwHaTdOyOuSeE = 1;
    cin >> DoYoUlIkEwHaTdOyOuSeE;
    while(DoYoUlIkEwHaTdOyOuSeE--){
        solve();
    }
    return 0;
}
/**
**/
