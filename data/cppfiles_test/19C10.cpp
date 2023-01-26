#include <bits/stdc++.h>
using namespace std;
int solve();
vector<int> a;
string s;
int n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
int in(vector<int> &a, int n) {
  int i = 0, x, sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
  return sum;
}
int pos[3000];
int inf = 99999999;
int solve() {
  a.clear();
  s.clear();
  int i = 0, j = 0, k = 0;
  int flag = 0;
  int x = 0, y = 0, z = 0;
  cin >> n;
  in(a, n);
  for (i = 0; i <= 2 * 1000; i++) pos[i] = inf;
  pos[0] = a[0];
  stack<int> startpos, length;
  for (i = 1; i < n; i++) {
    for (j = 0; j <= 2 * 1000; j++)
      if (pos[j] != inf) {
        startpos.push(j);
        length.push(pos[j]);
      }
    for (j = 0; j <= 2 * 1000; j++) pos[j] = inf;
    while (!startpos.empty()) {
      if (startpos.top() + a[i] > length.top()) {
        pos[0] = min(pos[0], startpos.top() + a[i]);
      } else {
        x = startpos.top() + a[i];
        x = min(x, length.top() - x);
        pos[x] = min(pos[x], length.top());
      }
      if (startpos.top() - a[i] >= 0) {
        x = startpos.top() - a[i];
        pos[x] = min(pos[x], length.top());
      } else {
        pos[0] = min(pos[0], length.top() - startpos.top() + a[i]);
      }
      length.pop();
      startpos.pop();
    }
  }
  int ans = inf;
  for (i = 0; i <= 2 * 1000; i++) ans = min(ans, pos[i]);
  cout << ans << "\n";
  return 0;
}
