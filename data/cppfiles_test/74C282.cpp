#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238460;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int d = (a - b) / 2;
    d = abs(d);
    vector<int> ans;
    int i = d;
    while (i <= a + b - d) {
      ans.push_back(i);
      if ((a + b) & 1)
        i++;
      else
        i += 2;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
