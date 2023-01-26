#include <bits/stdc++.h>
const long long mod = 998244353;
const long long maxn = 1e18 + 7;
using namespace std;
long long power(long long b, long long p) {
  b %= mod;
  long long ans = 1;
  while (p > 0) {
    if (p % 2 == 1) {
      ans *= b;
      ans %= mod;
    }
    b *= b;
    b %= mod;
    p /= 2;
  }
  return ans;
}
bool cstsort(pair<string, long long> a, pair<string, long long> b) {
  long long j = 0;
  string s = a.first;
  string t = b.first;
  long long n = s.size();
  while (s[j] == t[j]) j++;
  if ((j + 1) % 2) {
    return s[j] < t[j];
  } else {
    return s[j] > t[j];
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  string s[n];
  vector<pair<string, long long>> pa;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    pa.push_back({s[i], i});
  }
  sort((pa).begin(), (pa).end(), cstsort);
  long long ans[n];
  for (long long i = 0; i < n; i++) {
    long long ind = pa[i].second;
    ans[ind] = i + 1;
  }
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
