#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int o = (a + b) / 2;
    int e = a + b - o;
    set<int> ans;
    for (int i = 0; i <= o; i++) {
      int p = i, q = a - i, r = o - p, s = e - q;
      if (q < 0 || r < 0 || s < 0) continue;
      ans.insert(p + s);
    }
    for (int i = 0; i <= e; i++) {
      int p = i, q = a - i, r = o - q, s = e - p;
      if (p < 0 || q < 0 || r < 0 || s < 0) continue;
      ans.insert(p + r);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}
