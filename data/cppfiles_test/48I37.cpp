#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> pbds_mset;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> pbds_set;
#define ll long long
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define mod2 998244353
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vll,greater<ll>>
#define val_at find_by_order
#define less_than order_of_key


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	t=1;
	cin>>t;
	start:
	while(t--){

            ll n;
    cin>>n;
    ll arr[n+1],temp[n+1],next[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i],temp[i]=arr[i];

    sort(temp+1,temp+1+n);
    map<vll,ll> mp;

    for(ll i=1;i<=n-2;i++){
        mp[{temp[i],temp[i+1],temp[i+2]}]=1;
    }

    for(ll i=1;i<n;i++){
        next[temp[i]]=temp[i+1];
    }
    next[temp[n]]=-1;



     if(n==1){
        cout<<"YES"<<endl;
        goto start;
     }
     if(n==2){
        if(arr[2]>=arr[1]){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        goto start;
     }


   for(ll i=1;i<=n-2;i++){
       if(arr[i]!=arr[i+1] && arr[i+1]!=arr[i+2] && arr[i+2]!=arr[i] && (i==1 || arr[i]!=arr[i-1]) && (i==n-2 || arr[i+3]!=arr[i+2])){
            vll v;
       v.pb(arr[i]);
       v.pb(arr[i+1]);
       v.pb(arr[i+2]);
        sort(v.begin(),v.end());
       if(!(mp[v]==1)) continue;
        if(v[1]==arr[i+1] && v[2]==arr[i]){
            cout<<"NO"<<endl;
            goto start;
        }
        if(v[1]==arr[i] && v[2]==arr[i+2]){
             cout<<"NO"<<endl;
            goto start;
        }
        if(v[1]==arr[i+2] && v[2]==arr[i+1]){
             cout<<"NO"<<endl;
            goto start;
        }
       }
   }
   cout<<"YES"<<endl;


	}
	return 0;

}
