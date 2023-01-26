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
      return u > x.u;
    else
      return v > x.v;
  }
} p[N];
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
    for (int i = 1; i <= n; i++) {
      cin >> p[i].v;
      p[i].id = i;
    }
    sort(p + 1, p + 1 + n);
    int num = 0;
    int val = p[n].v;
    for (int i = 1; i < n; i++) {
      if (p[i].v <= val) {
        num++;
        val = max(val, p[i].v);
      } else {
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      int yb = n - i;
      int zb = num;
      if (yb + zb >= n - 1) {
        ans[p[i].id] = 1;
      } else {
        ans[p[i].id] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}
