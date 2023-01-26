#include <bits/stdc++.h>
using namespace std;
void circle(int a, int b, int c) {
  int x = (max(a, b) - min(a, b));
  if (max(a, b) > 2 * x || c > 2 * x) {
    cout << -1 << endl;
    return;
  } else {
    if (c + x > 2 * x)
      cout << (c + x) % (2 * x) << endl;
    else
      cout << c + x << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    circle(a, b, c);
  }
  return 0;
}
