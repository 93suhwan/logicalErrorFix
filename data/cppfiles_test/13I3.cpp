#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <chrono>
using namespace __gnu_pbds; 
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace chrono;
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e17
#define neginf -1e17
#define sp(y, x) fixed << setprecision(x) << y
#define all(x) x.begin(), x.end()
#define power(a, b) (double)pow((double)a, (double)b)
#define gcd(a, b) __gcd(a, b)
#define PI 3.1415926535
#define ss second
#define ff first
#define umap unordered_map
#define ummap unordered_multimap
#define uset unordered_set
#define umset unordered_multiset
//vector<vector<int>> dp(n+1,vector<int>(x+1,0)); vector of vectors
ll powerm(ll a,unsigned long long int b,ll mod)  
{  
    ll ans = 1;   
    a = a % mod; 
    if (a == 0) return 0; 
    while (b > 0)  
    {  
        if (b & 1)  
        ans = (ans*a) % mod;  
        b = b>>1;  
        a = (a*a)%mod;  
    }  
    return ans;  
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
//0 indexing arr1->input array and arr seg array 
void buildseg(ll arr[],ll le,ll ri,ll idx,ll arr1[])
{
    if(le==ri)
    {
        arr[idx]=arr1[le];
        return;
    }
    else
    {
        ll mid=le+(ri-le)/2;
        buildseg(arr,le,mid,2*idx+1,arr1);
        buildseg(arr,mid+1,ri,2*idx+2,arr1);
        arr[idx]=arr[2*idx+1]+arr[2*idx+2];
        return;
    }
}
ll rangesum(ll arr[],ll l1,ll r1,ll l2,ll r2,ll idx)
{
    //complete overlap
    if(l1<=l2&&r1>=r2)
    return arr[idx];
    //no overlap
    if(l1>r2||r1<l2)
    return 0;
    ll mid=(l2+r2)/2;
    return (rangesum(arr,l1,r1,l2,mid,2*idx+1)+rangesum(arr,l1,r1,mid+1,r2,2*idx+2));
}
void update(ll arr[],ll le,ll re,ll idx,ll idx1,ll arr1[],ll val)
{
    if(idx1<le||idx1>re)
    return;
    if(le==re)
    {
        arr1[le]=val;
        arr[idx]=val;
        return;
    }
    else
    {
        ll mid=(le+re)/2;
        if(idx1<=mid)
        {
            update(arr,le,mid,2*idx+1,idx1,arr1,val);
        }
        else
        {
            update(arr,mid+1,re,2*idx+2,idx1,arr1,val);
        }
        arr[idx]=arr[2*idx+1]+arr[2*idx+2];
        return;
        
    }
    
}
/*#define MAXX 15000005
ll spf[MAXX];
void sieve()
{
    spf[1]=1;
    for(ll i=2;i<MAXX;i++)
    spf[i]=i;
    for(ll i=4;i<MAXX;i=i+2)
    spf[i]=2;
    for(ll i=3;i*i<MAXX;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i;j<MAXX;j=j+i)
            if(spf[j]==j)
            spf[j]=i;
        }
    }
}
vector<ll> findfact(ll x)
{
    vector<ll>ans;
    while(1)
    {
        if(x==1)
        break;
        ans.pb(spf[x]);
        x=x/spf[x];
    }
    return ans;
}*/
/*ll par[100005];
ll dist[100005];
ll anc[100005][32];
void precom(ll n)
{
   for(ll i=1;i<=20;i++)
   {
       for(ll j=1;j<=n;j++)
       {
           ll d1=anc[j][i-1];
           ll d2;
           if(d1!=-1)
           d2=anc[d1][i-1];
           else
           d2=-1;
           anc[j][i]=d2;
       }
   }
}
ll findkanc(ll val,ll k)
{
    if(k==0)
    return val;
    ll d1=20;
    ll ans=-1;
    while(k)
    {
        if(d1==-1)
        break;
        ll po=(ll)(pow(2,d1));
        if(k<po)
        {
            d1--;
            continue;
        }
        else
        {
            ll val1=anc[val][d1];
            k-=po;
            if(val1==-1)
            {val=val1;
            break;
            }
            val=val1;
        }
    }
    return val;
}
ll lca(ll u,ll v)
{
    if(u==v)
    {
        return u;
    }
    ll d1=dist[u];
    ll d2=dist[v];
    //cout<<d1<<" "<<d2<<"\n";
    if(d2>d1)
    {
       swap(u,v); 
    }
    ll dif=dist[u]-dist[v];
    ll same_level=findkanc(u,dif);
    if(same_level==v)
    return v;
    for(ll i=20;i>=0;i--)
    {
        if(anc[same_level][i]!=anc[v][i])
        {
            //cout<<same_level<<" "<<v<<"\n";
            same_level=anc[same_level][i];
            v=anc[v][i];
        }
    }
    return findkanc(same_level,1);
}*/
//In C++, comparator should return false if its arguments are equal.
//code goes here
ll arr[500][500];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    ll t;
    t=1;
    cin>>t;
    //sieve();
    // for above 10^7 or 10^8 use int or long long as per the requirement//avoids runtime error 
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        for(ll i=0;i<500;i++)
        for(ll j=0;j<500;j++)
        arr[i][j]=0;
        if(n%2==0&&m%2==0)
        {
            if(k%2==0)
            {
                cout<<"YES"<<"\n";
                //ll arr[n+5][m+5];
                for(ll i=0;i<n+1;i++)
                {
                    for(ll j=0;j<m+1;j++)
                    arr[i][j]=0;
                }
                ll cnt=0;
                for(ll i=1;i<=n;i+=2)
                {
                    for(ll j=1;j<=m;j+=2)
                    {
                        if(arr[i][j]!=0)
                        continue;
                        if(cnt>=k)
                        break;
                       /* if(i%2==0)
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            else
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            k+=2;
                        }
                        else
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            else
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            k+=2;
                        }
                       // k+=2;*/
                       ll d1=j/2;
                       if(d1%2==0)
                       {
                           arr[i][j]=1;
                           arr[i+1][j]=2;
                           arr[i][j+1]=1;
                           arr[i+1][j+1]=2;
                       }
                       else
                       {
                           arr[i][j]=2;
                           arr[i+1][j]=1;
                           arr[i][j+1]=2;
                           arr[i+1][j+1]=1;
                       }
                       cnt+=2;
                    }
                }
                for(ll i=1;i<=n;i+=2)
                {
                    for(ll j=1;j<=m;j++)
                    {
                        if(arr[i][j]==0)
                        {
                            ll d1=i/2;
                       if(d1%2==0)
                       {
                           arr[i][j]=3;
                           arr[i+1][j]=3;
                           arr[i][j+1]=4;
                           arr[i+1][j+1]=4;
                       }
                       else
                       {
                           arr[i][j]=4;
                           arr[i+1][j]=4;
                           arr[i][j+1]=3;
                           arr[i+1][j+1]=3;
                       }
                        }
                    }
                }
                for(ll i=1;i<=n;i++)
                {
                    for(ll j=1;j<=m;j++)
                    {
                        cout<<(char)(97+arr[i][j]);
                    }
                    cout<<"\n";
                }
            }
            else
            {
                cout<<"NO"<<"\n";
            }
        }
        else
        {
            if(n%2==0)
            {
                
                if(k%2==0)
                {
                    ll m1=n*((m-1)/2);
                    if(k>m1)
                    cout<<"NO"<<"\n";
                    else
                    {
                    cout<<"YES"<<"\n";
                    //ll arr[n+5][m+5];
                for(ll i=0;i<n+1;i++)
                {
                    for(ll j=0;j<m+1;j++)
                    arr[i][j]=0;
                }
                ll cnt=0;
                for(ll i=1;i<=m;i+=2)
                {
                    for(ll j=1;j<=n;j+=2)
                    {
                        if(arr[j][i]!=0)
                        continue;
                        if(cnt>=k)
                        break;
                       /* if(i%2==0)
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            else
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            k+=2;
                        }
                        else
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            else
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            k+=2;
                        }
                       // k+=2;*/
                       ll d1=i/2;
                       if(d1%2==0)
                       {
                           arr[j][i]=1;
                           arr[j+1][i]=2;
                           arr[j][i+1]=1;
                           arr[j+1][i+1]=2;
                       }
                       else
                       {
                           arr[j][i]=2;
                           arr[j+1][i]=1;
                           arr[j][i+1]=2;
                           arr[j+1][i+1]=1;
                       }
                       cnt+=2;
                    }
                }
                for(ll i=1;i<=n;i+=2)
                {
                    for(ll j=1;j<=m;j++)
                    {
                        if(arr[i][j]==0)
                        {
                            ll d1=i/2;
                       if(d1%2==0)
                       {
                           arr[i][j]=3;
                           arr[i+1][j]=3;
                           arr[i][j+1]=4;
                           arr[i+1][j+1]=4;
                       }
                       else
                       {
                           arr[i][j]=4;
                           arr[i+1][j]=4;
                           arr[i][j+1]=3;
                           arr[i+1][j+1]=3;
                       }
                        }
                    }
                }
                    for(ll i=1;i<=n;i++)
                {
                    for(ll j=1;j<=m;j++)
                    {
                        cout<<(char)(97+arr[i][j]);
                    }
                    cout<<"\n";
                }
                }
                }
                else
                cout<<"NO"<<"\n";
            }
            else
            {
                /*ll d1=k*2;
                if(d1%m!=0)
                {
                    cout<<"NO"<<"\n";
                }
                else
                {
                    ll d2=d1/m;
                    if(d2%2!=0)
                    {
                        cout<<"YES"<<"\n";
                    }
                    else
                    cout<<"NO"<<"\n";
                }*/
                ll d1=k*2;
                ll d2=n*m-d1;
                ll d3=d2/2;
                if(d3%2==0)
                {
                    ll m1=m*((n-1)/2);
                    if(d3>m1)
                    cout<<"NO"<<"\n";
                    else
                    {
                    cout<<"YES"<<"\n";
                    //ll arr[n+5][m+5];
                for(ll i=0;i<n+1;i++)
                {
                    for(ll j=0;j<m+1;j++)
                    arr[i][j]=0;
                }
                k=d3;
                ll cnt=0;
                for(ll i=1;i<=n;i+=2)
                {
                    for(ll j=1;j<=m;j+=2)
                    {
                        if(arr[i][j]!=0)
                        continue;
                        if(cnt>=k)
                        break;
                       /* if(i%2==0)
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            else
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            k+=2;
                        }
                        else
                        {
                            ll d1=j/2;
                            if(d1%2==0)
                            {
                                arr[i][j]=2;
                                arr[i][j+1]=2;
                            }
                            else
                            {
                                arr[i][j]=1;
                                arr[i][j+1]=1;
                            }
                            k+=2;
                        }
                       // k+=2;*/
                       ll d1=i/2;
                       if(d1%2==0)
                       {
                           arr[i][j]=1;
                           arr[i+1][j]=2;
                           arr[i][j+1]=1;
                           arr[i+1][j+1]=2;
                       }
                       else
                       {
                           arr[i][j]=2;
                           arr[i+1][j]=1;
                           arr[i][j+1]=2;
                           arr[i+1][j+1]=1;
                       }
                       cnt+=2;
                    }
                }
                for(ll i=1;i<=m;i+=2)
                {
                    for(ll j=1;j<=n;j++)
                    {
                        if(arr[i][j]==0)
                        {
                            ll d1=i/2;
                       if(d1%2==0)
                       {
                           arr[i][j]=3;
                           arr[i+1][j]=3;
                           arr[i][j+1]=4;
                           arr[i+1][j+1]=4;
                       }
                       else
                       {
                           arr[i][j]=4;
                           arr[i+1][j]=4;
                           arr[i][j+1]=3;
                           arr[i+1][j+1]=3;
                       }
                        }
                    }
                }
                ll arr1[m+1][n+1];
                    for(ll i=1;i<=m;i++)
                {
                    for(ll j=1;j<=n;j++)
                    {
                        arr1[i][j]=arr[i][j];
                    }
                    //cout<<"\n";
                }
                for(ll i=1;i<=n;i++)
                {
                    for(ll j=1;j<=m;j++)
                    cout<<(char)(97+arr1[j][i]);
                    cout<<"\n";
                }
                }
                }
                else
                cout<<"NO"<<"\n";
            }
        }
        
    }
    return 0;
}