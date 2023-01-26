#include<iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long int ll;
ll mod=998244353;
int prime[8001];
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;
void init(){
    prime[0]=1;prime[1]=1;
    for(int i=2;i<=8000;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=8000;j+=i)
            prime[j]=1;
        }
    }
}
int divisor(int n){
    int c=0;
    while (n % 2 == 0)
    {
        c++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            c++;
            n = n/i;
        }
    }
    if (n > 2)
        c++;
    return c;
}
ll invmod(ll a,ll b,ll m){
    ll res=1;
    while(b){
        if(b%2)
        res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}
bool sort(int a[],int n){
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1])
        return false;
    }
    return true;
}
bool is_sub(string &s1,string &s2){
    int i=0;int j=0;
    while(i<s1.length()&&j<s2.length()){
        if(s1[i]==s2[j]){
            i++;j++;
        }
        else j++;
    }
    if(i==s1.length())
    return true;
    return false;
}
ll fastpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2)
        res=(res*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    cin>>T;
    ll fact[200001];fact[0]=1;
    ll invfact[200001];invfact[0]=1;
    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=fastpow(fact[i],mod-2);
    }
    while(T--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        if(arr[n-1]-arr[n-2]>1){
            cout<<0<<"\n";
            continue;
        }
        else if(arr[n-1]==arr[n-2]){
            cout<<fact[n]%mod<<"\n";
            continue;
        }
        else{
            ll cnt=0;
            for(int i=n-2;i>=0;i--){
                if(arr[i]+1==arr[n-1])
                cnt++;
                else break;
            }
            cout<<cnt<<"\n";
            ll pos=cnt+1;ll rem=n-cnt-1;ll j=rem;ll cal=1;
            ll res=0;
            for(ll i=n;i>=pos;i--){
                ll modval=fastpow(fact[j],mod-2)%mod;
                ll val=(fact[rem]*modval)%mod;
                res=(res%mod+(fact[n-cal]*val)%mod)%mod;
                j--;cal++;
            }
            cout<<(fact[n]%mod-res%mod+mod)%mod<<"\n";
        }
    }
}