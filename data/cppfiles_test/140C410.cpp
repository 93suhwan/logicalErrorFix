#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  set<long long int> se;
  for (long long int i = 1; i <= n; i++) {
    if (i * i > n) break;
    se.insert(i * i);
    if (i * i * i <= n) se.insert(i * i * i);
  }
  cout << se.size() << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
