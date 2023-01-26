#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  long x = abs(a - b) / 2;
  int y = floor(x);
  vector<int> ans;
  if ((a + b) % 2 == 0) {
    for (int i = y; i <= a + b - y; i = i + 2) {
      ans.push_back(i);
    }
  } else {
    for (int i = y; i <= a + b - y; i = i + 1) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
