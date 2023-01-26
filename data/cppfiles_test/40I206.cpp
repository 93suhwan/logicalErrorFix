#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long>> v;
vector<vector<long long>> prefix;
long long get(int l, int r, int idx) {
  if (r < l) return 0;
  if (l == 0)
    return prefix[idx][r];
  else
    return prefix[idx][r] - prefix[idx][l - 1];
}
long long bob(int k) { return max(get(0, k - 1, 1), get(k + 1, n - 1, 0)); }
long long alice(int k) { return bob(k); }
void solve() {
  cin >> n;
  v.assign(2, vector<long long>(n, 0));
  prefix.assign(2, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) cin >> v[0][i];
  for (int i = 0; i < n; i++) cin >> v[1][i];
  prefix[0][0] = v[0][0];
  prefix[1][0] = v[1][0];
  for (int i = 1; i < n; i++) {
    prefix[0][i] = prefix[0][i - 1] + v[0][i];
    prefix[1][i] = prefix[1][i - 1] + v[1][i];
  }
  int l = 0;
  int r = n - 1;
  long long minAns = alice(n - 1);
  while (l <= r) {
    int m1 = (l + r) / 3;
    int m2 = 2 * (l + r) / 3;
    minAns = min({minAns, alice(m1), alice(m2)});
    if (m1 < m2) {
      r = m2 - 1;
    } else {
      l = m1 + 1;
    }
  }
  cout << minAns << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}
