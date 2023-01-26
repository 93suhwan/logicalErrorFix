#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 7;
const int MOD = 1e9 + 7;
int n;
pair<int, int> p[N];
int l[N], r[N], d[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p + 1, p + 1 + n, [](pair<int, int> a, pair<int, int> b) {
    return a.second - a.first > b.second - b.first;
  });
  for (int i = 1; i <= n; i++) {
    l[i] = p[i].first, r[i] = p[i].second;
    for (int j = i + 1; j <= n; j++) {
      if (p[j].first == l[i]) {
        d[i] = p[j].second + 1;
        break;
      } else if (p[j].second == r[i]) {
        d[i] = p[j].first - 1;
        break;
      }
    }
    if (l[i] == r[i]) d[i] = l[i];
    cout << l[i] << " " << r[i] << " " << d[i] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
