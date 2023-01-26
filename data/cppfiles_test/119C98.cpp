#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int& x : a) cin >> x, sum += x;
  if (sum % n == 0)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
