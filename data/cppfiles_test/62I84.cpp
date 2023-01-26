#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define pb push_back
#define show(x) cout<<#x<<" : "<<x<<endl;
#define gcd __gcd
#define int long long
#define ff  first
#define ss  second
#define mp make_pair
#define inf INT_MAX
#define lb lower_bound
#define ub upper_bound
#define vec vector<int>
#define mapint map<int,int>
#define mapchar map<char,int>
#define maplist map<int,vec>
#define sum accumulate
#define setitr set<int>::iterator
#define mapitr map<int,int>::iterator
#define pii pair<int,int>
const int pri1 =pow(10,9)+7;
 
 
bool find(vector<int>&v,int val){ auto it=find(v.begin(),v.end(),val);  if(it!=v.end()) return true; else return false;}
bool find(set<int>&v,int val) { auto it=find(v.begin(),v.end(),val); if(it!=v.end()) return true; else return false; }
int freq(vector<int>&v,int val) {return count(v.begin(),v.end(),val);}
int power(int x,int y,int p ) { int res=1; x%=p; while(y>0) { if(y&1) res=(res*x)%p; y=y>>1; x=(x*x)%p; } return res; }
int modi(int x) { return power(x,pri1-2,pri1); }
int lcm(int x,int y) { return ((x*y)/(gcd(x,y))); }
int find_sorted(vector<int>&v,int value) { auto it=lb(v.begin(),v.end(),value); if(it-v.begin()==v.size())  { return -1; }  else  return it-v.begin(); }
int ncr(int n,int r,vector<int>&fact) {  return (((fact[n]*modi(fact[r]))%pri1)*((modi(fact[n-r]))%pri1)%pri1); }
int first_pos(vector<int>&v,int val) { for(int i=0;i<v.size();i++) if(v[i]==val) return i; return -1; }
string binary(int n) { string s; while(n) { s+='0'+n%2; n=n/2; } reverse(s.begin(),s.end()); return s; }
 
void input(vector<int> &a,int n){  a.resize(n); for(int i=0;i<n;i++) cin>>a[i]; }
void output(vector<int> &v) { for(auto it:v) cout<<it<<" " ;}
void factor(int n,vector<int>&v) { for(int i=1;i*i<=n;i++) { if(n%i==0 and n/i==i) v.pb(i); else if(n%i==0 and n/i!=i) { v.pb(i); v.pb(n/i); } }}
void sieve(int n,vector<int>&prime) { int p=2;  while(p*p<=n){ if(prime[p]) { for(int i=p*p;i<n+1;i+=p)  prime[i]=0;  }   p+=1; } }
void str_vec(string &s,vector<int>&v) { for(int i=0;i<s.size();i++)  v.pb(s[i]-'0'); }
void vec_str(string &s,vector<int>&v) { for(int i=0;i<v.size();i++)  s+=to_string(v[i]); }
void eraser(vector<int>&v,int val) { for(int i=0;i<v.size();i++) { if(v[i]==val)  { v.erase(v.begin()+i); return; } } }
int unique(vector<int>&v) { set<int>s; for(int i=0;i<v.size();i++) s.insert(v[i]); return s.size(); }
// ##################################################################################################################################
 
/*
tree functions  - input, subtree size solver , parent finder , distance solver
*/
int n;
vec dis(100005,0);
int sparse[100005][20];
void tree_input(int n,vec m[]) { int e=n-1; int x,y;  while(e) {  cin>>x>>y;  m[x].pb(y);  m[y].pb(x);e-=1; } }
void subtre(mapint &subtree,vec &visited,int node,maplist &m) { visited[node]=1; subtree[node]+=1; for(auto it:m[node]) { if(visited[it]==0) { subtre(subtree,visited,it,m); subtree[node]+=subtree[it]; } } }
void parent(vec &pr,int node,vec &visited,vec m[]) { visited[node]=1; for(auto it:m[node]) { if(visited[it]==0) { pr[it]=node; parent(pr,it,visited,m); } } }
void distance(vec &visited,int node,vec m[],vec &dis) { visited[node]=1; for(auto it:m[node]) { if(visited[it]==0) { visited[it]=1; dis[it]=dis[node]+1; distance(visited,it,m,dis); } } }
                    
//##########################################################################################################################i
int matrix[1000][1000][2];
int m1[1000][1000];
// int as[2132][123];
int m2[1000][1000];
 
int solver(int x,int i,int j,int n,int m) {

    if(i>=n or j>=m) return 0;

    if(matrix[i][j][x]!=0) return matrix[i][j][x];

    if(x==0) {
      matrix[i][j][x]=solver(1,i+1,j,n,m)+1;
    }
    else {
      matrix[i][j][x]=solver(0,i,j+1,n,m)+1;
    }

    return matrix[i][j][x];
  


}
 

 

void solve() {  
 
  int n,m,q;
  cin>>n>>m>>q;
  
  // memset(as,-1,sizeof(as));
  int matrix[1000][1000][2];
int m1[1000][1000];
// int as[2132][123];
int m2[1000][1000];


  int total=0;
 
  
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
     
      int t1=0;
      if(matrix[i][j][0]!=0) { t1+=matrix[i][j][0];}
      else {
        t1+=solver(0,i,j,n,m);
      }
      if(matrix[i][j][1]!=0) {
        t1+=matrix[i][j][1];

      }

      else {
        t1+=solver(1,i,j,n,m);
      }
   
      total+=t1-1;

    }
  }


  for(int i=0;i<q;i++) {

    int x,y;
    cin>>x>>y;
   
    int cnt=1;
    int mnt=1;
    int rnt=1;
    x-=1;y-=1;
    int g=x;
    int r=y;
    int dnt=1;
    while(x>=0 and y>=0) {
      x-=1;
      if(x<0 or m1[x][y]==1) break;
      cnt+=1;
      y-=1;
      if(y<0 or m1[x][y]==1) break;
   
      cnt+=1;
    }
    x=g;
    y=r;

     while(x>=0 and y>=0) {
      y-=1;
      if(y<0 or m1[x][y]==1) break;
      mnt+=1;
      x-=1;
      if(x<0 or m1[x][y]==1) break;
      
      mnt+=1;
    }
    
    x=g;
    y=r;
     while(x<n and y<m) {
      x+=1;
      if(x>=n or m1[x][y]==1) break;
      rnt+=1;
      y+=1;
      if(y>=m or m1[x][y]==1) break;
    
      rnt+=1;
    }
    x=g;
    y=r;
     while(x<n and y<m) {
      y+=1;
      if(y>=m or m1[x][y]==1) break;
      dnt+=1;
      x+=1;
      if(x>=n or m1[x][y]==1) break;
      dnt+=1;
    }

    x=g;
    y=r;
   
    

    int t1=(cnt*dnt)+(rnt*mnt)-1;
    if(m1[x][y]==1) {
      total+=t1;
      cout<<total<<endl;
      m1[x][y]=0;
    }

    else {
      total-=t1;
      cout<<total<<endl;
      m1[x][y]=1;
    }

  }

  
}
 
    
 
    
 
 
 
 
     
 
 
  
 
  
//############################################################################################################################
signed main() {
    int tt=1;
    fastio();
 
   // cin>>tt;
                                                                        
    while(tt--){
    solve();
    }
    return 0;
}