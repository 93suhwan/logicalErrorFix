#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(a,b) for (ll i=a;i<b;i++)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
 
  
#define nl << '\n'
#define sp << " " <<
const ll MOD = 1e9+7;
 
bool cmp(const pair<ll,ll> &v1, const pair<ll,ll> &v2){
      
       
    //   if( v1.second - v1.first == v2.second - v2.first){
           
    //       if(v1.second==v2.second){
    //           return v1.first<v2.first;
    //       }
    //       return v1.second > v2.second;
    //   }
      return v1.second  < v2.second;
}
 
 
 
bool isPalindrome(string str){
   
    int l = 0;
    int h = str.size() - 1;
  
   
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
          return false;
        }
    }
    return true;
}
 
 
 
ll factorial(ll n){
  
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
 
 
  
ll nCr(ll n,ll r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
 
vector<ll> printDivisors(ll n){
    vector<ll> ans;
    
    
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            
            if (n/i == i)
              {
                  ans.push_back(i);
              }
 
            else {
                ans.push_back(i);
                ans.push_back(n/i);
            }
              
        }
    }
    return ans;
}
 
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); }
 
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
 
ll binaryexpo(ll a,ll b){
        ll result= 1;
        while(b){
            if(b%2) result =(result*a + MOD)%MOD;
            a=((a)*(a))%MOD;
            b/=2;
        }
        return result;
}
 
vector<bool> SieveOfEratosthenes(ll n)
{
  ll count=0;
  
     vector<bool > prime(n + 1,true);
 
    for (ll p = 2; p * p <= n; p++)
    {
        
        if (prime[p] == true)
        {
            
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    // for (ll p = 2; p <= n; p++){
    //     if (prime[p]){
    //          count+=1;
    //     }    
        
    // }     
    return prime;
}
 
bool isPower(ll x, ll y)
{
    // logarithm function to calculate value
    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
 
// void dijkstra(vector<pair<ll,ll>> adj[],ll node, vector<ll> &dis){
    
//   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
 
// 	dis[node]=0;
	
// 	q.push({0,node});
	
// ll disprev,prev,currnum,currw;
 
// 	while(!q.empty()){
// 	    disprev=q.top().first;
// 	    prev=q.top().second;
	    
// 	    q.pop();
//          if (dis[prev] != disprev) continue;
// 	    for(auto x: adj[prev]){
// 	           currnum=x.first;
//             currw=x.second;
           
// 	        if(dis[prev] + currw < dis[currnum]){
// 	            dis[currnum]=dis[prev] + currw;
// 	            q.push({dis[currnum],currnum});
// 	        }
// 	    }
// 	}
	
// }
 
 
 
// void dfs(ll n,vector<ll> adj[],ll flag,vector<ll> &vis,ll node,vector<ll> &path){
//     vis[node]=1;
//     if(flag==1){
//       path.push_back(node);
//       if(node==n+1){
//           flag=0;
//       }
//     } 
//     for(auto x : adj[node]){
        
//         if(!vis[x]){
//             dfs(n,adj,flag,vis,x,path);
//         }
//     }
// }
 
bool dfscyl(vector<ll> &vis,vector<ll> adj[],ll node,ll p,vector<ll> &incall){
    
  vis[node] = 1; 
   
  incall[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfscyl(vis,adj,it,node,incall))return true; 
                  
            }
            else if(incall[it]) 
                return true; 
        }
        incall[node]=0;
        return false; 
}
 
void toposort(ll node,vector<ll> &vis1,vector<ll> adj[],stack<ll> &path){
    vis1[node]=1;
    
    for(auto x:  adj[node]){
        
        if(!vis1[x]){
            toposort(x,vis1,adj,path);
        }
    }
    
    path.push(node);
}
 
 
 
ll findpar(ll node,vector<ll> &par){
    
    if(par[node]==node) return node;
    return par[node]=findpar(par[node],par);
}
 
 
void unionbyrank(ll x,ll y,vector<ll> &par,vector<ll> &rank){
    ll u=findpar(x,par);
    ll v=findpar(y,par);
    
    
    if(rank[u]>rank[v]){
        par[v]=u;
        rank[u]+=rank[v];
       
    }
    else if(rank[v]>rank[u]){
         par[u]=v;
         rank[v]+=rank[u];
         
    }
    else{
        par[v]=u;
        rank[u]+=rank[v];
      
    }
}



int main() {
    
    fio;   
   
	ll t=1;
	cin>>t;
	
	
	while(t--){
	  ll n,m;
	  cin>>n>>m;
	  
	  if(n==m){
	      cout<<n nl;
	  }
	  else{
          
          if(n>m) cout<<(n+m) nl;
          else{
              cout<< m + (m%n)/2 nl;
          }
	  }
	  
	}
}
