#include <bits/stdc++.h>
using namespace std;
void solve() {
  float a, b;
  cin >> a >> b;
  int p = ceil((a + b) / 2);
  int q = floor((a + b) / 2);
  vector<int> v;
  int d = floor(abs(a - b) / 2);
  int c = 1, x = 2;
  if (int(a + b) % 2) {
    for (int i = d; i <= a + b - d; i++) {
      v.push_back(i);
    }
  } else {
    for (int i = d; i <= a + b - d; i += 2) {
      v.push_back(i);
    }
  }
  cout << v.size() << "\n";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
