#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int mx = 0;
  bool one = false, two = false, uno = false;
  for (int _ = (0); _ < (n); _++) {
    int tmp;
    cin >> tmp;
    mx = max(mx, tmp);
    one |= tmp % 3 == 1;
    two |= tmp % 3 == 2;
    uno |= tmp == 1;
  }
  if (mx % 3 == 0) {
    cout << mx / 3 + (one || two);
  } else if (mx % 3 == 1) {
    cout << mx / 3 + 1 + (two && uno);
  } else {
    cout << mx / 3 + 1 + one;
  }
}
int main() {
  int t;
  cin >> t;
  for (int _ = (0); _ < (t); _++) {
    solve();
    cout << "\n";
  }
}
