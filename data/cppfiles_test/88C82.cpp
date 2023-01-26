#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 90005;
const long long MOD = 1e9 + 7;
const long long base = 257;
const long double eps = 1e-7;
long long n;
string s;
vector<long long> v;
long long tri[MAX], m;
pair<long long, long long> a[MAX];
long long pos[MAX];
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
long long ok(long long k) { return ((k - 1) / m) + 1; }
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first) return a.first < b.first;
  if (ok(pos[a.second]) == ok(pos[b.second])) return a.second > b.second;
  return a.second < b.second;
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
    for (long long i = 1; i <= n * m; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a + 1, a + m * n + 1);
    for (long long i = 1; i <= n * m; i++) {
      pos[a[i].second] = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    for (long long i = 1; i <= n * m; i++) {
      pos[a[i].second] = i;
    }
    long long ans = 0;
    for (long long i = 1; i <= n * m; i++) {
      ans += max(0ll, get(pos[i]) - get((pos[i] - 1) / m * m));
      update(pos[i], 1);
    }
    cout << ans << "\n";
  }
}
