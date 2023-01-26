#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fo(i,n) for(int i=0;i<n;i++)
 

 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
const int MOD = 1000000007;
 
const int MAXN = 10000000, MAXK = 18;


vector<bool>p(MAXN+1,true);
vector<int>test;
void seive()
{
      
    p[0]=p[1]=false;
    for(int i=2;i*i<=MAXN;i++)
    {
        for(int j=i*i;j<=MAXN;j+=i)
        {
            p[j]=false;
        }
    }
    
    for(int i=0;i<=MAXN;i++)
    {
        if(p[i])
        {
            test.pb(i);
            
        }
    }
    
    
}
int power(int x, int y)
{
    int res = 1;   
 
    x = x % MOD; 
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        
        if (y & 1)
            res = (res*x) % MOD;
 
       
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res%MOD;
}


int gcd(int a,int b)
{
    
    return (__gcd(a,b));
    
}


int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
    
}





 

int32_t main()
{
   
        
      int t;
      t=1;
      
     cin>>t;
      while(t--)
      {
          
         int n;
         cin>>n;
         vi v;
         fo(i,n)
         {
             int x;
             cin>>x;
             v.pb(x);
             
         }
         sort(all(v));
         
         int mid=n/2;
         cout<<-v[mid-1]+v[mid+1-1]<<endl;
         
         
      }
          
    
        
   
   
   
   return 0;
}
