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
bool b[2002][2002][2][2];
pii dp[2002][2002][2][2];
pii fun(int i,int j,int k,int l,int n,string &s,string &t){
    if(i==n){
        if(j==n)return {0,1};
        else if(t[j]=='1')return {0,0};
        else return fun(i,j+1,k,0,n,s,t);
    }
    if(j==n){
        if(s[i]=='1')return {0,0};
        else return fun(i+1,j,0,l,n,s,t);
    }
    if(b[i][j][k][l])return dp[i][j][k][l];
    b[i][j][k][l]=true;
    if(s[i]=='0')return dp[i][j][k][l]=fun(i+1,j,0,l,n,s,t);
    if(t[j]=='0')return dp[i][j][k][l]=fun(i,j+1,k,0,n,s,t);
    pii ans={0,0};
    if(s[i]=='1'){
        if(t[j]=='1'){
            pii p=fun(i+1,j+1,0,0,n,s,t);
            ans.fi+=p.fi+abs(j-i)*p.se;
            ans.se+=p.se;
        }
        else{
            pii p=fun(i+1,j+1,0,0,n,s,t);
            ans.fi+=p.fi+abs(j-i)*p.se;
            ans.se+=p.se;
            p=fun(i,j+1,k,0,n,s,t);
            ans.fi+=p.fi;
            ans.se+=p.se;
        }
    }
    else{
        if(t[j]=='1'){
            pii p=fun(i+1,j+1,0,0,n,s,t);
            ans.fi+=p.fi+abs(j-i)*p.se;
            ans.se+=p.se;
            p=fun(i+1,j,0,0,n,s,t);
            ans.fi+=p.fi;
            ans.se+=p.se;
        }
        else{
            pii p=fun(i+1,j+1,0,0,n,s,t);
            ans.fi+=p.fi+abs(j-i)*p.se;
            ans.se+=p.se;
            p=fun(i+1,j+1,0,0,n,s,t);
            ans.fi+=p.fi;
            ans.se+=p.se;
            t[j]='1';
            p=fun(i+1,j,0,1,n,s,t);
            t[j]='?';
            ans.fi+=p.fi;
            ans.se+=p.se;
            s[i]='1';
            p=fun(i,j+1,1,0,n,s,t);
            s[i]='?';
            ans.fi+=p.fi;
            ans.se+=p.se;
        
        }
    }
    ans.fi%=mod;
    ans.se%=mod;
    return dp[i][j][k][l]=ans;
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
        string s,s1;
        cin>>s>>s1;
        for(int i=0;i<n;i+=2){
            if(s[i]=='0')s[i]='1';
            else if(s[i]=='1')s[i]='0';

            if(s1[i]=='0')s1[i]='1';
            else if(s1[i]=='1')s1[i]='0';
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[i][j][0][0]=false;
                b[i][j][0][1]=false;
                b[i][j][1][0]=false;
                b[i][j][1][1]=false;
            }
        }
        cout<<fun(0,0,0,0,n,s,s1).fi<<endl;
    }
    return 0;
}