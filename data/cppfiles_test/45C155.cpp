#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = 1;
    bool nw = false;
    bool d = false;
    for (int i = 0; i < n; ++i) {
      int s;
      cin >> s;
      if (d) {
        continue;
      }
      if (s == 1) {
        if (i > 0 && !nw) {
          c += 5;
        } else {
          c += 1;
        }
        nw = false;
      } else {
        if (nw) {
          d = true;
        }
        nw = true;
      }
    }
    cout << (d ? -1 : c) << endl;
  }
}
