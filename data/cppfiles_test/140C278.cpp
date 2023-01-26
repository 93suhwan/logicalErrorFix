#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x;
  cin >> x;
  set<long long> s;
  for (long long i = 1; i * i * i <= x; i++) s.insert(i * i * i);
  for (long long i = 1; i * i <= x; i++) s.insert(i * i);
  cout << s.size() << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
