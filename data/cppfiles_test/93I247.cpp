#include <bits/stdc++.h>
#define ll long long int
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
 
const int mod = 1e9 + 7;
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 /*
 
 
ll sie[100005]={0};
 
void pre()
{
   sie[1]=1;
   for(ll i=2;i*i<=100005;i++)
   {
      if(sie[i]==0)
      {
         sie[i]=i;
         for(ll j=i*i;j<=100005;j+=i)
         {
            if(sie[j]==0)
               sie[j]=i;
         }
      }  
   }
   F(i,1,100005)
   {
      if(sie[i]==0)
         sie[i]=i;
   }
}
int count1,vis[15],dis[15],low[15],par[15],ans[15];
vector<int>v[15];
vector<pair<int,int>>ans1;
void dfs(int n)
{
   vis[n]=1;
   dis[n]=count1++;
   low[n]=dis[n];
   int children=0;
   for(auto x : v[n])
   {
      if(!vis[x])
      {
         children++;
         par[x]=n;
         dfs(x);
         low[n]=min(low[x],low[n]);
         if(par[n]!=-1&&dis[n]<=low[x])
            ans[n]=1;
         if(low[x]>dis[n])
            ans1.push_back(make_pair(x,n));
      }
      else if(par[n]!=x)
      {
         low[n]=min(low[n],dis[x]);
      }
   }
   if(par[n]==-1&&children>=2)
      ans[n]=1;
}
vector<ll>v;
void func(string s,ll a1,ll a2,ll n1)
{
   if(s.length())
      v.push_back(stoll(s));
   if(s.length()==n1)
      return;
   if(s.length()==0&&a1==0)
   {
      s+=a2+'0';
      func(s,a1,a2,n1);
   }
   else
   {
      s+=a1+'0';
      func(s,a1,a2,n1);
      s[s.length()-1]=a2+'0';
      func(s,a1,a2,n1);
   }
}
 
*/
 
ll func(string s,ll i,ll j,char c)
{
    if(i>=j)
        return 0;
    ll count=0;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            if(s[i]==c)
            {
                i++;
                count++;
            }
            else if(s[j]==c)
            {
                j--;
                count++;
            }
            else
                return LONG_MAX;
        }
        else
        {
            i++;
            j--;
        }
    }
    return count;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
	ll test = 1;
	cin>>test;
	while(test--)
	{
	    ll n,k;
	    cin>>n>>k;
	    ll i=ceil((double)log2(k));
	    ll a=pow(2,i);
	    n-=a;
	    cout<<(n+k-1)/k+i<<endl;
	}
	return 0;
}