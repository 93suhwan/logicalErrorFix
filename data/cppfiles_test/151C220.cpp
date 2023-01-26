#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, j, k;
  cin >> n;
  map<long long int, long long int> m;
  long long int l = 5 * 100001;
  for (i = 1; i < l; i++) {
    m[i] = i;
  }
  vector<long long int> x(l);
  vector<pair<long long int, long long int>> y(l);
  vector<long long int> ans;
  long long int t = n;
  long long int a, b, c;
  for (i = 0; i < t; i++) {
    cin >> a >> b;
    if (a == 2) {
      cin >> c;
      x[i] = 0;
      y[i] = make_pair(b, c);
    } else {
      x[i] = b;
      y[i] = make_pair(0, 0);
    }
  }
  t = n;
  for (i = t - 1; i >= 0; i--) {
    if (x[i] != 0) {
      ans.push_back(m[x[i]]);
    } else {
      pair<long long int, long long int> p = y[i];
      m[p.first] = m[p.second];
    }
  }
  reverse(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  long long int t = 1, i;
  while (t--) {
    solve();
  }
  return 0;
}
