    
#include<bits/stdc++.h>
using namespace std;
 
#define ar array<int, 2>
#define int long long
#define in insert
#define pb push_back
#define pii pair<int,int>
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(int i = 0; i < n; i++)
#define Rev(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REV(i, n) for(int i = n; i >= 1; i--)
#define Rep(i,a,b) for(int i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
 
// Maximum priority queue
template <typename T>
using mxpq = priority_queue<T>;
 
// Minimum priority queue
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;
 
 
// x | (x + 1) sets lowest unset bit of x
// x & (x - 1) unsets lowest set bit of x
 
const int mod = 1e12L + 7;
const int INF = 1e18L + 5;
const int mxN = 2e5 + 1;
 
/*
   Function in main.
  auto Ask=[&](int v)
    {
      
    };
 
    In vector-> lower_bound(all(),number);
    In set-> set.lower_bound(number);
*/
//auto align ctrl+alt+f.
// remember to read no of test_cases
// Think thrice before writing code.
void solve()
{
  int n;
  cin>>n;
  vt<int> v(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  
 int number=1;
 int k=14;
 for(int i=0;i<=min(k,n-1);i++)
 { 
    number*=(i+2);
     if(__gcd(number,v[i])==number)
     {
       cout<<"NO"<<endl;
       return;
     }
 }
   cout<<"YES"<<endl;
  return;
}
 
signed main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int t = 1;
   cin >> t;
  FOR(tt, t) solve();
  return 0;
}