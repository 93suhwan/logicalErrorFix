#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100001;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
long long n;
vector<vector<long long> > v;
bool ok(long long x) {
  for (long long i = 0; i < n; i++)
    for (auto j : v[i])
      if (j >= x)
        return false;
      else
        x++;
  return true;
}
bool cmp(vector<long long> &a, vector<long long> &b) {
  return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end());
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int tc = 1, cs = 0;
  cin >> tc;
  while (tc--) {
    long long i;
    cin >> n;
    v.clear();
    v.resize(n);
    for (i = 0; i < n; i++) {
      long long a;
      cin >> a;
      v[i].resize(a);
      for (auto &it : v[i]) cin >> it;
      ;
    }
    sort(v.begin(), v.end(), cmp);
    long long lo = 1LL, hi = 100LL, m, ans = INF;
    while (lo <= hi) {
      m = (lo + hi) / 2LL;
      if (ok(m))
        ans = m, hi = m - 1;
      else
        lo = m + 1;
    }
    cout << ans << '\n';
  }
}
