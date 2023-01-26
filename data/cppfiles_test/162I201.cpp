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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
bool check(int k,int a[],int n){
    int b[n];
    for(int i=0;i<n;i++)b[i]=a[i];
    for(int i=n-1;i>=0;i--){
        if(b[i]<k)return false;
        if(i>1){
            int  x=a[i]-k;
            x/=3;
            a[i]-=3*x;
            a[i-1]+=x;
            a[i-2]+=2*x;
        }
    }
    return true;
}
int search(int start,int end,int a[],int n){
    if(start==end)return start;
    int mid=(start+end+1)/2;
    if(check(mid,a,n))return search(mid,end,a,n);
    else return search(start,mid-1,a,n);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<search(0,2e9,a,n)<<endl;
    }
    return 0;
}