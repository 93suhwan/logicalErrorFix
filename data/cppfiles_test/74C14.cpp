#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd;
const long long maxn = 3e7 + 50;
const long long mod = 998244353;
const long long base = 1e18;
long long a[1030];
vector<long long> vt[3];
bool dd[maxn];
long long n;
void dosth(long long x, long long y, long long len) {
  long long h = x & y;
  x -= h;
  y -= h;
  vector<long long> vt;
  vector<long long> vt1;
  for (int i = 0; i < len; i++) {
    if (x & (1ll << i)) vt.push_back(a[i + 1]);
    if (y & (1ll << i)) vt1.push_back(a[i + 1]);
  }
  vector<long long> nw;
  long long pre = 0;
  cout << "YES"
       << "\n";
  for (int i = 0; i < vt.size(); i++) {
    cout << vt[i] - pre << " ";
    pre = vt[i] - pre;
    cout << vt1[i] - pre << " ";
    pre = vt1[i] - pre;
  }
  for (int i = 0; i < n; i++) {
    if (i >= len) {
      cout << a[i + 1] - pre << " ";
    } else {
      if (x & (1ll << i)) continue;
      if (y & (1ll << i)) continue;
      cout << a[i + 1] - pre << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    vt[a[i] % 2].push_back(a[i]);
    if (a[i] == a[i - 1]) {
      cout << "YES"
           << "\n";
      vector<long long> nw;
      cout << 0 << " ";
      long long t = i;
      for (int i = 1; i <= n; i++) {
        if (t == i) continue;
        cout << a[i] << " ";
      }
      return 0;
    }
  }
  if (n == 2) {
    cout << "NO";
    return 0;
  }
  if (vt[0].size() && (vt[1].size() >= 2 || vt[0].size() >= 3)) {
    long long a1 = vt[0].back();
    long long b, c;
    vt[0].pop_back();
    long long pos = 0;
    if (vt[1].size() >= 2) pos = 1;
    b = vt[pos].back();
    vt[pos].pop_back();
    c = vt[pos].back();
    vt[pos].pop_back();
    long long x = (a1 - c + b) / 2;
    long long y = b - x;
    long long z = c - y;
    cout << "YES"
         << "\n";
    cout << x << " " << y << " " << z << " ";
    for (int i = 1; i <= n; i++) {
      if (a[i] == a1 || a[i] == b || a[i] == c) continue;
      cout << a[i] - x << " ";
    }
    return 0;
  }
  long long h = min(n, (long long)26);
  long long p = h / 2;
  for (int i = 0; i < (1ll << h); i++) {
    if (__builtin_popcount(i) != p) continue;
    long long nw = 0;
    for (int j = 0; j < h; j++) {
      if (i & (1ll << j)) {
        nw += a[j + 1];
      }
    }
    if (dd[nw]) {
      for (int t = 0; t < i; t++) {
        if (__builtin_popcount(t) != p) continue;
        long long cnt = 0;
        for (int j = 0; j < h; j++) {
          if (t & (1ll << j)) {
            cnt += a[j + 1];
          }
        }
        if (cnt == nw) {
          dosth(i, t, h);
          return 0;
        }
      }
    } else {
      dd[nw] = 1;
    }
  }
  cout << "NO"
       << "\n";
}
