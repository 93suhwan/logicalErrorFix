#include<bits/stdc++.h> 
#define  ll long long int 
#define  sz(x) (int)(x.size())
#define  slen(s) (int)s.length()
#define  all(x) x.begin(),x.end() 
#define  allb(x) x.begin(),x.begin()+sz(x)
#define  sortalla(x) sort(all(x))
#define  sortalld(x) sort(all(x),greater<int>())
#define  distinct(x) sortalla(x); x.resize(unique(all(x))-x.begin())
#define  ff  first 
#define  ss  second 
#define  pb  push_back
#define  eb  emplace_back 
#define  ppb pop_back 


#define  deb(x) cout <<#x<<" = "<<x<<endl; 
#define  debv1(v){cout<<#v <<" = [ "; for(int i:v){cout<<i<<" ";}cout<<"]"<<endl;}
#define  debc1(c){cout<<#c <<" = { " ; tr(c,i){cout << i << space ;} cout << "}"<< endl; }
#define  debc2(c){cout<<#c <<" = \n" ; tr(c,i){cout << i.ff << space << i.ss << endl; } cout << endl;}

#define  no   cout << "NO" << nline
#define  yes  cout << "YES" << nline
#define  here cout << "here" << nline 
#define  nline "\n"
#define  space " "

#define  present(container, element)(container.find(element) != container.end())

using namespace std; 

#define PI    (acos(-1))
#define MOD   (1e9 + 7)
#define mod   (998244353)
#define pinfl INT64_MAX
#define ninfl INT64_MIN
#define ninf  INT32_MIN
#define ninf  INT32_MIN

#define  v2d(s,row,col,type) vector <vector <type> > s(row,vector <type> (col));  
template<class T > using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T > using max_heap = priority_queue<T, vector<T>, less<T>>;

inline ll MIN(ll x, ll y) {return min(x, y);}
inline ll MAX(ll x , ll y){return max(x,y); }
inline ll GCD(ll x , ll y ){return __gcd(x,y);}

vector<int> z_function(string s) {int n = (int) s.length();vector<int> z(n);for (int i = 1, l = 0, r = 0; i < n; ++i) {if (i <= r)z[i] = min (r - i + 1, z[i - l]);while (i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;}return z;}  

inline ll binpower(ll b, ll p, ll m = MOD ) {b %= m;ll ans = 1;for (; p > 0; p >>= 1) {if (p&1) {ans *= b; ans %= m ;}b *= b;b %= m;}return ans;}
inline ll mod_add(ll a, ll b, ll m = MOD ) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
inline ll mod_mul(ll a, ll b, ll m = MOD ) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
inline ll mod_sub(ll a, ll b, ll m = MOD ) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
inline ll max(ll a, int b) { return (a > b ? a : b); }
inline ll max(int a, ll b) { return (a > b ? a : b); }
inline ll min(ll a, int b) { return (a < b ? a : b); }
inline ll min(int a, ll b) { return (a < b ? a : b); }
inline ll ceil(ll a ,ll b ){return (a+b-1)/b ;}

void init_code(){  

ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif

}
int wally,wallx,rx,ry,cx,cy,ans,dx,dy;
void recurse(){
  if((rx == 1 && dx==-1) || (rx == wallx && dx==1)) dx = -dx;
  if((ry == 1 && dy==-1) || (ry == wally && dy ==1)) dy = -dy;

  if(rx==cx || ry==cy){
    cout << ans << nline;
    return;
  }
  rx = rx + dx;
  ry = ry + dy;  
  ans++;
  recurse();
}
void solve(){
  dx = dy = 1;ans = 0 ;
  cin >> wally >> wallx >> rx >> ry >> cx >> cy;
  recurse() ;
}

int main(){
init_code() ;
cout << fixed << setprecision(10);

 
int t = 1 ; 
cin >> t;
while(t--){
  solve(); 
}

return 0 ; 

}
   





