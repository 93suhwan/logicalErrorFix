#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int m, n;
  cin >> m >> n;
  vector<vector<long long int>> mat;
  for (long long int i = 0; i < m; i++) {
    vector<long long int> temp(n);
    for (long long int i = 0; i < n; i++) {
      cin >> temp[i];
    }
    mat.push_back(temp);
  }
  vector<long long int> colmaxs(n);
  for (long long int i = 0; i < n; i++) {
    long long int mx = 0;
    for (long long int j = 0; j < m; j++) {
      mx = max(mx, mat[j][i]);
    }
    colmaxs[i] = mx;
  }
  sort(colmaxs.begin(), colmaxs.end());
  if (m < n) {
    cout << colmaxs[0] << endl;
    return;
  }
  long long int ans = colmaxs[0];
  vector<long long int> row2ndmax(m);
  for (long long int i = 0; i < m; i++) {
    vector<long long int> temp = mat[i];
    sort(temp.begin(), temp.end(), greater<long long int>());
    row2ndmax.push_back(temp[1]);
  }
  sort(row2ndmax.begin(), row2ndmax.end(), greater<long long int>());
  long long int x = row2ndmax[0];
  ans = min(ans, x);
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
