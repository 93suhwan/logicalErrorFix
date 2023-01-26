#include <bits/stdc++.h>
#include<iostream>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
dfs(int i,int j,vector<vector<ll>>&grid,vector<vector<int>>&visited,ll &count)
{
    ll m=grid.size(),n=grid[0].size();
    ll num=grid[i][j];
    visited[i][j]=1;
    count++;
    if( (num & (1<<3))==0 && i-1>=0 && (grid[i-1][j] & (1<<1))==0 && visited[i-1][j]==0)dfs(i-1,j,grid,visited,count);
    if( (num & (1<<2))==0 && j+1<n && (grid[i][j+1] & (1<<0))==0 && visited[i][j+1]==0)dfs(i,j+1,grid,visited,count);
    if( (num & (1<<1))==0 && i+1<m && (grid[i+1][j] & (1<<3))==0 && visited[i+1][j]==0)dfs(i+1,j,grid,visited,count);
    if( (num & (1<<0))==0 && j-1>=0 && (grid[i][j-1] & (1<<2))==0 && visited[i][j-1]==0)dfs(i,j-1,grid,visited,count);
}
void solve() {
   ll n,m;
   cin>>m;
   cin>>n;
   vector<vector<ll>>grid(m,vector<ll>(n,0));
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>grid[i][j];
       }
   }
   vector<vector<int>>visited(m,vector<int>(n,0));
   vector<int>ans;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(visited[i][j]==0)
           {
               ll count=0;
               dfs(i,j,grid,visited,count);
              // cout<<i<<" "<<j<<" "<<count<<endl;
               ans.push_back(count);
           }
       }
   }
   sort(ans.begin(),ans.end());
   reverse(ans.begin(),ans.end());
   for(auto &p:ans)cout<<p<<" ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}