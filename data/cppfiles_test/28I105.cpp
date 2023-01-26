#include<bits/stdc++.h>
#define read(arr, n)    vector<int> arr(n); for(int i=0; i<n; i++)  cin >> arr[i];
#define fr(x,s,e)       for(auto x=s-(s>e);x!=e-(s>e);(s<e)?x++:x--)
// #define fr(i, m, n)     for(int i=m;i<n;i++)
#define pii             pair<int, int> 
#define all(x)          x.begin(), x.end()
#define YES             cout<<"YES"<<endl
#define NO              cout<<"NO"<<endl
#define Yes             cout<<"Yes"<<endl
#define No              cout<<"No"<<endl
#define yes             cout<<"yes"<<endl
#define no              cout<<"no"<<endl
#define ub              upper_bound
#define lb              lower_bound
#define umap            unordered_map
#define pb              push_back
#define F               first
#define S               second
#define I               insert
using namespace std;
using namespace std::chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define set_bits __builtin_popcountll
#define decimalPlace(x) cout<<fixed<<setprecision(x);


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
// void file(){
//         fastio;
//         #ifndef ONLINE_JUDGE
//                 // freopen("input.txt", "r", stdin);
//                 // freopen("o1.txt", "w", stdout);
//                 freopen("error.txt", "w", stderr);
//         #endif
// }

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
// template <class T> void _print(T arr[]);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(map <T, V, greater<T>> v);
template <class T> void _print(multiset <T> v);
// template <class T> void _print(T arr[]) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V, greater<T>> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void maxii(int &x, int &y){
      x = max(x, y);
      return;
}

#define vvi(type, n, m, s, name)       vector<vector<type>> name(n, vector<type> (m, s));
#define fbreak(flag) {flag = false; break;}

// #define IM              18446744073709551615
// vector<vector<int>> mat(n, vector<int> (n, 0));
// bool cmp(vector<int> &a, vector<int> &b){
//       if(a[0] < b[0]) return true;
//       if(a[0] == b[0]) return a[1]<b[1];
//       return false;
// }


int _ = 1;
bool bad = 0;
void solve();
void Input();
inline void test_cases();

signed main(){
      ios_base::sync_with_stdio(false); 
      cin.tie(NULL); cout.tie(NULL);
      #ifndef ONLINE_JUDGE
            FILE* inp = freopen("input.txt", "r", stdin);
            FILE* err = freopen("error.txt", "w", stderr);
            FILE* out = freopen("output.txt", "w", stdout);
      #endif
      test_cases();

      auto start = high_resolution_clock::now();
      cout << setprecision(10);
      for(int __=1; __<=_; __++) {
            bad = 0;
            Input();
            solve();
      }
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      #ifndef ONLINE_JUDGE
            cerr << "Time: " << duration.count()/1000.0 << " Millisecond" << endl;
      #endif
}
long long int binPow(long long int x, long long int p, long long int mod) {
      // x : value, p : power, mod : module
      if(p == 1LL) return x%mod;
      if(p == 0LL) return 1%mod;
      if(x == 1LL) return 1%mod;
      if(p&1) {
            return (binPow(x,p-1,mod) * (x%mod)) % mod;
      }
      else {
            long long int temp = binPow(x,p/2,mod);
            return (temp * temp) % mod;
      }
}

void maxii(int &a, int b) {
      a = max(a, b);
}

void minii(int &a, int b) {
      a = min(a, b);
}

bool isPrime(int n){
    if(n<=1)    return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

vector<int> factors(int k) {
      vector<int> p;
      for(int i=1; i*i<=k; i++) {
            if(k%i==0){
                  p.push_back(i);
                  if(i*i != k) p.push_back(k/i);
            }
      }
      return p;
}

const int mod = 1000000007;
const int mm = 998244353;
#define int             ll
#define inf             LLONG_MAX
#define inff            LLONG_MIN
#define IM              INT_MAX
#define Im              INT_MIN
string str;
// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};

const int M = 101;
// vector<vector<char>> mat(M, vector<char>(M));
// vector<vector<bool>> dp(M, vector<bool>(M));
// vector<vector<int>> dp(M, vector<int>(M, -1));
// map<int, vector<int>> g;
// set<int> vis;
// map<int, set<int>> g;
// map<pair<int,int>, int> mp;
// map<int, int, greater<int>> mp;
// map<int, int> mpleft;
// map<int, int> mpright;
// vector<int> cnt(100001);
// vector<int> left;
// vector<int> right;`
// vector<pii> ar;
// vector<int> v;
vector<int> ar;
// vector<int> br;
set<int> st;

int n, m, k, d, ele;

void Input() {
      cin >> n >> m;
      ar.resize(n);
      fr(i,0,n) {
            cin >> ar[i];
            ar[i]--;
      }
}

bool check1(int x) {

      vector<int> arr(n);
      for(int i=0; i<n; i++) {
            int t = (i+x)%n;
            arr[i] = ar[t];
      }

      vector<int> v(n);
      for(int i=0; i<n; i++) {
            v[arr[i]] = i;
      }

      int cnt = 0;
      bool flag = false;
      for(int i=0; i<n; i++) {
            if(i-arr[i]==0) continue;
            // arr[i] = i;
            arr[v[i]] = arr[i];
            cnt++;
      }

      return (m >= cnt);
}

void solve() {

      map<int,int> mp;
      fr(i,0,n) {
            mp[(i-ar[i] + n)%n]++;
      }

      set<int> v;
      int k = -1;
      pair<int,int> p;
      for(auto it : mp) {
            int x = it.F;
            if(x>=0) {
                  if(it.S >= (n+2)/3) {
                        if(check1(it.F)) 
                              v.I(it.F);
                  }
            }
      }

      cout << v.size() << "  ";
      for(int x : v) cout << x << " ";
            cout << endl;

}

inline void test_cases() {
      cin >> _;
}