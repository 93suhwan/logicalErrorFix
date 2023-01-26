#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
inline long long bigmod(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) {
      R = (R * B) % mod;
    }
    P >>= 1;
    B = (B * B) % mod;
  }
  return R;
}
const long long mxn = 2e5 + 10;
long long Mod(long long a) {
  if (a < 0)
    return (a + mod) % mod;
  else
    return a % mod;
}
long long Mul(long long a, long long b) { return Mod(Mod(a) * Mod(b)); }
long long Add(long long a, long long b) { return Mod(Mod(a) + Mod(b)); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  for (long long tc = 1; tc <= tt; tc++) {
    long long n, k, c = 0;
    cin >> n >> k;
    vector<long long> pq1, pq2;
    map<long long, long long> mp1, mp2;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x > 0) {
        pq1.push_back(x);
        mp1[x]++;
      } else if (x < 0) {
        pq2.push_back(abs(x));
        mp2[abs(x)]++;
      } else
        c++;
    }
    n -= c;
    long long rlagbe = 0, llagbe = 0;
    for (auto i : mp1) rlagbe += i.second;
    for (auto i : mp2) llagbe += i.second;
    long long ans = 0, pos = 0;
    sort(pq1.begin(), pq1.end());
    sort(pq2.begin(), pq2.end());
    if (!pq1.empty()) {
      for (auto i : mp1) {
        long long d = rlagbe / k;
        if (rlagbe % k) d++;
        ans += (2 * d - 1) * (i.first - pos);
        rlagbe -= i.second;
        pos = i.first;
      }
    }
    pos = 0;
    if (!pq2.empty()) {
      for (auto i : mp2) {
        long long d = llagbe / k;
        if (llagbe % k) d++;
        ans += (2 * d - 1) * (i.first - pos);
        llagbe -= i.second;
        pos = i.first;
      }
    }
    if (!pq1.empty() && !pq2.empty()) {
      ans += min(pq1.back(), pq2.back());
    }
    cout << ans << '\n';
  }
  return 0;
}
