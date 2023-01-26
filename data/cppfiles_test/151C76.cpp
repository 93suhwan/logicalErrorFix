#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> tmp[500005];
vector<long long int> p(500005);
void solve() {
  long long int q1;
  cin >> q1;
  long long int qq = q1;
  vector<long long int> ans;
  vector<vector<long long int>> q;
  for (long long int i = 1; i <= 500004; i++) p[i] = i;
  while (qq--) {
    long long int t, x = -1, y = -1;
    cin >> t;
    if (t == 1) {
      cin >> x;
    } else
      cin >> x >> y;
    q.push_back({t, x, y});
  }
  for (long long int i = q1 - 1; i >= 0; i--) {
    if (q[i][0] == 1) {
      ans.push_back(p[q[i][1]]);
    } else {
      p[q[i][1]] = p[q[i][2]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long int i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  solve();
  return 0;
}
