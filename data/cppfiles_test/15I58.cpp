#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define vi             vector<ll> 
#define mi             map<ll,ll>
#define pi             pair<ll,ll>
#define pqueue         priority_queue<ll,vector<ll>,greater<ll>>
#define si             set<ll>
#define endl            "\n"
#define ins             insert 
#define hell             1000000007
#define PI              3.1415926535897932384
#define ll              long long 
#define f               first
#define s              second
#define pb             push_back
#define pp             pop_back
#define fr(n)          for(ll i=0;i<n;i++)
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define narak             998244353 
#define decimal(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define make make_pair
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define sz(a) (ll)a.size()
#define loop(i,a,b) for(ll i=a;i<=b;i++)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//std::ifstream in("input.txt");
//std::ofstream out("output.txt");
/*

INT_MIN Minimum value for a variable of type int. -2147483647 
INT_MAX Maximum value for a variable of type int.  2147483647
LLONG_MIN Minimum value for a variable of type long long. -9,223,372,036,854,775,807 
LLONG_MAX Maximum value for a variable of type long long.  9,223,372,036,854,775,807


bool comp(ll a,ll b) 
{ return (a < b); } 
ll spf[1000005];
void build()
{
    for(ll i=2;i<1000005;i++)
    {
        if(!spf[i])
        {
            for(ll j=1;j*i<1000005;j++)
            {
            if(!spf[i*j])
              spf[i*j]=i;  
            }
        }
    }}
map<ll,ll>allpowofno(ll n)
{
    map<ll,ll>mp;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            mp[i]++;
            n/=i;
            i--;
        }
    }
    if(n!=1)
    mp[n]++;
    return mp;}
ll primepow(ll n,ll k)
{
    ll res=0;
    while(n)
    {
      n/=k;
      res+=n;
    }
    return res;}
ll allpowofnocomp(ll n,ll k)
{
    mi mp=allpowofno(k);
    ll ans;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        cout<<it->f<<" "<<it->s<<endl;
        ll z=primepow(n,it->f);
        ans=min(ans,z/(it->s));
    }
    return ans;    }
ll spf[1000005];
void build()
{
    for(ll i=2;i<1000005;i++)
    {
        if(!spf[i])
        {
            for(ll j=1;j*i<1000005;j++)
            {
            if(!spf[i*j])
              spf[i*j]=i;  
            }
        }
    }   
}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{
  return (a.second < b.second); 
} 



ll modInverse(ll n,ll p) 
{ 
    return power(n,p-2,p); 
}

const int N=+1e+5+5;
const int LG=20;
vector<ll>g[N];
ll parent[LG][N];
ll timer=0;
ll tin[N],tout[N],level[N];

int __lca(int u,int v)
{
    if(level[u]<level[v])
        swap(u,v);
    int diff=level[u]-level[v];
    for(int i=LG-1;i>=0;i--)
    {
        if((1<<i) & diff){
            u=parent[i][u];
        }
    }
    if(u==v)
        return u;
    for(int i=LG-1;i>=0;i--)
    {
        if(parent[i][u] and parent[i][u]!=parent[i][v])
        {
            u=parent[i][u];
            v=parent[i][v];
        }
    }
    return parent[0][u];
}


void dfs(ll v,ll par,ll lvl)
{
    arr[v]=cnt;
    tin[v]=++timer;
    parent[0][v]=par;
    level[v]=lvl;
    
    for(auto &u:g[v])
    {
        if(u==par)
            continue;
        dfs(u,v,lvl+1);
    }
    tout[v]=timer;
}
bool is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v] and tout[u]>=tout[v]);
}
void precompute()
{
    for(int i=1;i<LG;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(parent[i-1][j])
            {
                parent[i][j]=parent[i-1][parent[i-1][j]];
            }
        }
    }
}

ll kthancestor(ll v,ll p)
{
    ll curr=v;
    for(ll i=20;i>=0;i--)
    {
        if( 1<<i & p)
            curr=parent[i][curr];
    }
    return curr;
}

void buildtree(ll *tree,ll *s,ll index,ll start,ll end)
{
    if(start>end)
    return ;
    if(start==end)
    {
        tree[index]=s[start];
        return;
    }
    ll mid=(start+end)/2;
    buildtree(tree,s,2*index,start,mid);
    buildtree(tree,s,2*index+1,mid+1,end);
    ll left=tree[2*index];
    ll right=tree[2*index+1];
    tree[index]=max(left,right);
    return ;
}
ll query(ll *tree,ll index,ll s,ll e,ll qs,ll qe)
{
    // no overlap
    if(qs>e||s>qe)
    return int_MIN;
    if(qe>=e&&s>=qs)
    {
        return tree[index];
    }
    ll mid=(s+e)/2;
    ll left=query(tree,2*index,s,mid,qs,qe);
    ll right=query(tree,2*index+1,mid+1,e,qs,qe);
    return max(left,right);
}
buildtree(tree,s,1,0,n-1); // 1 based tree is formed but array is 0 based
query(tree,1,0,n-1,x,y); // x and y are indexss


vector<ll>fac(200005);
void build()
{
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<=200000;i++)
    {
        fac[i]=i*fac[i-1];
        fac[i]%=N;
    }

}



ll power(ll x,ll y,ll p)
{
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
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
ll modInverse(ll n,ll p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
ll ncr(ll n,ll r,ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    
 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}




ll phi(ll n) 
{ 
      
    // Initialize result as n 
    double result = n;  
   
    // Consider all prime factors of n  
    // and for every prime factor p, 
    // multiply result with (1 - 1/p) 
    for(ll p = 2; p * p <= n; ++p) 
    { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) 
        { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
                  
            result *= (1.0 - (1.0 / p)); 
        } 
    } 
   
    if (n > 1) 
        result *= (1.0 - (1.0 / n)); 
   
    return (ll)result; 
} 



ll gcdExtended(ll a,ll b,ll *x,ll *y)
{
    if(a==0)
    {
        // 0*x+ b*y=b  => y=1; and x=0;
        *x=0;
        *y=1;
        return b;
        
    }
    // Update x and y using results of
    // recursive call
    // a*x+b*y=gcd(a,b);
    // Replace a with b%a
    // (b%a)*x1+a*y1=gcd(b%a,a);
    //  ( b- (b/a)*a )x1 + a*y1 =gcd(b%a,a)
    //  a*(y1-(b/a)*x1)+b*y1=gcd(b%a,a)
    // since gcd(a,b)=gcd(b%a,a)
    // comparing coefficient
    // x= y1- (b/a)*x1
    // y=x1
    
    ll y1,x1;
    ll gcd=gcdExtended(b%a,a,&x1,&y1);
    
    *x=y1-(b/a)*x1;
    *y=x1;
    
    return gcd;
}







const ll N=100005;
ll lpf[N],mobius[N];

void LPF()
{
    lpf[1]=1;
    for(ll i=2;i<N;i++)
    {
        if(!lpf[i])
        {
            for(ll j=i;j<N;j+=i)
            {
                if(!lpf[j])
                {
                    lpf[j]=i;
                }
            }
        }
        
    }
    return ;
    
}

void Mobius()
{
    mobius[1]=1;
    for(ll i=2;i<=N-2;++i)
    {
        if(lpf[i/lpf[i]]==lpf[i])
            mobius[i]=0;
        else
            mobius[i]=-1*mobius[i/lpf[i]];
    }
}






bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        for(auto i = g[v].begin(); i != g[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[n+1];
    bool *recStack = new bool[n+1];
    for(int i = 0; i <= n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 1; i <= n; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

void topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    for ( auto i = g[v].begin(); i != g[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
vector<int> topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[n+1];
    for (int i = 1; i <= n; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    vector<int>xx;
    // Print contents of stack
    while (Stack.empty() == false) {
        xx.push_back(Stack.top());
        Stack.pop();
    }
    return xx;
}

*/
const ll N=105;
vector<ll>g[N];
ll child[N][N];
ll has[N][N];
ll n,k;
ll vis[N];
ll dist[N];


ll power(ll x,ll y,ll p)
{
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
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
ll modInverse(ll n,ll p)
{
    return power(n, p - 2, p);
}



vector<ll>fac(105);
void build()
{
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<=100;i++)
    {
        fac[i]=i*fac[i-1];
        fac[i]%=N;
    }

}

 
// Returns nCr % p using Fermat's little
// theorem.
ll ncr(ll n,ll r,ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    
 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}




void dfs(ll x,ll y)
{
    child[x][0]++;
    vis[x]=1;
    has[x][0]++;
    for(ll y:g[x])
    {
        if(vis[y]) continue;
        dfs(y,x);
        for(ll j=0;j<=k;j++)
        {
            if(child[y][j])
            has[x][j+1]++;
            child[x][j+1]+=child[y][j];
        }
    }
    
}


void solve(ll nn)
{
    cin>>n>>k;
    string str;
    getline(cin,str);
    
    ll ans=0;
    mem0(child);
    mem0(has);
    mem0(vis);
    
    for(ll i=1;i<=n;i++)
    {
        g[i].clear();
    }
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y); 
        g[y].pb(x);
    }
    
    
    if(k==2)
    {
        ans+=(n-1);
    }
    
    for(ll i=1;i<=n;i++)
    {
        mem0(vis);
        mem0(child);
        mem0(dist);
        mem0(has);
        dfs(i,0);
        
        ll temp=0;
        
        ll product[n+1];
        for(ll j=1;j<=n;j++)
        {
            if(child[i][j])
            product[j]=1;
            else
            product[j]=0;
        }
        
        
        
        for(ll j=1;j<=n;j++)
        {
            for(ll kk=j;kk<=j;kk++)
            {
                
                
                
                ll pr=1;
                for(ll x:g[i])
                {
                    if(child[x][kk-1])
                    pr=pr*child[x][kk-1];
                    pr%=hell;
                }
                
                for(ll x:g[i])
                {
                    // dist contider = j
                    // rem vertices dist= k 
                    
                    if(j==kk)
                    {
                        if(dist[j])
                        continue;
                        else
                        dist[j]=1;
                    }
                    
                    
                    ll cnt1=has[x][j-1];
                    ll cnt2=(has[i][kk]-has[x][kk-1]);
                    
                    //cout<<i<<" "<<x<<" "<<j<<" "<<kk<<" "<<cnt1<<" "<<cnt2<<endl;
                    if(cnt1==0 or cnt2==0) continue;
                    if(cnt1+cnt2>=k)
                    {
                        ll val1=child[x][j-1];
                        ll val2=pr*modInverse(child[x][kk-1],hell);
                        val2%=hell;
                        
                        ll val3=ncr(cnt2+1,k,hell);
                        
                      //  cout<<"BI "<<i<<" "<<j<<" "<<kk<<" "<<x<<" "<<pr<<" "<<val1<<" "<<val2<<" "<<val3<<endl;
                        
                        ans+=(((val1)*(val2))%hell)*(val3)%hell;
                        ans%=hell;
                        //cout<<"hi "<<ans<<endl;
                        // choose 1 from x => child[x][j-1];
                        // product of child[i][kk]/child[x][kk-1] 
                        // total (cnt2+1) c k
                        
                    }
                    
                }
                
                
                
            }
            
        }
        
        
        
        
    }
    
    cout<<ans<<endl;
}

 
int main()
{ 
   decimal(15);
   FAST;
   build();
   ll t;
   t=1;
   cin>>t;  
   for(ll i=1;i<=t;i++)
   solve(i);
   return 0;
}