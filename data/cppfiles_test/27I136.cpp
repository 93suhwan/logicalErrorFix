#include<bits//stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(v) v.begin(),v.end()
#define pb push_back
#define mk make_pair
#define pii pair<int,int> 
#define vi vector<int> 
#define maxe *max_element
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define umap unordered_map

vector<int> g(1000001,0);
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void seive()
{
  g[1]=1;
  for(int i=2;i*i<=1000000;i++)
  {
    if(g[i]==0)
    {
    for(int j=i*i;j<1000000;j=j+i)
    {
      g[j]=1;
    }
    }
  }
}
int modpow(int x, int n, int m) 
{
   if (n == 0) return 1%m;
   int u = modpow(x,n/2,m);
   u = (u*u)%m;
   if (n%2 == 1) u = (u*x)%m;
   return u;
}
bool checkifbalanced(string expr) 
{   
    stack<char> s; 
    char x; 
   
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')  
        { 
            s.push(expr[i]); 
            continue; 
        }  
        if (s.empty()) 
            return false; 
  
        switch (expr[i]) { 
        case ')': 
              
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
   
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 

            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    } 
    return (s.empty()); 
} 
int check(int n)
{
  int flag=0;
  for(int i=0;i*i<n;i++)
  {
    if(i*i==n)
    {
      flag=1;
      break;
    }
  }
  if(flag==1)return 1;
  else return 0;
}
int mandist(int x,int i,int y,int j)
{
  return abs(x-i)+abs(y-j);
}
int cnt=0;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n%2 != 0)
            return 0;
        n = n/2;
    }
    return 1;
}
bool isapal(string s)
{
  int n=s.length();
  int flag=0;
  for(int i=0;i<n/2;i++)
  {
    if(s[i]!=s[n-i-1])
    {
      flag=1;
    }
  }
  if(flag==0)return true;
  else return false;
}
int numofdig(int n)
{
  int c=0;
  while(n!=0)
  {
    c++;
    n=n/10;
  }
  return c;
}
vi vis(2000,0);
int arr[105][105];
int c=2;
void fibo()
{
  
  vi v(100000,0);
  int i=2;
  v[0]=0;
  v[1]=1;
  while(1)
  {
    v[i]=v[i-1]+v[i-2];
    if(v[i]>1e9)
    {
      break;
    }
    c++;
    i++;
  }
}
int _pow(int a, int b)
{
   if(!b)return 1;
   ll temp = _pow(a, b/2);
   temp = (temp * temp);
   if(b%2)return (a * temp);
   return temp;
}
bool isInteger(double n)
{
 
    
    int X = n;
 
    double temp2 = n - X;
 
    
    if (temp2 > 0) {
        return false;
    }
    return true;
}
const int N=100005;
vector<vi> A(2,vi(2e5+5));
int dp[2][N];
vector<vi> adj(2000);
int d=0;
void dfs(int u)
{
  vis[u]=1;
  for(auto v:adj[u])
  {
    if(vis[v]==0)
    {
      d++;
      dfs(v);
    }

  }
}
bool isPower(int x, int y)
{
    // logarithm function to calculate value
    int res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
int lcm(int a,int b)
{
  return (a*b)/__gcd(a,b);
}
int ciel(int a,int b)
{
  if(a%b==0)
  {
    return a/b;
  }
  else
  {
    return (a/b)+1;
  }
}
bool chk(vector<int>& a)
{
  int n=a.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        if((a[i]<=a[j] && a[j]<=a[k]) || a[i]>=a[j] && a[j]>=a[k])
        {
          return true;
        }
      }
    }
  }
  return false;
}



void solve()
{
  string s,t;
  cin>>s>>t;
  int n=s.length();
  int m=t.length();
  if(m>n || t[m-1]!=s[n-1])
  {
    cout<<"NO"<<endl;
    return ;
  }

  int j=n-1;
  int i=m-1;
  int c=0;
  vector<int> v;
  while(i>=0 && j>=0)
  {
    if(s[j]==t[i])
    {
      j--;
      i--;
      v.pb(j);
      c++;
    }
    else
    {
      j--;
    }
  }
  if(c!=m)
  {
    cout<<"NO"<<endl;
    return ;
  }
  for(int i=1;i<v.size();i++)
  {
    if(v[i]-v[i-1]==1)continue;
    else
    {
      if((v[i]-v[i-1])%2==0)
      {
        cout<<"NO"<<endl;
        return ;
      }
    }
  }
  cout<<"YES"<<endl;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin>>tt;
  int t=1;
  while(tt--)
  {
    solve();
  }
  return 0;
  
}