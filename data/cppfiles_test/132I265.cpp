#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  vector<long long> v(7);
  for (auto &x : v) cin >> x;
  cout << v[0] << " " << v[1] << " ";
  for (int i = 2; i < 7; i++) {
    if (v[0] + v[1] != v[i]) {
      cout << v[i] << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
