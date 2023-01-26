#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma optimize("jillzay, jillzay, paci, paci, gilzi, gilzi")
#pragma optimize("JARU SOSISONI")
 
using namespace __gnu_pbds;
using namespace std;
 
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e;} return in;}
template <class T>
istream& operator >> (istream& in, pair<T, T> &v){ in >> v.first >> v.second; return in;}
 
#define int long long
//#define int short int
#define pb push_back
#define mkp make_pair
#define X first
#define Y second
#define cont continue
#define For(i, a, b) for (int i = a; i < b;++i)
#define forn(i, a) for (int i = 0;i < a;++i)
#define ford(i, a, b) for (int i = b - 1;i >= a;--i)
#define fordn(i, a) for (int i = a - 1;i >= 0;--i)
#define forr(x, arr) for(auto &x: arr)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
void debug_out(){ cout << '\n';}

template<typename head, typename... tail>
void debug_out(head H, tail... T){ cout << " " << H; debug_out(T...);}

#ifdef KULA
    #define deb(...) cout << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const vector<T>& v){ out << "[";for(int i = 0;i < v.size();i++){out << v[i];if (i != v.size() - 1) out << " ";} out << "]"; return out; }
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const pair<T, T>& v){ out << "[";out << v.first << ", " << v.second;out << "]"; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const set<T>& v){out << "["; for(auto i = v.begin();i != v.end();i++){ out << *i; if (*i != *v.rbegin()) out << ", ";} out << "]"; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const multiset<T>& v){out << "["; for(auto i = v.begin();i != v.end();i++){ out << *i; if (*i != *v.rbegin()) out << ", ";} out << "]"; return out;}
#else
    #define deb(...)
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const vector<T>& v){ for(auto& e : v){ out << e << d;} return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const pair<T, T> & v){ out << v.X << d << v.Y; return out;}
    template <char d = ' ', class T>
    ostream& operator << (ostream& out, const set<T>& v){ for(auto& e : v){ out << e << d;} return out;}
#endif
typedef long long ll;
typedef long double ldd;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<pii> spii;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename T> T sqr(T a) {return a * a;}
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
//const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
//const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
//const int dx[8] = {-2, -2, 1, 1, -1, -1, 2, 2};
//const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const ldd EPS = 1e-12;
const int MOD = 1e9 + 7;
const ldd PI = acos(-1.);
/*const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
  return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }*/
int dp[1001][1001][2];
int n, m;
int vse = 0;
int a[1001][1001];
int go(int x, int y, int type){
  if (x >= n || y >= m) return 0;
  if (dp[x][y][type]) return dp[x][y][type];
  int &ans = dp[x][y][type] = 0;
  if (a[x][y] == 1) return ans;
  if (type) ans = go(x, y + 1, type ^ 1) + 1;
  else ans = go(x + 1, y, type ^ 1) + 1;
  return ans;
}

void go_remove(int x, int y, int type, int val){
  if (x < 0 || y < 0) return;
  uin(val, dp[x][y][type]);
  dp[x][y][type] -= val;
  vse -= val;
  if (val == 0) return;
  if (type) go_remove(x - 1, y, type ^ 1, val);
  else go_remove(x, y - 1, type ^ 1, val);
}

void go_add(int x, int y, int type){
  if (x < 0 || y < 0) return;
  if (a[x][y] == 1) return;
  int was = dp[x][y][type];
  if (type && y + 1 < m){
    dp[x][y][type] = dp[x][y + 1][type ^ 1] + 1;
  } else if (type == 0 && x + 1 < n) {
    dp[x][y][type] = dp[x + 1][y][type ^ 1] + 1;
  }
  vse += dp[x][y][type] - was;
  if (type) go_add(x - 1, y, 0);
  else go_add(x, y - 1, 1);
}

void solve(){
  
  cin >> n >> m;
  
  forn(type, 2) forn(i, n) forn(j, m){
    vse += go(i, j, type);
  }
  int cells = n * m;
  
  int q;
  cin >> q;
  while(q--){
    int x, y;
    cin >> x >> y;
    x-- ,--y;
    if (a[x][y] == 0){
      go_remove(x, y, 0, dp[x][y][0]);
      go_remove(x, y, 1, dp[x][y][1]);
      cells--;
    } else {
      a[x][y] = 0;
      go_add(x, y, 0);
      go_add(x, y, 1);
      a[x][y] = 1;
      cells++;
    }
    a[x][y] ^= 1;
    cout << vse - cells << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef KULA
//            freopen("input.txt", "r", stdin);
//            freopen("output.txt", "w", stdout);
  #else
//            freopen("input.txt", "r", stdin);
//            freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  forn(i, t) solve();
  return 0;
}
//g++ -std=c++17 -Wall -Wextra -Weffc++ -O3 -DKULA=1 -o a main.cpp