#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
#define ull unsigned long long
#define max_value 0x3f3f3f
#define all(v) v.begin(),v.end()
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define file freopen("C:/Users/KUMAR SATYAM/Desktop/on_the_run_input.txt","r",stdin);freopen("C:/Users/KUMAR SATYAM/Desktop/output.txt","w",stdout);
using namespace std;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<ll,ll> pii;
typedef pair<ll,pair<ll,ll>> pii1;
const int iinf=1e9+7;
const ll  inf=1e9+7;
const ll mod=998244353;
const ll maxn=2e5+5;
/*Nihal123456@*/
ll sqr(ll x)
{
    return x*x;
}
ll modd(ll a)
{
    if(a>0)
        return a%inf;
    while(a<0)
    {
        a+=inf;
    }
    return a;

}
vector<int> z_function(string s)
{
    int n=s.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1; i<n; i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l;
            r--;
        }
        else
        {
            int k=i-l;
            if(z[k]<(r-i+1))
                z[i]=z[k];
            else
            {
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }

    return z;
}
ll modexpo(ll a,ll b,ll iinf1)
{
    a%=iinf1;
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a%iinf1;
        a=a*a%iinf1;
        b>>=1;
    }
    return res;

}
/*a+b=a^b+2*(a and b)=(a or b)+(a and b) */


























































void solve(){
int n,m;
cin>>n>>m;
vector<bool>vis(n+1,false);
vector<pair<int,int>>ans;
while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    if(!vis[b]){
        ans.push_back({a,b});
    }
    if(!vis[c]){
      ans.push_back({a,c});
    }
    vis[a]=true;
    vis[b]=true;
    vis[c]=true;
}
for(auto it:ans){
    cout<<it.first<<" "<<it.second<<endl;
}



}




















































































int main()
{
    FIO;
    /*file;*/

int t;
cin>>t;
while(t--)
{
solve();


}


}

