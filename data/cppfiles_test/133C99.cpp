#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string res;
    char last = '#';
    for (int i = 0; i < n - 2; i++) {
      char x, y;
      cin >> x >> y;
      if (i == 0)
        res.push_back(x), res.push_back(y);
      else {
        if (last != x) {
          res.push_back(x);
          res.push_back(y);
        } else
          res.push_back(y);
      }
      last = res.back();
    }
    if (res.size() < n) res.push_back('a');
    cout << res;
    cout << '\n';
  }
  return 0;
}
