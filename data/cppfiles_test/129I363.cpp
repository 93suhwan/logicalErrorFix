#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == (i + 1)) continue;
    if ((v[i] - (i + 1)) < (i + 1)) {
      cout << -1 << endl;
      return;
    } else
      count++;
  }
  cout << count << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
