#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{    if(a.first==b.first)return (a.second > b.second);
    else  return (a.first < b.first);}
int min(int x,int y){if(x<y)return x;else return y;}
int max(int x,int y){if(x>y)return x;else return y;}
unsigned long long power(unsigned long long x,int y, int p);
// vector<vector<int> > adj(200001); // adjacency list
// vector<bool> vis(200001);
// //  int a[100001];
// //  int exist;
// //  int dal;
// //  vector<int> val;
//  void dfs(int node)
// {  
//     vis[node]=true;
  
    
    
//     for(auto child: adj[node])
//     { 
//         if (!vis[child])
//         {      dfs(child);
            
            
//         }
//     }

    
    
   
// }

// int rnk[400005];
// int par[400005];
 
// void make_set(int n)
// {
// for(int i=1; i<=n; i++)
// {
// par[i] = i;
// rnk[i] = 1;
// }
// }
// int find_set(int x)
// {
// if( par[x] == x)
// {
// return x;
// }
// par[x]=find_set(par[x]);
// return par[x];
// }
 
// void union_set(int a, int b)
// {
// int p1 = find_set(a);
// int p2 = find_set(b);
// if ( p1 == p2)
// return;
// if (rnk[p1] > rnk[p2])
// {
// par[p2]=p1;
// rnk[p1] = rnk[p1] + rnk[p2];
// }
// else
// {
// par[p1] = p2;
// rnk[p2] = rnk[p1] + rnk[p2];
// }
// }
#define MAXN   100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
int mod=1e9+7;
int32_t main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     sieve();
      int t;
      cin>>t;
      while(t--)
      {
       

       int n,m;
       cin>>n>>m;
       int a[m],b[m],c[m];
       map<int,int> mp;
       for(int i=0;i<m;i++)
       {
           cin>>a[i]>>b[i]>>c[i];
           mp[b[i]]++;
       }
       int pos=0;
       for(int i=1;i<=n;i++)
       {
           if(mp[i]==0)
           {
               pos=i;
               break;
           }

       }
        for(int i=1;i<n;i++)
        { if(i!=pos)
          {
              cout<<pos<<" "<<i<<endl;
          }

        }
         
      }
   
       


 
    return 0;
}
//     val.clear();
    // 	val.resize(n+1);
    //   for(int i=1;i<=n;i++){
	// 		while(!adj[i].empty())adj[i].pop_back();
	// 	}
    //    for(int i=0;i<=n;i++){
    //          vis[i]=false;
    //      }
    //   for(int i=0;i<n-1;i++)
    //   {   int al,bl;
    //        cin>>al>>bl;
    //       adj[al].pb(bl);
    //       adj[bl].pb(al);
    //   }
unsigned long long power(unsigned long long x,
                                   int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
  if (y == 0) return 1;
    if (x == 0) return 0; 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}