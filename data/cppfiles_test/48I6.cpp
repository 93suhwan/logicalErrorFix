
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> pre_sum(n+1);
    vector<ll> a(n+1),b(n+1);
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
        cin>>b[i];
    for(ll i=1;i<=n;i++)
        pre_sum[i] = pre_sum[i-1] + a[i]-b[i];
    ll L = log2(n+1)+1;
    vector<vector<ll>> st_max(n+1,vector<ll>(L)),st_min(n+1,vector<ll>(L));
    ll one = 1;
    for(ll i=0;i<n+1;i++)
        st_max[i][0] = pre_sum[i],st_min[i][0] = pre_sum[i];
    for(ll sz = 1;sz<L;sz++){
        for(ll i =0;i<n+1;i++){
            st_max[i][sz] = max(st_max[i][sz-1],st_max[min(n,i+(one<<(sz-1)))][sz-1]);
            st_min[i][sz] = min(st_min[i][sz-1],st_min[min(n,i+(one<<(sz-1)))][sz-1]);
        }
    }
    for(ll i =0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        if(pre_sum[l-1]!= pre_sum[r] || a[l] > b[l] || a[r] < b[r]){
            cout<<-1<<endl;
            continue;
        }
        ll mx_ans = INT64_MIN, mn_ans = INT64_MAX;
        ll lcp = l;
        for(ll sz = L-1;sz;sz--){
            if(lcp+(one<<sz)-1<= r){
                mn_ans = min(st_min[lcp][sz],mn_ans);
                mx_ans = max(st_max[lcp][sz],mx_ans);
                lcp += (one<<sz);
            }
        }
        mx_ans -= pre_sum[l-1];
        mn_ans -= pre_sum[l-1];
        cout<<max(abs(mx_ans),abs(mn_ans))<<endl;
    }
    return 0;
}