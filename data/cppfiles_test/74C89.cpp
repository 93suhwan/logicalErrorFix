#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    long long x = (abs(a - b)) / 2;
    set<int> ans;
    if ((a + b) % 2 == 0) {
      for (int i = x; i <= a + b - x; i += 2) ans.insert(i);
    } else {
      for (int j = x; j <= a + b - x; j++) ans.insert(j);
    }
    ans.insert(a + b - x);
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
