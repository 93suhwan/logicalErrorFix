#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans *= a;
    }
    a *= a;
    n >>= 1;
  }
  return ans;
}
inline long long _qpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
inline long long ksm(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int maxnum = 1e6 + 5;
const int MAXN = (1 << 13) - 1;
vector<int> g[MAXN + 5];
int r[MAXN + 5];
int ans[MAXN + 1];
int n;
int x;
void slove() {
  for (int i = 0; i <= MAXN; i++) g[i].push_back(0), r[i] = MAXN;
  cin >> n;
  ans[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (int v : g[x]) {
      int to = x ^ v;
      ans[to] = 1;
      while (r[to] > x) {
        g[r[to]].push_back(to);
        r[to]--;
      }
    }
    g[x].clear();
  }
  vector<int> res;
  for (int i = 0; i <= MAXN; i++)
    if (ans[i]) res.push_back(i);
  cout << res.size() << "\n";
  for (int x : res) cout << x << " ";
  cout << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  slove();
  return 0;
}
