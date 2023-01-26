#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> res;
    for (int i = 1; i < 2 * n; i++) {
      if (i % 3 == 0 || i % 10 == 3) {
        continue;
      }
      res.push_back(i);
    }
    cout << res[n - 1] << endl;
  }
  return 0;
}
