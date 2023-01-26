#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100005;
const int mod = 1000000007;
void solve() {
  int n, k;
  int qtd[12];
  int ans[N];
  for (int i = 0; i < 10; i++) {
    qtd[i] = 0;
  }
  vector<pair<int, pair<int, int> > > v;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
    int x;
    cin >> x;
    if (qtd[x] < k) {
      qtd[x]++;
      v.push_back({x, {i, 0}});
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    ans[v[i].second.first] = (i % k) + 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
