#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int a, b, c;
  set<long long int> s;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    s.insert(b);
  }
  long long int pos = -1;
  for (int i = 1; i <= n; i++) {
    if (s.find(i) == s.end()) {
      pos = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != pos) cout << pos << " " << i << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
