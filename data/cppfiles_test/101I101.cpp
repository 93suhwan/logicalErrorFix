#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 200010;
long long ksm(long long x, long long y) {
  long long res = 1;
  do {
    if (y & 1) res = 1ll * x * res % mod;
    x = 1ll * x * x % mod;
  } while (y >>= 1);
  return res;
}
void sol() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> v(n), h(m);
  vector<pair<long long, long long> > a1(k), a2(k);
  map<long long, long long> mp1;
  map<long long, long long> mp2;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
    mp1[v[i]] = 1;
  }
  for (long long i = 0; i < m; ++i) {
    cin >> h[i];
    mp2[h[i]] = 1;
  }
  for (long long i = 0; i < k; ++i) {
    cin >> a1[i].first >> a1[i].second;
    a2[i].first = a1[i].second;
    a2[i].second = a1[i].first;
  }
  long long j = 0;
  long long res = 0;
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
  for (long long i = 0; i < n; ++i) {
    vector<long long> sad;
    long long ans = 0;
    long long cnt = 1;
    for (; j < k && a1[j].first < v[i]; j++) {
      if (mp1[a1[j].first]) continue;
      if (j + 1 == k || a1[j].first != v[i] ||
          a1[j].second != a1[j + 1].second) {
        sad.push_back(cnt);
        ans += cnt;
        cnt = 1;
      } else
        cnt++;
    }
    for (auto d : sad) {
      res += d * (ans - d);
    }
  }
  j = 0;
  for (long long i = 0; i < m; ++i) {
    vector<long long> sad;
    long long ans = 0;
    long long cnt = 1;
    for (; j < k && a2[j].first < h[i]; j++) {
      if (mp1[a2[j].second]) continue;
      if (j + 1 == k || a2[j].first != h[i] ||
          a2[j].second != a2[j + 1].second) {
        sad.push_back(cnt);
        ans += cnt;
        cnt = 1;
      } else
        cnt++;
    }
    for (auto d : sad) {
      res += d * (ans - d);
    }
  }
  cout << res << "\n";
}
signed main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  long long __ = 1;
  cin >> __;
  while (__--) sol();
  return 0;
}
