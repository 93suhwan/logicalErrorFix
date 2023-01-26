#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y, n;
    cin >> a >> b;
    n = a + b;
    vector<int> ans;
    if ((a + b) % 2 == 0) {
      x = max(a, b) - (a + b) / 2;
      ans.push_back(x);
      y = min(a, b);
      while (y--) {
        x += 2;
        ans.push_back(x);
      }
    } else {
      if (a > (n + 1) / 2)
        x = a - (n + 1) / 2;
      else
        x = b - n / 2;
      ans.push_back(x);
      y = min(a, b);
      while (y--) {
        x += 2;
        ans.push_back(x);
      }
      if (a > n / 2)
        x = a - n / 2;
      else
        x = b - (n + 1) / 2;
      ans.push_back(x);
      y = min(a, b);
      while (y--) {
        x += 2;
        ans.push_back(x);
      }
    }
    sort((ans).begin(), (ans).end());
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
}
