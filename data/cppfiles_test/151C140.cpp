#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int maxm = 5e5 + 5;
long long to[maxm];
void solve() {
  long long q;
  cin >> q;
  vector<long long> op(q), x(q), y(q);
  for (long long i = 0; i < q; ++i) {
    cin >> op[i] >> x[i];
    if (op[i] == 2) cin >> y[i];
  }
  for (long long i = 0; i < maxm; ++i) to[i] = i;
  vector<long long> ans;
  for (long long i = q - 1; i >= 0; --i) {
    if (op[i] == 2) {
      to[x[i]] = to[y[i]];
    } else {
      ans.push_back(to[x[i]]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << " ";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
