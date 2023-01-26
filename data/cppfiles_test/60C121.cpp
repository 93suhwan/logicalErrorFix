#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long add(long long a, long long b) {
  long long res = a + b;
  if (res >= mod) res -= mod;
  return res;
}
long long sub(long long a, long long b) {
  long long res = a - b + mod;
  if (res >= mod) res -= mod;
  return res;
}
long long mul(long long a, long long b) {
  return (((a % mod) * (b % mod)) % mod);
}
long long potolok(long long a, long long b) { return (a + b - 1) / b; }
long long gcd(long long x, long long y) {
  if (y == 0) {
    return x;
  }
  if (x == 0) {
    return y;
  }
  if (x > y) {
    return gcd(y, x % y);
  } else {
    return gcd(x, y % x);
  }
}
struct segtree {
  int razmer;
  vector<long long> tree;
  void Init(vector<long long> &v) {
    int n = (int)v.size();
    razmer = 1;
    while (razmer < n) razmer *= 2;
    tree.assign(2 * razmer - 1, 0);
  }
  void build(vector<long long> &v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)v.size()) {
        tree[x] = v[lx];
      }
    } else {
      int m = (lx + rx) / 2;
      build(v, 2 * x + 1, lx, m);
      build(v, 2 * x + 2, m, rx);
      tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
  }
  void build(vector<long long> &v) { build(v, 0, 0, razmer); }
  void cet(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    } else {
      int m = (lx + rx) / 2;
      if (i < m) {
        cet(i, v, 2 * x + 1, lx, m);
      } else {
        cet(i, v, 2 * x + 2, m, rx);
      }
      tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
  }
  void cet(int i, int v) { cet(i, v, 0, 0, razmer); }
  long long mn(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) {
      return mod;
    }
    if (lx >= l && rx <= r) {
      return tree[x];
    } else if (min(rx, r) - max(lx, l) >= 0) {
      int m = (lx + rx) / 2;
      long long s1 = mn(l, r, 2 * x + 1, lx, m);
      long long s2 = mn(l, r, 2 * x + 2, m, rx);
      return min(s1, s2);
    }
  }
  long long mn(int l, int r) { return mn(l, r, 0, 0, razmer); }
};
bool isSquare(int x) {
  int y = (int)(sqrt(x));
  while (y * y < x) y++;
  while (y * y > x) y--;
  return y * y == x;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  map<long long, long long> mp;
  long long ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
    mp[v[i] * n]++;
  }
  sum *= 2;
  for (int i = 0; i < n; i++) {
    if (mp.count(sum - v[i] * n)) {
      if (sum - v[i] * n == v[i] * n) {
        ans += (mp[sum - v[i] * n] - 1);
      } else {
        ans += mp[sum - v[i] * n];
      }
    }
  }
  cout << ans / 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
