#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int c = (a + b) >> 1;
    vector<int> ans;
    for (int i = a - c; i <= a + b - c + b; i += 2) ans.push_back(i);
    if ((a + b) & 1) {
      for (int i = a - c - 1; i <= c + 1 + b; i += 2) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
}
