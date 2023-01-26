//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007  
#define fi first
#define se second
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 100000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans; 
}
int spf[1000006]={0};
int h[1000006]={0};
int hash_fact[1000006]={0};
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
void sieve(){
    spf[1]=1;
    for(int i=2;i<1000006;i++){
        for(int j=i;j<1000006;j+=i){
            if(spf[j]==0)spf[j]=i;
        }
        if(spf[i]==i){
            h[i]=rng()+1;
        }
        else h[i]=(h[i/spf[i]]^h[spf[i]]);
        hash_fact[i]=(hash_fact[i-1]^h[i]);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    sieve();
    int n;
    cin>>n;
    int x=0;
    for(int i=2;i<=n;i++){
        x^=hash_fact[i];
    }
    if(x==0){
        cout<<n<<endl;
        for(int i=0;i<n;i++)cout<<i+1<<" ";
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(x==hash_fact[i]){
                cout<<n-1<<endl;
                for(int j=1;j<=n;j++)if(i!=j)cout<<j<<" ";
                return 0;
            }
        }
        sort(hash_fact,hash_fact+n+1);
        for(int i=1;i<=n;i++){
            int k=lower_bound(hash_fact,hash_fact+n+1,(x^hash_fact[i]))-hash_fact;
            if(k==i)k++;
            if(k<=n&&x==(hash_fact[i]^hash_fact[k])){
                cout<<n-2<<endl;
                for(int j=1;j<=n;j++)if(i!=j&&j!=k)cout<<j<<" ";
                return 0;
            }
        }
        x^=hash_fact[n];
        for(int i=1;i<n;i++){
            int k=lower_bound(hash_fact,hash_fact+n+1,(x^hash_fact[i]))-hash_fact;
            if(k==i)k++;
            if(k<n&&x==(hash_fact[i]^hash_fact[k])){
                cout<<n-3<<endl;
                //cout<<i<<" "<<k<<endl;
                for(int j=1;j<n;j++)if(i!=j&&j!=k)cout<<j<<" ";
                return 0;
            }
        }
    }
    return 0;
}