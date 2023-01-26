#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma comment(linker, "/stack:200000000")
long long beki(long long i) { return 1ll << i; }
const long long INF = (1LL << 61) - 1;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long MAX_N1 = 200010;
const long long MAX_N2 = 500010;
template <class X>
void print(X x) {
  cout << x << "\n";
}
void print(vector<long long> x) {
  for (long long i : x) {
    cout << i << " ";
  }
  cout << "\n";
}
void print(vector<pair<long long, long long> > x) {
  for (pair<long long, long long> i : x) {
    cout << i.first << " " << i.second << "\n";
  }
  cout << "\n";
}
template <class X>
void printr(X x) {
  cerr << x << "\n";
}
void printr(vector<long long> x) {
  for (long long i : x) {
    cerr << i << " ";
  }
  cerr << "\n";
}
void printr(vector<pair<long long, long long> > x) {
  for (pair<long long, long long> i : x) {
    cerr << i.first << " " << i.second << "\n";
  }
  cout << "\n";
}
template <class X>
int lbound(vector<X> &Y, X a) {
  return lower_bound(Y.begin(), Y.end(), a) - Y.begin();
}
template <class X>
int ubound(vector<X> &Y, X a) {
  return upper_bound(Y.begin(), Y.end(), a) - Y.begin();
}
template <class X>
X lbound2(vector<X> &Y, X a, int mode = 0) {
  int x = lbound(Y, a) - mode;
  if (x < 0 || x >= Y.size()) return INF;
  return Y[x];
}
template <class X>
X ubound2(vector<X> &Y, X a, int mode = 0) {
  int x = ubound(Y, a) - mode;
  if (x < 0 || x >= Y.size()) return INF;
  return Y[x];
}
template <class... T>
void cl(T &...t) {
  (..., (t.clear()));
}
template <class... T>
void in(T &...t) {
  (..., (cin >> t));
}
template <class... T>
void put(vector<long long> &V, int n, int mode = 0) {
  long long k;
  if (mode == 0) cl(V);
  for (long long i = 0; i < n; ++i) {
    cin >> k;
    V.push_back(k);
  }
}
int max_index(vector<long long> &V) {
  return max_element(V.begin(), V.end()) - V.begin();
}
int min_index(vector<long long> &V) {
  return min_element(V.begin(), V.end()) - V.begin();
}
long long sum(vector<long long> &V) {
  return accumulate(V.begin(), V.end(), 0ll);
}
template <typename T>
void UNIQUE(vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <typename T>
T ADD(T a, T b) {
  T res;
  return __builtin_add_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
}
template <typename T>
T MUL(T a, T b) {
  T res;
  return __builtin_mul_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
};
template <typename T>
T POW(T a, int n) {
  T res = 1;
  for (; n > 0; n >>= 1, a *= a)
    if (n & 1) res *= a;
  return res;
}
template <class X>
bool ma(X &a, X b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class X>
bool mi(X &a, X b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void vset(vector<long long> &A, long long n, long long k) {
  A = vector<long long>(n, k);
}
void so(vector<long long> &A) { sort(A.begin(), A.end()); }
long long age(long long x, long long y) { return (x + y - 1) / y; }
long long a, b, c, d, aa, bb, cc, dd, h, x, y, z, p, q, n, t, r, k, w, l, ans,
    m, u, v;
long long codeforces = 1;
string S, T, U;
vector<long long> A, B, C, D;
vector<long long> g[MAX_N2];
vector<pair<long long, long long> > VP, VP2;
set<long long> s1, s2;
void solve() {
  int qq;
  in(n, qq);
  in(S);
  map<long long, vector<long long> > M;
  p = 0;
  q = 0;
  M[p].push_back(q);
  A.push_back(q);
  for (long long i = 0; i < n; ++i) {
    if (S[i] == '+')
      x = 1;
    else
      x = -1;
    if (i % 2 == 0)
      q += x;
    else
      q -= x;
    M[q].push_back(i + 1);
    A.push_back(q);
  }
  while (qq--) {
    in(x, y);
    u = A[y] - A[x - 1];
    if (u == 0) {
      print(0);
    } else if (abs(u) % 2 == 1) {
      print(1);
    } else {
      print(2);
    }
  }
  M.clear();
  cl(A);
}
int main() {
  cout << fixed << setprecision(15);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> codeforces;
  while (codeforces--) {
    ans = 0;
    solve();
  }
}
