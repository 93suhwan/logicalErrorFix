#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        ll b[n-1];
        for(int i=0;i<n-1;i++){
            int r=a[i+1]-a[i];
            ll l=1;
            while(r--){
                l=l*10;
            }
            b[i]=l-1;
        }
        ll ans=-1;
        ll s=0;
        ll p=0;
        for(int i=0;i<n-1;i++){
            s+=b[i];
            ll y=1;
            for(int j=0;j<a[i];j++){
                y=y*10;
            }
            if(s>k){
                ans=p+y*(k-s+b[i]+1);
            }
            p+=y*b[i];
        }
        ll y=1;
        for(int j=0;j<a[n-1];j++){
            y=y*10;
        }
        if(ans==-1){
            ans=p+y*(k-s+1);
        }
        cout<<ans<<endl;
    }
}    