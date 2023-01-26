#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ppb pop_back
//#define mp make_pair
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define mod 1000000007
#define mod1 998244353
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define vd(x) vector <x>
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define nline "\n"
#define INF 1e18
#define ppi pair<int,int>
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

/***************************Seive***********************************************/
long long int P = 20010;//till 5e7 works fine
vector<bool> is_prime(P + 1, true);
vector<ll> prime;
void seive()
{ is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= P; i++) {
    if (is_prime[i] && (unsigned long long int)i * i <= P) {
      for (ll j = i * i; j <= P; j += i)
        is_prime[j] = false;
    }
  }
  for (ll i = 2; i < P; i++)
  { if (is_prime[i])
      prime.push_back(i);
  }
}
/*******************************************************************************/
/***************************Modular Exponenetiation*****************************/
long long modexp(long long x, long long y, ll p)
{ long long res = 1; x = x % p;
  if (x == 0)
  { if (y == 0) return 1;
    else return 0;
  }
  while (y > 0)
  { if (y & 1) res = (res * x) % p;
    y = y >> 1; x = (x * x) % p;
  }
  return res;
}
/*******************************************************************************/
/***************************Mod inverse*****************************/
/*m is prime use modexp(x,m-2,m)*/

ll gcdExtended(ll a, ll b, ll* X, ll* Y)
{ if (a == 0) {
    *X = 0, *Y = 1; return b;
  }
  ll x1, y1; ll gcd = gcdExtended(b % a, a, &x1, &y1);
  *X = y1 - (b / a) * x1; *Y = x1; return gcd;
}
ll modInverse(ll a, ll m) {
  ll X, Y; ll g = gcdExtended(a, m, &X, &Y); ll res = (X % m + m) % m;
  return res;
}
/*******************************************************************************/
/***************************BFS*****************************/
// to activate this first traverse through all nodes in solve()
//  whenever vis is!=1 call bfs
vector <int> storebfs;
void bfs(int i, vector <int> &vis, vector <int> adj[]) {
  queue<int> q;
  q.push(i); vis[i] = 1;
  while (!q.empty()) {
    int node = q.front(); q.pop(); storebfs.pb(node);
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        q.push(it); vis[it] = 1;
      }
    }
  }
}
/*******************************************************************************/
/***************************DFS*****************************/
// to activate this first traverse through all nodes in solve()
//  whenever vis is!=1 call dfs
vector <int> storedfs;
void dfs(int node, int parent, vector <int> &vis, vector <int> adj[]) {
  storedfs.pb(node); vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, node, vis, adj);
    }
  }

}
/*******************************************************************************/
//int dp[2005][2005];
// char alf[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',

//                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
//                };



const ll inf = 1e9 + 5;
//ll dp[300005][3];





void solve()
{
  ll n, k;
  cin >> n >> k;
  ll sol = 0;
  vector <ll> v1(n);
  rep(i, n) cin >> v1[i];
  k++;
  for (ll i = 0; i < n - 1; i++)
  {
    if (k > 0)
    {
      ll num1 = pow(10, v1[i + 1] - v1[i]) - 1;
      ll val2 = min(num1, k);

      sol += pow(10, v1[i]) * val2;

      k -= val2;
    }
  }
  sol += (k) * pow(10, v1[n - 1]);
  cout << sol << '\n';

}










int main() {
#ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
#endif
  fastio();
  auto start1 = high_resolution_clock::now();
  //seive();
  int T; T = 1;
  cin >> T;
  rep(tc, T) {
    debug(tc);
    //cout << "Case #" << tc + 1 << ":" << " ";
    //debug(tc);
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
  cerr << "Time: " << duration . count() / 1000 << endl;
#endif
  return 0;
}