#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int x = 0;
  for (int i = 0; i < a; ++i) {
    x = x ^ i;
  }
  int r = (a - 1) % 4;
  if (r == 0) {
    x = a - 1;
  } else if (r == 1) {
    x = 1;
  } else if (r == 2) {
    x = a + 1;
  } else {
    x = 0;
  }
  if (x == b) {
    cout << a << "\n";
    return;
  }
  if ((x ^ b) != a) {
    cout << a + 1 << "\n";
  } else {
    cout << a + 2 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int te;
  cin >> te;
  while (te--) {
    solve();
  }
  return 0;
}
