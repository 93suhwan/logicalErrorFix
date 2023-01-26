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
    for (int i = 0; i < n - 2; i++) {
      char a, b;
      cin >> a >> b;
      res.push_back(a);
      res.push_back(b);
    }
    bool f = 0;
    cout << res[0] << res[1];
    for (int i = 2; i < res.size(); i++) {
      if (res[i] == res[i - 1] && !f) {
        f = 1;
        continue;
      } else
        f = 0, cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}
