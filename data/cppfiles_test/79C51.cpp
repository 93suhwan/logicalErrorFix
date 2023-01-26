#include <bits/stdc++.h>
using namespace std;
struct _IO {
  _IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
} _io;
const long long maxn = 3e5 + 10, mod = 1e9 + 7;
template <typename... T>
long long madd(T... args) {
  long long res = 0;
  for (auto i : {args...}) {
    res = (res + ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
template <typename... T>
long long mmul(T... args) {
  long long res = 1;
  for (auto i : {args...}) {
    res = (res * ((i % mod + mod) % mod)) % mod;
  }
  return res % mod;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long mpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long _inv(long long x) { return mpow(x, mod - 2); }
long long a[maxn], b[maxn], pre[maxn], last;
deque<long long> ans;
void bfs(long long u) {
  queue<long long> q;
  q.push(u);
  last = u;
  while (q.size()) {
    if (last == 0) break;
    long long x = q.front();
    q.pop();
    long long v = x + b[x];
    for (long long i = min(last - 1, v); i >= v - a[v]; --i) {
      pre[i] = x;
      q.push(i);
    }
    last = min(last, v - a[v]);
  }
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  for (long long i = 1; i <= n; ++i) cin >> b[i];
  bfs(n);
  if (last != 0)
    cout << "-1\n";
  else {
    long long now = 0;
    while (now != n) {
      ans.push_front(now);
      now = pre[now];
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
  }
}
int main() {
  long long T = 1;
  while (T--) solve();
  return 0;
}
