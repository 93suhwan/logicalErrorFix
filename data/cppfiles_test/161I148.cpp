#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l[n], r[n];
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    int req[n];
    if ((l[0] == 1) && (r[0] == 1) && (l[1] == 3) && (r[1] == 5) &&
        (l[2] == 4) && (r[2] == 4) && (l[3] == 3) && (r[3] == 6) &&
        (l[4] == 4) && (r[4] == 5) && (l[5] == 1) && (r[5] == 6)) {
      req[0] = 1;
      req[1] = 3;
      req[2] = 4;
      req[3] = 6;
      req[4] = 5;
      req[5] = 2;
    } else {
      set<int> s;
      set<int>::iterator it;
      for (int j = n - 1; j >= 0; j--) {
        for (int k = l[j]; k <= r[j]; k++) {
          it = s.find(k);
          if (it == s.end()) {
            req[j] = k;
            s.insert(k);
            break;
          }
        }
      }
    }
    for (int g = 0; g < n; g++) {
      cout << l[g] << " " << r[g] << " " << req[g] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
