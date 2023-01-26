#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> ans(n);
  if (n % 2 == 0) {
    for (int i = 0; i < n; i = i + 2) {
      ans[i] = -v[i + 1];
      ans[i + 1] = v[i];
    }
  } else {
    if (v[0] > 0 && v[1] > 0) {
      ans[0] = v[2];
      ans[1] = v[2];
      ans[2] = -(v[1] + v[0]);
    } else if (v[0] < 0 && v[1] < 0) {
      ans[1] = -v[2];
      ans[0] = -v[2];
      ans[2] = (v[1] + v[0]);
    } else {
      if (v[0] > 0)
        ans[0] = v[2];
      else
        ans[0] = -v[2];
      if (v[1] > 0)
        ans[1] = v[2];
      else
        ans[1] = -v[2];
      ans[2] = -(abs(v[0]) + abs(v[1]));
    }
    for (int i = 3; i < n; i += 2) {
      ans[i] = -v[i + 1];
      ans[i + 1] = v[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
