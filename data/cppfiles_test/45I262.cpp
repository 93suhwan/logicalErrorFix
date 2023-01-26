#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 5e5 + 5, mod = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long lct(long long a, long long b) { return a * b / gcd(a, b); }
long long inv(long long x) { return qpow(x, mod - 2); }
int a[N];
int n;
vector<int> g0, g1;
int main() {
  int _ = 1;
  cin >> _;
  while (_--) {
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        cnt1++, g1.push_back(i);
      else
        cnt0++, g0.push_back(i);
    }
    if (n % 2 == 0) {
      if (cnt1 == cnt0) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
          if (i % 2 == 0) {
            ans += abs(g0[i / 2 - 1] - i);
          } else {
            ans += abs(g1[i / 2] - i);
          }
        }
        int tt = 0;
        for (int i = 1; i <= n; i++) {
          if (i % 2 == 0) {
            tt += abs(g1[i / 2 - 1] - i);
          } else {
            tt += abs(g0[i / 2] - i);
          }
        }
        ans = min(ans, tt);
        cout << ans / 2 << endl;
      } else
        puts("-1");
    } else {
      if (abs(cnt1 - cnt0) == 1) {
        int ans = 0;
        if (cnt1 > cnt0) {
          for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
              ans += abs(g0[i / 2 - 1] - i);
            } else {
              ans += abs(g1[i / 2] - i);
            }
          }
        } else {
          for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
              ans += abs(g1[i / 2 - 1] - i);
            } else {
              ans += abs(g0[i / 2] - i);
            }
          }
        }
        cout << ans / 2 << endl;
      } else
        puts("-1");
    }
    g0.clear();
    g1.clear();
  }
}
