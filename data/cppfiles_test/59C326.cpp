#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(5));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int cnt = 0;
      int cnt2 = 0;
      int bth = 0;
      for (int k = 0; k < n; k++) {
        if (v[k][i] == 0 and v[k][j]) cnt++;
        if (v[k][i] and v[k][j]) bth++;
        if (v[k][i]) cnt2++;
      }
      if (cnt2 < n / 2) break;
      if (cnt >= n / 2) {
        cout << "YES" << endl;
        return;
      }
      if (bth >= n / 2 - cnt and cnt2 - (n / 2 - cnt) >= n / 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  long long i = 0;
  while (i < t) {
    solve();
    i++;
  }
}
