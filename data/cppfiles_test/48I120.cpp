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
#define INF             +2e+18
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


void bridgeUtil(int u, bool visited[], int disc[],int low[], int parent[])
{
    // A static variable is used for simplicity, we can
    // avoid use of static variable by passing a pointer.

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++tt;

    for (ll v:g[u])
    {
        
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);

            // Check if the subtree rooted with v has a
            // connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree
            // under v is below u in DFS tree, then u-v
            // is a bridge
            if (low[v] > disc[u])
            {
                b=1;
                cout << u <<" " << v << endl;
            }
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

// DFS based function to find all bridges. It uses recursive
// function bridgeUtil()
void bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[n+1];
    int *disc = new int[n+1];
    int *low = new int[n+1];
    int *parent = new int[n+1];

    // Initialize parent and visited arrays
    for (int i = 1; i <=n; i++)
    {
        parent[i] = 0;
    }

    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 1; i <=n; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}


*/




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
 
 
ll k; 
ll fun(vi v)
{
    ll ans=0;
    ll n=v.size();
    ll curr=n;
    
    while(curr>0)
    {
        if(curr-k<=0)
        {
            ans+=2*v[curr-1];
            break;
        }
        else
        {
            ans+=2*v[curr-1];
            curr-=k;
        }
        //cout<<curr<<" "<<ans<<endl;
    }
    return ans;
}

 
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
 
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) 
    {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
 
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

void solve(ll nn)
{
    ll n;
    cin>>n;
    int a[n];
    ll b[n];
    fr(n)  
    {
        cin>>a[i];
    //    b[i]=a[i];
    }
    
    ll ans=mergeSort(a,n);
    //cout<<ans<<" ";
    if(ans%2==0)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
    
    return ;
}

 
int main()
{ 
   decimal(15);
   FAST;
   
   //build();
   ll t;
   t=1;
   cin>>t;  
   for(ll i=1;i<=t;i++)
   solve(i);
   return 0;
}