#include <bits/stdc++.h>
using namespace std;
inline void smax(int& a, int b) {
  if (b > a) a = b;
}
inline void smin(int& a, int b) {
  if (b < a) a = b;
}
inline void smax(long long& a, long long b) {
  if (b > a) a = b;
}
inline void smin(long long& a, long long b) {
  if (b < a) a = b;
}
const long long LLINF = 2e18 + 13;
const int INF = 1e9 + 7;
mt19937 rng(time(nullptr) + 'm' + 'a' + 'n' + 'u' + 'l');
uniform_int_distribution<int> uid(0, INF);
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> pr(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) pr[i + 1] = pr[i] + a[i];
    long long sum = pr[n];
    if (sum <= k) {
      cout << 0 << endl;
      continue;
    }
    long long ans = sum - k;
    for (int i = 1; i < n; ++i) {
      long long minus = pr[i];
      long long lans = n - i;
      long long l = -1, r = INF * 10ll;
      while (r - l > 1) {
        long long m = r + l >> 1;
        if (minus - m + (a[0] - m) * lans <= k) {
          r = m;
        } else {
          l = m;
        }
      }
      smin(ans, lans + r);
    }
    cout << ans << endl;
  NEXT:;
  }
  return 0;
}
