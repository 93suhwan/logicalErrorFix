/******************************************
* AUTHOR : RATHOD DHAVAL  *
* INSTITUTION : NIT SURAT *
******************************************/

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i,a, n) for(int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define sortall(c) c.begin(),c.end()
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define PI 3.141592653589793238
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define itsval(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); itval(_it, args); }
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
void itval(istream_iterator<string> it) {}
template<typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    itval(++it, args...);
}
const int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {cout << x << "\n";}
template <typename T>
inline void printvec(T x) {for (auto a : x) cout << a << ' '; cout << '\n';}

void solve()
{
  int x,n;
  cin>>x>>n;
  if(n==0){
    cout<<x<<"\n";
    return;
  }
  if(abs(x%2)==1){
    int need=abs(n/2);
    if(need%2==1){
       if(n%2==0){
        cout<<x-1;
       }
       else cout<<x-n-1;
    }
    else {
       if(n%2==0)
        cout<<x+1;
      else cout<<x+n;
    }
  }
  else {
     int need =abs(n/2);
     if(need%2==1){
       if(n%2==0){
         cout<<x+1;
       }
       else cout<<x+n+1;
     }
     else { 
      if(n%2==0)
      cout<<x;
    else cout<<x-n;
     }
  }
  cout<<"\n";
}
 
main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
solve();
 
return 0;
}