#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> p[1010];
bool st[1010];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first - a.second != b.first - b.second)
    return a.first - a.second < b.first - b.second;
  return a.first < b.first;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> p[i].first >> p[i].second, st[i] = 0;
  sort(p + 1, p + 1 + n);
  for (long long i = 1; i <= n; i++) {
    for (long long j = p[i].first; j <= p[i].second; j++) {
      if (!st[j]) {
        cout << p[i].first << ' ' << p[i].second << ' ' << j << endl;
        st[j] = true;
        break;
      }
    }
  }
  cout << endl;
}
signed main() {
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
