#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    int m = c[0];
    for (int i = 1; i < n; i++) {
      if (c[i] - c[i - 1] > m) m = c[i] - c[i - 1];
    }
    cout << m;
    cout << '\n';
  }
  return 0;
}
