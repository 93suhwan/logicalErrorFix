#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 1e9;
const long long int maxn = 5e3 + 1;
long long int POW(long long int a, long long int b) {
  long long int ret = 1;
  for (; b; b >>= 1, a = a * a) {
    if (b & 1) {
      ret *= a;
    }
  }
  return ret;
}
long long int POWM(long long int a, long long int b, long long int MMM = mod) {
  long long int ret = 1;
  a = a % MMM;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long int run_test() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  long long int l = 0, r = 1e9;
  long long int mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    vector<long long int> d = a;
    bool ok = true;
    for (long long int i = n - 1; i >= 0; i--) {
      if (d[i] < mid) {
        ok = false;
        break;
      }
      if (i > 1) {
        long long int transferrable = d[i] - mid;
        transferrable = min(a[i], transferrable);
        long long int div = transferrable / 3;
        d[i - 1] += div;
        d[i - 2] += 2 * div;
      }
    }
    if (ok) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << '\n';
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int tt;
  tt = 1;
  cin >> tt;
  for (long long int test = 1; test <= tt; test++) {
    run_test();
  }
  return 0;
}
