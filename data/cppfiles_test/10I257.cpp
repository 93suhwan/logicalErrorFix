#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long powerMod(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * powerMod(a * a % md, b / 2, md) % md
                      : powerMod(a * a % md, b / 2, md) % md));
}
long long modInv(long long x, long long m) { return powerMod(x, m - 2, m); }
const long long INF = 1e18;
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  map<int, int> m;
  int e = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  map<int, int> m1;
  for (int i = 0; i < n; i++) {
    m1[a[i]] = m[a[i]];
  }
  for (int i = 0; i < n; i++) {
    if (m1[a[i]] > k) {
      e += m1[a[i]] - k;
      m1[a[i]] = 0;
    }
  }
  int t = n - e;
  int c[k + 1];
  for (int i = 1; i <= k; i++) c[i] = (t / k);
  map<int, int> p;
  int j = 1;
  int ans[n];
  int f = (t / k) * k;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (m[a[i]] > k) {
      ans[i] = 0;
      m[a[i]]--;
    }
    if (count >= f)
      ans[i] = 0;
    else {
      while (c[j] == 0) j++;
      if (p[a[i]] >= j) {
        if (p[a[i]] + 1 <= k) {
          ans[i] = p[a[i]] + 1;
          c[p[a[i]] + 1]--;
          p[a[i]] = ans[i];
          count++;
        } else {
          ans[i] = 0;
        }
      } else {
        ans[i] = j;
        c[j]--;
        p[a[i]] = j;
        count++;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
