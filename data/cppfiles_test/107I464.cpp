#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
const long long INF = 1e18 + 100;
const long long NINF = -INF;
const int inf = 1e8;
const int MOD = 998244353;
const int mod = 1000000007;
const int ninf = -mod;
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long tri(long long a, long long b, long long c) {
  return mul(mul(a, b), c);
}
long long binPow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long ans = binPow(a, b / 2, mod);
  if (b & 1) {
    return tri(ans, ans, a);
  }
  return mul(ans, ans);
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
void solve() {
  int n, a, b, i, j, f = 1, t = 1;
  cin >> n >> a >> b;
  if (a + b + 2 > n || abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  if (a == b) {
    t = 0;
  }
  vector<int> v;
  if (a >= b) {
    int left = 2, right = n - 1;
    cout << 1 << " " << n << " ";
    while (a > 0) {
      if (f) {
        if (a == 1) {
          if (t == 1) {
            cout << right-- << " ";
          } else {
            cout << left++ << " ";
          }
        } else {
          cout << left++ << " ";
        }
        a--;
      } else {
        cout << right-- << " ";
      }
      f = !f;
    }
    if (t == 1) {
      for (i = right; i >= left; i--) cout << i << " ";
      cout << "\n";
      return;
    } else {
      for (i = left; i <= right; i++) cout << i << " ";
      cout << "\n";
      return;
    }
  } else {
    int left = 2, right = n - 1;
    cout << n << " " << 1 << " ";
    while (b > 0) {
      if (f) {
        cout << right-- << " ";
        b--;
      } else {
        cout << left++ << " ";
      }
      f = !f;
    }
    for (i = right; i >= left; i--) cout << i << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
