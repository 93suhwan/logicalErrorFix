#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define take(i)                    int i;cin>>i
#define taken                    take(n)
#define gcd(a,b)                __gcd(a,b)
#define endl                    '\n'
#define f                        first
#define s                        second
#define pb                        push_back
#define rep(i,a,b,c)            for(int i=a;i<b;i+=c)
#define ub                        upper_bound
#define lb                        lower_bound
#define bs                        binary_search
#define all(x)                    x.begin(), x.end()
#define mp                        make_pair
#define PI                        3.141592653589793238
#define E                        2.7182818284590452353602874713527
#define pi                        pair<int,int>
#define vi                        vector<int>
typedef unsigned long int    uli;
typedef long long        ll;
typedef unsigned long long    ull;
const unsigned int M = 1000000007;

//using namespace __gnu_pbds;
using namespace std;

ull binpow(ll a,ll b,ll m);

void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n+1]={};
    arr[0]=1;
    arr[1]=1;
    ll sum=0,pr=0;
    rep(i,1,n+1,1){
        int ls=i;
        arr[i]=(arr[i]+sum)%m;
        int j,k;
        for(j=1;j*j<=i;j++){
            // if(i==n)cout<<ls<<" "<<j<<"\n";
            k=i/(j+1);
            if(j>=k)break;
            if(i==n)cout<<j<<" "<<ls-k<<"\n";
            arr[i]=(arr[i]+((ls-k)*arr[j])%m)%m;
            if(i==n-1)cout<<k<<" "<<1<<"\n";
            arr[i]=(arr[i]+arr[k])%m;
            ls=k;
        }
        if(j==k){
            if(i==n-1)cout<<j<<" "<<ls-k<<"\n";
            arr[i]=(arr[i]+((ls-k)*arr[j])%m)%m;
        }

        // arr[i]+=(arr[i]+arr[j-])%m;
        // if(i==n)cout<<j<<"\n";
        // if(i==n)cout<<j<<" "<<ls<<"\n";
        // rep(j,2,i+1,1){
        //     if(i==n)cout<<i/j<<" ";
        //     arr[i]=(arr[i]+arr[i/j])%m;
        // }
        sum=(sum+arr[i])%m;
    }
    cout<<arr[n];
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}

ull binpow(ll a,ll b,ll m){
    if(b==0)return ll(1);
    ull a1=binpow(a,b/2,m);
    if(b%2) {
        a1 = (a1*a1)%m;
        return (a*a1)%m;
    }
    else return (a1*a1)%m;
}