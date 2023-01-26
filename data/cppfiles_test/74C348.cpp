#include <bits/stdc++.h>
using namespace std;
set<int> f(int a, int b) {
  int x = (a + b) / 2;
  int y = a + b - x;
  set<int> ans;
  for (int i = 0; i <= a; i++) {
    if (i <= x && (a - i) <= y) {
      ans.insert(x - i + a - i);
    }
  }
  swap(x, y);
  for (int i = 0; i <= a; i++) {
    if (i <= x && (a - i) <= y) {
      ans.insert(x - i + a - i);
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    set<int> ans;
    ans = f(a, b);
    cout << ans.size() << endl;
    int tmp = ans.size();
    for (auto it = ans.begin(); it != ans.end(); it++) {
      cout << (*it) << " ";
    }
    cout << endl;
  }
  return 0;
}
