#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int c = abs(n - m) / 2;
  vector<int> v;
  if ((n + m) % 2) {
    for (int i = c; i <= (n + m) - c; i++) {
      v.push_back(i);
    }
  } else {
    for (int i = c; i <= (n + m) - c; i += 2) {
      v.push_back(i);
    }
  }
  cout << v.size() << "\n";
  for (auto i : v) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
