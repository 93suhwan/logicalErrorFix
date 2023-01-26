#include <bits/stdc++.h>
using namespace std;
long long inf = 1e17;
void solve() {
  int n;
  cin >> n;
  set<int> ans;
  for (long long i = 1; i * i <= n; ++i) ans.insert(i * i);
  for (long long i = 1; i * i * i <= n; ++i) ans.insert(i * i * i);
  cout << ans.size() << "\n";
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
