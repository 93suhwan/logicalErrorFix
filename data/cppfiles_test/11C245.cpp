#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> &v) {
  for (auto it : v) {
    cout << it << " ";
  }
}
void solve() {
  int n;
  cin >> n;
  string s;
  vector<int> summ(n, 0);
  vector<vector<int>> v(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (char c : s) {
      v[i][(int)(c - 'a')]++;
    }
    summ[i] = s.size();
  }
  int ans = 0;
  for (int c = 0; c < 5; c++) {
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
      diff[i] = -v[i][c] + (summ[i] - v[i][c]);
    }
    sort(diff.begin(), diff.end());
    if (diff[0] >= 0) {
      continue;
    }
    int pt = 1;
    int curr = diff[0];
    for (int i = 1; i < n; i++) {
      if (curr + diff[i] < 0) {
        pt++;
        curr += diff[i];
      } else {
        break;
      }
    }
    ans = max(ans, pt);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
