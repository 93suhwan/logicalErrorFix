#include <bits/stdc++.h>
using namespace std;
int a, b;
int T;
void solve() {
  cin >> a >> b;
  if (a > b) {
    cout << 0;
  } else {
    if (a == 1) {
      cout << b;
    } else if (a == 2) {
      cout << b / 2;
    } else {
      int t = ceil((double)a / 2);
      if (a % 2 == 0) {
        t++;
      }
      cout << b / t;
    }
  }
}
int main() {
  freopen("in.txt", "r", stdin);
  cin >> T;
  while (T--) {
    solve();
    if (T != 0) {
      cout << "\n";
    }
  }
  return 0;
}
