#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long n, m, p;
void solve() {
  cin >> n >> m;
  vector<pair<long long, long long>> a(n * m);
  for (int i = 0; i < n * m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n * m; i++) a[i].second = -a[i].second;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    sort(a.begin() + (m * i), a.begin() + (m * (i + 1)));
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < j; k++) {
        if (a[i * m + k].second > a[i * m + j].second) cnt++;
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
