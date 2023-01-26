#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 5;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
struct node {
  int id;
  int u;
  int v;
  bool operator<(const node& x) const {
    if (u != x.u)
      return u < x.u;
    else
      return v < x.v;
  }
} p[N];
int maxn[N];
int ans[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i].u;
    }
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i].v;
      p[i].id = i;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
      maxn[i] = max(maxn[i - 1], p[i - 1].v);
    }
    for (int i = n; i; i--) {
      if (i == n) {
        ans[p[i].id] = 1;
      } else {
        if (p[i].v > p[n].v) {
          ans[p[i].id] = 1;
        } else {
          if (maxn[i] > p[n].v) {
            ans[p[i].id] = 1;
          } else
            ans[p[i].id] = 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}
