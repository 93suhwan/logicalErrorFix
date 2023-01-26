#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i = 2;
  cin >> n;
  vector<int> a;
  while (a.size() != n) {
    if (i % (i - 1) != 0) a.push_back(i);
    ++i;
  }
  for (auto x : a) {
    cout << x << ' ';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
