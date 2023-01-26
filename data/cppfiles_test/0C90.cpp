#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
void prec() {}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> vs(n);
  for (auto &s : vs) {
    cin >> s;
    for (int i = 1; i < m; i += 2) {
      s[i] = 'A' + (25 - (s[i] - 'A'));
    }
  }
  VI ixs(n);
  iota(ixs.begin(), ixs.end(), 0);
  sort(ixs.begin(), ixs.end(),
       [&](int i, int j) -> bool { return vs[i] < vs[j]; });
  for (int i : ixs) cout << (i + 1) << ' ';
  cout << '\n';
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
