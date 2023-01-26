#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long N = 1000000007;
void func() {
  int q;
  cin >> q;
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i] >> x[i];
    if (t[i] == 2) cin >> y[i];
  }
  vector<int> p(500005);
  iota(p.begin(), p.end(), 0);
  vector<int> ans;
  for (int i = q - 1; i > -1; i--) {
    if (t[i] == 1)
      ans.push_back(p[x[i]]);
    else
      p[x[i]] = p[y[i]];
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    func();
  }
  return 0;
}
