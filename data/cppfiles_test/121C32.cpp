#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, one_s = 0, one_u = 0, ans = 0, f_ans = INT_MAX;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '1') one_s++;
      ans++;
    }
    if (a[i] != b[i]) {
      if (a[i] == '1') one_u++;
    }
  }
  if (one_s == (ans - one_s) + 1) {
    f_ans = min(f_ans, ans);
  }
  ans = n - ans;
  if (one_u == (ans - one_u)) {
    f_ans = min(f_ans, ans);
  }
  if (f_ans == INT_MAX) f_ans = -1;
  cout << f_ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
