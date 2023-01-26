#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, a, b, c, i, j, k;
  cin >> tc;
  while (tc != 0) {
    cin >> a >> b >> c;
    i = abs(a - b) - 1;
    j = (i + 1) * 2;
    if (c <= j && j >= max(a, b)) {
      if (i + c + 1 <= j)
        cout << i + c + 1 << endl;
      else
        cout << c - i - 1 << endl;
    } else
      cout << -1 << endl;
    tc--;
  }
  return 0;
}
