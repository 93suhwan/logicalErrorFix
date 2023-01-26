#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
void solve() {
  long long a, b;
  cin >> a >> b;
  set<long long> ans;
  if (b < a) std::swap(a, b);
  for (long long i = (b - a) / 2, j = 0; i <= a + b && j <= a; i += 2, ++j) {
    ans.insert(i);
    ans.insert(a + b - i);
  }
  std::cout << ans.size() << '\n';
  for (auto& x : ans) cout << x << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (int i = 0; i < (t); i++) {
    solve();
  }
  return 0;
}
