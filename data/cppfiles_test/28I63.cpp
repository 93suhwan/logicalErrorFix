#include<bits/stdc++.h>
using namespace std; 
 
#define fast            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli             long long int
#define ld              long double
#define pll             pair<lli,lli>
#define ve              vector<lli>
#define vep             vector<pll>
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define all(x)          (x).begin(),(x).end()
#define fr(i,a,n)       for(lli i=a;i<(n);i++)
#define frx(i,a,n)      for(lli i=a;i>(n);i--)
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            '\n'
#define op(x)           cout<<x<<endl
#define op2(x,y)        cout<<x<<" "<<y<<endl
#define parr(arr,a,n)   fr(u,a,n) cout<<arr[u]<<" "; cout<<endl
#define yes             cout<<"YES"<<endl
#define no              cout<<"NO"<<endl
#define mem(a,x)        memset(a,x,sizeof(a))
#define sz(a) 		    ((lli) a.size())
#define db(x)           cout << "[ " << x << " ]" << endl
#define db2(x,y)        cout<<"[ " <<x<<" "<<y<< " ]" <<endl

void solve(){
    lli n,m;
    cin>>n>>m;
    lli a[n+5],b[n+5]={0};
    fr(i,1,n+1)cin>>a[i];
    fr(i,1,n+1){
        if(i>=a[i]) b[i-a[i]]++;
        else{
            b[n-a[i]+i]++;
        }
    }
    ve v;
    fr(i,0,n){
        lli temp=n-b[i];
        if((temp+1)/2<=m)v.pb(i);
    }
    cout<<sz(v)<<" ";
    parr(v,0,sz(v));
}

int main(){
    fast;
    lli test=1;
    cin>>test;
    while(test--){
        solve();
    }
}
