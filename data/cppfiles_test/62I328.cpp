#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int idx = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
      if (x == 1 && (i == 0 || v[i - 1] == 0)) idx = i;
    }
    if (idx == -1)
      cout << -1 << endl;
    else {
      if (v[0] == 1) {
        cout << n + 1;
        for (int i = 1; i <= n; i++) cout << " " << i;
        cout << endl;
      } else {
        for (int i = 1; i < idx + 1; i++) cout << i << " ";
        cout << n + 1;
        for (int i = idx + 1; i <= n; i++) cout << " " << i;
        cout << endl;
      }
    }
  }
  return 0;
}
