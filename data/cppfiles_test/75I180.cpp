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
/*ll par[1005];
ll rank1[1005];
ll find_set(ll a)
{
    if(a==par[a])
    {
        return a;
    }
    else
    {
        return par[a]=find_set(par[a]);
    }
}
ll union_set(ll a,ll b)
{
    ll par1=find_set(a);
    ll par2=find_set(b);
    if(par1==par2)// cycle
    {
        return 1;
    }
    else
    {
        if(rank1[par1]<rank1[par2])
        {
            par[par1]=par2;
            return 0;
        }
        else
        {
            if(rank1[par1]==rank1[par2])
            {
                rank1[par1]++;
                par[par2]=par1;
                return 0;
            }
            else
            {
                par[par2]=par1;
            }
        }
    }
}*/
/*for(ll i=1;i<=n;i++)
{
    par[i]=i;
    rank1[i]=0;
}*/
//In C++, comparator should return false if its arguments are equal.
//code goes here
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
    //cin>>t;
    //sieve();
    // for above 10^7 or 10^8 use int or long long as per the requirement//avoids runtime error 
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        ll left=0,right=n-1;
        ll turn=0;
        int flag=0;
        ll prev=-1;
        while(left<=right)
        {
            if(left==right)
            {
                if(arr[left]<=prev)
                {
                    if(turn%2)
                    {
                        cout<<"Alice\n";
                    }
                    else
                    {
                        cout<<"Bob\n";
                    }
                }
                else
                {
                    if(turn%2)
                    {
                        cout<<"Bob\n";
                    }
                    else
                    {
                        cout<<"Alice\n";
                    }
                }
                break;
            }
            else
            {
                ll val1=arr[left];
                ll val2=arr[right];
                if(max(val1,val2)<=prev)
                {
                    if(turn%2)
                    {
                        cout<<"Alice\n";
                    }
                    else
                    {
                        cout<<"Bob\n";
                    }
                    break;
                }
                else
                {
                    ll val3=arr[left+1];
                    ll val4=arr[right-1];
                    // if i take val1 
                    ll max1=max(val1,val2);
                    if(max1==val1)
                    {
                    if(val1>prev)
                    {
                    if(max(val3,val2)<=val1)
                    {
                        left++;
                        turn^=1;
                        prev=val1;
                        continue;
                    }
                    else
                    {
                        if(val2==val3)
                        {
                            if(left+2<=right)
                            {
                                if(max(arr[left+2],arr[right-1])>val2)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                            else
                            {
                                if(arr[right-1]>val2)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                        }
                        if(val2==max(val2,val3))
                        {
                            // val3 val4 
                            if(max(val3,val4)>val2)
                            {
                                left++;
                                turn^=1;
                                prev=val1;
                                continue;
                            }
                        }
                        else
                        {
                            if(left+2<=right)
                            {
                                if(max(val2,arr[left+2])>val3)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                            else if(val2>val3)
                            {
                                left++;
                                turn^=1;
                                prev=val1;
                                continue;
                            }
                        }
                    }
                    }
                    if(val2>prev)
                    {
                    if(max(val1,val4)<=val2)
                    {
                        right--;
                        turn^=1;
                        prev=val2;
                        continue;
                    }
                    else
                    {
                        if(val1==val4)
                        {
                            if(right-2>=left)
                            {
                                if(max(arr[right-2],arr[left+1])>val1)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                            else
                            {
                                if(arr[left+1]>val1)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                        }
                        if(val1==max(val1,val4))
                        {
                            // val3 val4 
                            if(max(val3,val4)>val1)
                            {
                                right--;
                                turn^=1;
                                prev=val2;
                                continue;
                            }
                        }
                        else
                        {
                            if(right-2>=left)
                            {
                                if(max(val1,arr[right-2])>val4)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                            else if(val1>val4)
                            {
                                right--;
                                turn^=1;
                                prev=val2;
                                continue;
                            }
                        }
                    }
                    }
                    }
                    else
                    {
                    if(val2>prev)
                    {
                    if(max(val1,val4)<=val2)
                    {
                        right--;
                        turn^=1;
                        prev=val2;
                        continue;
                    }
                    else
                    {
                        if(val1==val4)
                        {
                            if(right-2>=left)
                            {
                                if(max(arr[right-2],arr[left+1])>val1)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                            else
                            {
                                if(arr[left+1]>val1)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                        }
                        if(val1==max(val1,val4))
                        {
                            // val3 val4 
                            if(max(val3,val4)>val1)
                            {
                                right--;
                                turn^=1;
                                prev=val2;
                                continue;
                            }
                        }
                        else
                        {
                            if(right-2>=left)
                            {
                                if(max(val1,arr[right-2])>val4)
                                {
                                    right--;
                                    turn^=1;
                                    prev=val2;
                                    continue;
                                }
                            }
                            else if(val1>val4)
                            {
                                right--;
                                turn^=1;
                                prev=val2;
                                continue;
                            }
                        }
                    }
                    }
                    if(val1>prev)
                    {
                    if(max(val3,val2)<=val1)
                    {
                        left++;
                        turn^=1;
                        prev=val1;
                        continue;
                    }
                    else
                    {
                        if(val2==val3)
                        {
                            if(left+2<=right)
                            {
                                if(max(arr[left+2],arr[right-1])>val2)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                            else
                            {
                                if(arr[right-1]>val2)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                        }
                        if(val2==max(val2,val3))
                        {
                            // val3 val4 
                            if(max(val3,val4)>val2)
                            {
                                left++;
                                turn^=1;
                                prev=val1;
                                continue;
                            }
                        }
                        else
                        {
                            if(left+2<=right)
                            {
                                if(max(val2,arr[left+2])>val3)
                                {
                                    left++;
                                    turn^=1;
                                    prev=val1;
                                    continue;
                                }
                            }
                            else if(val2>val3)
                            {
                                left++;
                                turn^=1;
                                prev=val1;
                                continue;
                            }
                        }
                    }
                    }
                    }
                    if(val1==max(val1,val2))
                    {
                        left++;
                        prev=val1;
                    }
                    else
                    {
                        right--;
                        prev=val2;
                    }
                    turn^=1;
                }
            }
        }
    }
    return 0;
}