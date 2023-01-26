#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/* Find by order, Order of Key */

#define int long long
#define deb(x)      cout << #x << " " << x << "\n"
#define db          double
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define all(x)      (x).begin(),(x).end()

void deb_out() { 
    cout << endl; 
}

template <typename Head, typename... Tail>
void deb_out(Head H, Tail... T) {
    cout << " " << H;
    deb_out(T...);
}

const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n);
    vector<int> tmp,zr;
    rep(i,0,n){
        cin >> v[i];
    }
    for(int i=1;i<n;i+=2){
        ans += min(v[i],v[i-1]);
        if(v[i]-v[i-1]==0){
            zr.push_back(0);
        }else{
            tmp.push_back(v[i-1]-v[i]);
            zr.push_back(v[i-1]-v[i]);
        }
    }
    for(int i=1;i<tmp.size();i++){
        if(tmp[i]<0 && tmp[i-1]>0){
            ans += min(abs(tmp[i]),abs(tmp[i-1]));
        }
    }
    int cnt = 0;
    for(int i=0;i<zr.size();i++){
        if(zr[i]>0){
            cnt++;
        }else if(zr[i]<0){
            cnt++;
            ans += ((cnt)*(cnt+1))/2 - cnt;
            cnt = 0;
        }else{
            cnt++;
        }
    }
    ans += ((cnt)*(cnt+1))/2 - cnt;
    cout << ans << "\n";
}

int32_t main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}