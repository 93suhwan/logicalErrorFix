#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
using namespace std;

int main() {
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,i,j,k;
        cin>>n;ll a[n];
        for(i=0;i<n;i++)cin>>a[i];
        ll x=a[0];
        ll y=a[1];
        for(i=2;i<n;i+=2)
        x=__gcd(x,a[i]);
        for(i=3;i<n;i+=2)
        y=__gcd(y,a[i]);
        if(x==y)
        cout<<"0\n";
        else {
                ll p=0,q=0;
                for(i=0;i<n;i+=2){
                    if(a[i]%y==0){
                        p=1;break;
                    }
                }
                for(i=1;i<n;i+=2){
                    if(a[i]%x==0){
                        q=1;
                        break;
                    }
                }
                if(p==1&&q==1)
                cout<<"0\n";
                else
                  cout<<max(x,y)<<"\n";
            
        }
    }
    return 0;
}