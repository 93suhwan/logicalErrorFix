#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = a[i * m + j];
        for (int k = 0; k < j; k++) {
          if (v[i][k].first != v[i][j].first && v[i][k].second < v[i][j].second)
            ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
