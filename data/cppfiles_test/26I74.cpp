#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define check(x)  cerr << #x << ": " << x << endl;
ll isPrime(ll n) {
   ll i;
   for(i=2; i*i<=n; ++i) {
      if(n%i==0) {
        
         
         return 0;
      }
   }
   return 1;
  
}
ll findFactor(int n)
{
   int a=0;
   for(int i=3;i<=n;i=i+2)
   {
      
      
      if(n%i==0)
         {
            a=n/i;
            break;
         }
      
   }
   return a;
}
vector<int> factors(int n)
{
    vector<int> s;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i != 0) 
         {
            continue;
         }
        s.push_back(i);
        while(n % i == 0) n /= i;
    }
    if(n != 1) s.push_back(n);
    return s;
}
void adjacencym()
{
 int n,m;
 cin>>n>>m;
 int adjacencymatrix[n+1][n+1]={0};
 for(int i=0;i<m;i++)
 {
   int u,v;
   cin>>u>>v;
   adjacencymatrix[u][v]=1;
   adjacencymatrix[v][u]=1;

}
for(int i=0;i<n;i++)
{
   for(int j=0;j<n;j++)
      cout<<adjacencymatrix[i][j]<<" ";
   cout<<"\n";
}
}
void adjacencylistbfs()
{
   int n,m;
   cin>>n>>m;
   vector<int> adjacencyl[n+1];
   for(int i=0;i<m;i++)
   {
      int u,v;
      cin>>u>>v;
      adjacencyl[u].push_back(v);
      adjacencyl[v].push_back(u);
   }
    vector<bool>vis(n+1,0);
    vector<int>bfs1;
   for(int i=1;i<=n;i++)
   {
      if(vis[i]==1)
         continue;
      queue<int>bfs;
      vis[i]=1;
      bfs.push(i);
      while(bfs.size())
      {
         int current_node=bfs.front();
         bfs1.push_back(current_node);
         bfs.pop();
         for(int child:adjacencyl[current_node])
         {
            if(vis[child])
               continue;
            bfs.push(child);
            vis[child]=1;
         }
      }
   }
   for(auto i:bfs1)
      cout<<i<<" ";
  
}
void dfs(int curr , vector <int> &vis , vector <int> nodes[]){
  vis[curr] = 1;
  for(int child : nodes[curr]){
    if(vis[child])
      continue;
    dfs(child , vis , nodes);
  }
  
}
void adjacencyldfs()
{
   int n,m;
   cin>>n>>m;
   vector<int> nodes[n+1];
   for(int i=0;i<m;i++)
   {
      int u,v;
      cin>>u>>v;
      nodes[u].push_back(v);
      nodes[v].push_back(u);
   }
  vector <int> vis(n+1 , 0);
  dfs(1 , vis , nodes);


}

void solve()
{
        int n;
        cin>>n;
        long long int ans=1;
        for(int i=2;i<=2*n;i++)
        {
            ans=(ans*i)%mod;
        }
        ans=ans%mod;
        cout<<ans/2<<endl;





}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sync;
   
    int t = 1;
    cin >> t;
   
    while(t--) solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;    
}