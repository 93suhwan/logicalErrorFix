#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 17;
void solve() {
  long long n, m;
  cin >> m >> n;
  vector<vector<long long>> p(n, vector<long long>(m)),
      a(n, vector<long long>(m)), need(m);
  vector<long long> good(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[j][i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
  long long l = -1, r = 1e18;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    bool ok = 1;
    vector<long long> cnt(m, 0);
    for (int i = 0; i < n; i++) {
      bool flag = 0;
      for (int j = 0; j < m; j++) {
        if (p[i][j] >= mid) {
          if (mid == 3) {
            cout << p[i][j] << " ";
          }
          cnt[j]++;
          flag = 1;
        }
      }
      if (mid == 3) {
        cout << endl;
      }
      ok &= flag;
    }
    long long mx = *max_element((cnt).begin(), (cnt).end());
    if (mx > 1 && ok) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
