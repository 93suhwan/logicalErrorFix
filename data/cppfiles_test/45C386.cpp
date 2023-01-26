#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
start:
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    bool b = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] && b) {
        sum += 5;
      } else if (a[i]) {
        sum++;
        b = 1;
      } else {
        if (i > 0 && a[i - 1] == 0) {
          cout << -1 << "\n";
          goto start;
        } else {
          b = 0;
        }
      }
    }
    cout << sum + 1 << "\n";
  }
  return 0;
}
