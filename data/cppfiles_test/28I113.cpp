#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<int> dif(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    int d = (i - p[i] + n) % n;
    dif[d]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (dif[i] >= (n + 2) / 3) {
      if (n - dif[i] <= 2 * m) ans.push_back(i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << " ";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  cin >> ntest;
  for (int test = 0; test < ntest; ++test) {
    solve();
  }
  return 0;
}
