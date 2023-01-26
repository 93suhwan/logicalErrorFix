#include <bits/stdc++.h>
using namespace std;
const int dir[5] = {0, -1, 0, 1, 0};
const long long oo = LLONG_MAX;
const long long mod = 998244353;
const int N = 307;
pair<int, int> a[N * N + 7];
int t, n, m;
bool Check(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first && a.second < b.second);
}
int main() {
  {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  };
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a + 1, a + 1 + n * m);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
      long long cnt = 0;
      for (int j = 2; j <= m; ++j)
        for (int z = 1; z <= j - 1; ++z)
          cnt += Check(a[(i - 1) * m + z], a[(i - 1) * m + j]);
      res += cnt;
    }
    cout << res << '\n';
  }
}
