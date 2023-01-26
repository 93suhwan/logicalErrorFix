#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    int tot = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (tot == -1) {
        continue;
      }
      if (a[i] == 0 && i && a[i - 1] == 0) {
        tot = -1;
      }
      if (a[i] == 1) {
        if (i && a[i - 1]) {
          tot += 5;
        } else {
          tot += 1;
        }
      }
    }
    cout << tot << endl;
  }
  return 0;
}
