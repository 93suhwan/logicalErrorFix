//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FIO ios_base::sync_with_stdio(false); cin.tie(0);
#define trav(x,a) for (auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define case(t) cout << "Case #" << (t) << ": "
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 998244353;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const ld eps = 1e-9;

template<class T> void read(T& x) { cin >> x; }
template<class X, class Y> void read(pair<X,Y>& a) { read(a.first), read(a.second); }
template<class T, size_t U> void read(array<T,U>& x) { for (int i = 0; i < U; i++) read(x[i]); }
template<class T> void read(vector<T>& x) { trav(y, x) read(y); }
template<class T, class... O> void read(T& x, O&... y) { read(x), read(y...); }

string to_string(const char& x) { return string(1,x); }
string to_string(const char*& x) { return (string)x; }
string to_string(const string& x) { return x; }
template<class T, class U> string to_string(const pair<T,U>& x) { return to_string(x.first) + " " + to_string(x.second); }
template<class T, size_t U> string to_string(const array<T,U>& x) { string ret = ""; for (int i = 0; i < U; i++) ret += (!i ? "" : " ") + to_string(x[i]); return ret; }
template<class T> string to_string(const vector<T>& x) { string ret = ""; bool f = 0; trav(y, x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
template<class T> string to_string(const set<T>& x) { string ret = ""; bool f = 0; trav(y, x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
void print() { cout << endl; }
template<class T> void pr(const T& x) { cout << to_string(x); }
template<class T, class... O> void print(const T& x, const O&... y) { pr(x); if (sizeof...(y)) pr(" "); print(y...); }

int inv[N], ifac[N], fac[N];

inline int add(int x, int y) { return x+y < mod ? x+y : x+y-mod; }
inline int sub(int x, int y) { return x-y >= 0 ? x-y : x-y+mod; }
inline int mul(int x, int y) { return x * 1ll * y % mod; }
template<class T, class... O> inline int add(T x, O... y) { return add(x, add(y...)); }
template<class T, class... O> inline int mul(T x, O... y) { return mul(x, mul(y...)); }
inline int norm(int x) { return x >= 0 ? (x < mod ? x : x-mod) : x+mod; }
inline int pw(int x, int y) {
  int r = 1;
  for (; y; x = mul(x, x), y /= 2)
    if (y & 1)
      r = mul(r, x);
  return r;
}
inline int inverse(int x) { return pw(x, mod-2); }
inline int ncr(int n, int k) {
  if (n < k || k < 0) return 0;
  if (n < N) return mul(fac[n], ifac[n-k], ifac[k]);
  int r = 1;
  for (int i = 1; i <= k; i++)
    r = mul(r, n-i+1, inv[i]);
  return r;
}

void precomputeInverse(int n) {
  inv[1] = ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
  for (int i = 2; i < n; i++) {
    inv[i] = mod - mul(mod / i, inv[mod % i]);
    fac[i] = mul(fac[i-1], i);
    ifac[i] = mul(ifac[i-1], inv[i]);
  }
}

int ar[40], br[40];
map<int,vector<int>> sm;
vector<int> tt = {1, 2, 3, 5, 9, 17};
vector<int> ct = {1, 1, 2, 4, 8, 16};
int val = 0;
vector<int> cur;

void dfs(int k) {
  if (k < 0) {
    sm[val] = cur;
    return;
  }
  for (int i = 0; i <= ct[k]; i++) {
    dfs(k - 1);
    val = add(val, br[tt[k]]);
    cur.push_back(tt[k]);
  }
  for (int i = 0; i <= ct[k]; i++)
    cur.pop_back();
}

int main() {
  FIO
  int k, a, h; read(k, a, h);
  if (k == 1) {
    if (add(pw(a, 1), mul(2, pw(a, 2))) == h)
      print(1, 2);
    else if (add(pw(a, 2), mul(2, pw(a, 1))) == h)
      print(2, 1);
    else
      print(-1);
    return 0;
  }

  ar[0] = 1;
  for (int i = 1; i < 40; i++)
    ar[i] = mul(ar[i - 1], a);
  for (int i = 0; i < 40; i++)
    br[i] = sub(ar[(1 << k - 1) + 1], ar[i]);
  dfs(k - 1);


  auto calc = [&](vector<int>& p) {
    int r = 0;
    for (int i = 0; i < sz(p); i++)
      r = add(r, mul(i + 1, ar[p[i]]));
    return r;
  };


  int s = 0;
  for (int i = k - 1; i > 0; i--)
    s += 1 << i - 1;
  for (int i = 0; i < 1 << s; i++) {
    vector<int> p(1 << k);
    vector<int> a;
    int v = 1 << k - 1;
    for (int j = 0; j < 1 << k; j += 2) {
      p[j] = v + 1;
      a.push_back(j + 1);
    }
    int j = 0;
    while (sz(a) > 1) {
      v /= 2;
      vector<int> b;
      for (int jj = 0; jj < sz(a); jj += 2, j++) {
        if (i >> j & 1)
          p[a[jj]] = v + 1, b.push_back(a[jj + 1]);
        else
          p[a[jj + 1]] = v + 1, b.push_back(a[jj]);
      }
      a = b;
    }
    p[a[0]] = 1;
    v = calc(p);
    if (sm.count(sub(h, v))) {
      vector<int> ar = sm[sub(h, v)];
      for (int o: ar) {
        for (int j = 0; j < 1 << k; j++)
          if (p[j] == o) {
            swap(p[j], p[j - 1]);
            break;
          }
      }
      int uuu = calc(p);
      assert(uuu == h);
      print(p);
      return 0;
    }
  }
  print(-1);
}
