#include <bits/stdc++.h>
const long long N = 1e6 + 100;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 998244353;
using namespace std;
long long binpow(long long a, long long x) {
  if (x == 0) return 1;
  if (x % 2 == 1) return (a * binpow(a, x - 1));
  long long p = binpow(a, x / 2);
  return (p * p);
}
long long k, mn, mx, p, l;
string s, a;
void solve() {
  cin >> a >> k;
  set<long long> g;
  s = "";
  for (int i = 0; i < a.size(); i++) {
    g.insert(int(a[i]));
  }
  if (g.size() <= k) {
    cout << a;
    return;
  }
  g.clear();
  if (k >= 1) {
    mx = a[k - 1];
    for (int i = 0; i < k - 1; i++) {
      s += a[i];
      mx = max(mx, int(a[i]) * 1ll);
      g.insert(int(a[i]));
    }
    long long cnt = 0;
    while (1 > 0) {
      l = 0;
      p = 0;
      cnt++;
      for (int i = k; i < a.size(); i++) {
        if (a[i] < mx) {
          l = 1;
          break;
        }
        if (a[i] > mx) {
          p = 1;
        }
      }
      if (a[k - 1] < mx) {
        cnt = 10;
        break;
      }
      if (p == 0) break;
      mx++;
    }
    s += char(mx);
    g.insert(mx);
    l = 0;
    if (cnt > 1) l = 1;
    for (int i = k; i < a.size(); i++) {
      if (a[i] < mx && l == 0) {
        l = 1;
        p = 0;
        for (int to : g) {
          if (to == a[i]) {
            p = 1;
            break;
          }
        }
        if (p == 0) {
          if (g.size() < k) {
            g.insert(a[i]);
            s += a[i];
          } else {
            for (int to : g) {
              if (to >= a[i]) {
                s += char(to);
                break;
              }
            }
          }
        } else {
          s += a[i];
          if (g.size() < k) {
            g.insert('0');
          }
        }
      } else if (l == 1) {
        if (g.size() < k) {
          g.insert('0');
        }
        s += char(*g.begin());
      } else {
        for (int to : g) {
          if (to >= a[i]) {
            s += char(to);
            break;
          }
        }
      }
    }
    cout << s;
  }
}
int main() {
  int o = 1;
  cin >> o;
  while (o--) {
    solve();
    cout << "\n";
  }
}
