#include <bits/stdc++.h>
using namespace std;
const int tam = 1e9 + 5;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> f[n + 1];
  for (int i = 1; i <= n; i++) {
    int aux;
    cin >> aux;
    f[aux].push_back(i - 1);
  }
  vector<int> ans(n);
  vector<vector<int>> r;
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)f[i].size() >= k) {
      int c = 1;
      for (auto &first : f[i]) {
        ans[first] = c;
        c++;
        if (c > k) break;
      }
    } else {
      t += (int)f[i].size();
      r.push_back(f[i]);
    }
  }
  if (t >= k) {
    if (t % k) t -= (t % k);
    int j = 1;
    int c = 1;
    for (auto &ri : r) {
      for (auto &rii : ri) {
        ans[rii] = c;
        j++;
        c++;
        if (c > k) {
          c = 1;
        } else if (j > t)
          break;
      }
      if (j > t) break;
    }
  }
  for (auto &ai : ans) cout << ai << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
