#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long n, m, u, v, k;
long long flag;
long long a[N];
long long x, y, z;
long long aa, bb, cc, dd;
long long ans[100005];
long long sum;
void init() {}
long long gcd(long long x, long long y) {
  if (!y) return x;
  return gcd(y, x % y);
}
struct node {
  long long x, id;
  bool operator<(const node t) const { return x < t.x; }
};
long long getn(long long x, long long y, long long z) {
  long long n;
  cout << "? " << x << " " << y << " " << z << endl;
  cin >> n;
  return n;
}
void solve() {
  init();
  cin >> n;
  sum = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = 0;
  }
  for (long long i = 0; i < n / 3; i++) {
    ans[i] = getn(i * 3 + 1, i * 3 + 2, i * 3 + 3);
    if (!ans[i]) {
      u = i;
    } else {
      v = i;
    }
  }
  aa = getn(u * 3 + 1, u * 3 + 2, v * 3 + 1);
  bb = getn(u * 3 + 1, u * 3 + 2, v * 3 + 2);
  cc = getn(v * 3 + 1, v * 3 + 2, u * 3 + 1);
  dd = getn(v * 3 + 1, v * 3 + 2, u * 3 + 2);
  if (aa + bb == 0) {
    x = u * 3 + 1;
  } else {
    x = u * 3 + 3;
  }
  a[x] = 0;
  if (cc + dd == 2) {
    y = v * 3 + 1;
  } else {
    y = v * 3 + 3;
  }
  a[y] = 1;
  for (long long i = 0; i < n / 3; i++) {
    if (ans[i]) {
      aa = getn(i * 3 + 1, i * 3 + 2, x);
      bb = getn(i * 3 + 2, i * 3 + 3, x);
      if (aa + bb == 0) {
        a[i * 3 + 1] = 1;
        a[i * 3 + 2] = 0;
        a[i * 3 + 3] = 1;
      } else if (aa + bb == 2) {
        a[i * 3 + 1] = 1;
        a[i * 3 + 2] = 1;
        a[i * 3 + 3] = 1;
      } else if (aa == 1) {
        a[i * 3 + 1] = 1;
        a[i * 3 + 2] = 1;
        a[i * 3 + 3] = 0;
      } else {
        a[i * 3 + 1] = 0;
        a[i * 3 + 2] = 1;
        a[i * 3 + 3] = 1;
      }
    } else {
      aa = getn(i * 3 + 1, i * 3 + 2, y);
      bb = getn(i * 3 + 2, i * 3 + 3, y);
      if (aa + bb == 0) {
        a[i * 3 + 1] = 0;
        a[i * 3 + 2] = 0;
        a[i * 3 + 3] = 0;
      } else if (aa + bb == 2) {
        a[i * 3 + 1] = 0;
        a[i * 3 + 2] = 1;
        a[i * 3 + 3] = 0;
      } else if (aa == 1) {
        a[i * 3 + 1] = 1;
        a[i * 3 + 2] = 0;
        a[i * 3 + 3] = 0;
      } else {
        a[i * 3 + 1] = 0;
        a[i * 3 + 2] = 0;
        a[i * 3 + 3] = 1;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] == 0) sum++;
  }
  cout << "! " << sum << " ";
  for (long long i = 1; i <= n; i++) {
    if (a[i] == 0) cout << i << " ";
  }
  cout << endl;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
