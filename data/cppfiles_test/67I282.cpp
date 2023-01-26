#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, a, b, c, i, j, k;
  cin >> tc;
  while (tc != 0) {
    cin >> a >> b >> c;
    i = abs(a - b);
    j = i * 2;
    if (c <= j && j >= max(a, b)) {
      if (i + c <= j)
        cout << i + c << endl;
      else
        cout << j - c - 1 << endl;
    } else
      cout << -1 << endl;
    tc--;
  }
  return 0;
}
