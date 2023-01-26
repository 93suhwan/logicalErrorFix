#include <bits/stdc++.h>
const long long N = 3e4 + 100;
const long long INF = 1e9;
const long long inf = -1e9;
const long long MOD = 998244353;
using namespace std;
long long binpow(long long a, long long x) {
  if (x == 0) return 1;
  if (x % 2 == 1) return (a * binpow(a, x - 1));
  long long p = binpow(a, x / 2);
  return (p * p);
}
long long n, a[N], b[N], k, p;
void solve() {
  cin >> n;
  vector<pair<long long, pair<long long, long long> > > g;
  vector<long long> us(n + 10, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  while (1 > 0) {
    long long l = 0;
    for (int j = 1; j <= n; j++) {
      if (b[j] != a[j]) {
        k = j;
        l = 1;
        break;
      } else {
        us[j] = 1;
      }
    }
    if (l == 0) break;
    for (int j = 1; j <= n; j++) {
      if (us[j] == 0) {
        if (b[k] == a[j]) {
          p = j;
          break;
        }
      }
    }
    g.push_back({k, {p, 1}});
    long long q = a[p];
    for (int j = p; j >= k + 1; j--) {
      a[j] = a[j - 1];
    }
    a[k] = q;
  }
  cout << g.size() << "\n";
  for (int i = 0; i < g.size(); i++) {
    cout << g[i].first << " " << g[i].second.first << " " << g[i].second.second
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int o = 1;
  cin >> o;
  while (o--) {
    solve();
  }
}
