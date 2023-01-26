#include <bits/stdc++.h>
using namespace std;
void solve() {
  string second, c;
  cin >> second;
  cin >> c;
  int sum = 0, x, y;
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < second.size(); j++) {
      if (second[j] == c[i]) x = j;
    }
    if (i > 0) {
      sum += abs(x - y);
    }
    y = x;
  }
  cout << sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t5;
  cin >> t5;
  while (t5--) {
    solve();
    cout << '\n';
  }
  return 0;
}
