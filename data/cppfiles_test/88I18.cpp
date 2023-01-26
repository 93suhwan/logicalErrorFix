#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 90005;
const long long MOD = 1e9 + 7;
const long long base = 257;
const long double eps = 1e-7;
long long a[301][301], n;
string s;
vector<long long> v;
long long tri[MAX], m;
void update(long long x, long long delta) {
  while (x <= 90001) {
    tri[x] += delta;
    x += x & -x;
  }
}
long long get(long long x) {
  long long sum = 0;
  while (x > 0) {
    sum += tri[x];
    x -= x & -x;
  }
  return sum;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    for (long long i = 0; i <= 90001; i++) {
      tri[i] = 0;
    }
    v.clear();
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cin >> a[i][j];
        v.push_back(a[i][j]);
      }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1;
      }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= 90001; j++) {
        tri[i] = 0;
      }
      for (long long j = m; j >= 1; j--) {
        long long x = get(a[i][j]);
        long long y = get(90001);
        ans += y - x;
        update(a[i][j], 1);
      }
    }
    cout << ans << "\n";
  }
}
