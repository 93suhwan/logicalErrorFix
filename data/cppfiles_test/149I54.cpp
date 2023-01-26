#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

using namespace std;

vi primes;

ull binpow(ll a,ll b,ll m);
void primesfill(int k);

void solve(){
    ll n,k,x;
    cin>>n>>k>>x;
    ll j=1;
    string s;
    cin>>s;
    string ans="";
    // for(int i=n-1;i>=0;i--){
    //     if(s[i]=='a'){ans="a"+ans;continue;}
    //     if(j*k<x){
    //         j*=k;
    //         rep(l,0,k,1)ans="b"+ans;
    //     }
    //     else{
    //         int t=1;
    //         while(j*t<x){
    //             t++;
    //             ans="b"+ans;
    //         }
    //         j=j*t;
    //     }
    // }
    ll ct=0;
    vector<ll> tp;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){ct++;}
        else if(ct){
            tp.push_back(ct*k+1);
            ct=0;
        }
    }
    if(ct)tp.push_back(ct*k+(ct!=0));
    int n1=tp.size();
    for(int i=n1-2;i>=0;i--){
        tp[i]*=tp[i+1];
    }
    // for(ll a:tp)cout<<a<<" ";
    rep(i,0,tp.size(),1){
        if(s[i]==0){cout<<'a';continue;}
        if(i+1<tp.size() && tp[i+1]>=x){tp[i]=0;continue;}
        int a=1;
        if(i+1<tp.size()){
            while((a+1)*tp[i+1]<x){
                a++;
            }
            x-=a*tp[i+1];
            tp[i]=a;
        }
        else {
            tp[i]=x-1;
        }
        // cout<<x;
    }
    ct=0;
    int in=0;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){ct++;continue;}
        else{
            if(ct){
                for(int l=0;l<tp[in];l++)cout<<'b';
                in++;
            } 
            ct=0;
            cout<<'a';
        }  
    }
    if(ct)for(int l=0;l<tp[in];l++)cout<<'b';

}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
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

void primesfill(int k){
    primes = vector<int>(k+1,1);
    primes[1]=0;
    for(int i=2;i<=k;i++){
        if(!primes[i])continue;
        for(int j=i*2;j<=k;j+=i){
            primes[j]=0;
        }
    }
}