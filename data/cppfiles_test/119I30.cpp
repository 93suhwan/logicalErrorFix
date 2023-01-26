#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<ll, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            s += x;
        }
        if(s % n == 0){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
        
    }   
return 0;
}