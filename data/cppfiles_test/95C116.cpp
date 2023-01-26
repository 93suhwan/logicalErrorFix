#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long tt, s, n;
bool check(long long x) {
  long long z = 1;
  while (z <= x) {
    if (z == x) return true;
    z = z * 10;
  }
  return false;
}
long long sp(long long x) {
  long long z = 1;
  while (z <= x) {
    if (z == x) return z / 10;
    z = z * 10;
  }
  return z / 10;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> s >> n;
    vector<long long> v;
    v.push_back(s);
    for (long long i = 0; i < n - 1; i++) {
      long long ans = -1;
      for (long long j = 0; j < (long long)v.size(); j++) {
        if (!check(v[j])) {
          ans = v[j];
          v.erase(v.begin() + j);
          break;
        }
      }
      if (ans == -1) {
        long long mi = 1e18;
        for (long long j = 0; j < (long long)v.size(); j++) {
          if (v[j] != 1) mi = min(mi, v[j]);
        }
        for (long long j = 0; j < (long long)v.size(); j++) {
          if (v[j] == mi) {
            ans = v[j];
            v.erase(v.begin() + j);
            break;
          }
        }
      }
      v.push_back(sp(ans));
      v.push_back(ans - sp(ans));
    }
    for (long long i = 0; i < (long long)v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
