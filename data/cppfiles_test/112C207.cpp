#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, maxn = 5e5 + 5, inf = 1e9 + 5;
void Solve() {
  vector<int> v(3);
  for (int i = (0); i < (3); (i)++) cin >> v[i];
  int m;
  cin >> m;
  sort(v.begin(), v.end());
  if (m > v[0] + v[1] + v[2] - 3 || m < v[2] - (v[0] + v[1] + 1)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t-- > 0) Solve();
  return 0;
}
