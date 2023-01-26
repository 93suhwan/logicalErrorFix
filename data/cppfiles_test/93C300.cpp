#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, n, ans, num, i, a, b, j;
  cin >> test;
  vector<int> v;
  v.push_back(0);
  for (i = 1; i <= 3 * 10e5; i++) v.push_back(v[i - 1] ^ i);
  while (test--) {
    cin >> a >> b;
    ans = b ^ v[a - 1];
    if (ans == 0)
      cout << a << endl;
    else if (ans != a)
      cout << a + 1 << endl;
    else
      cout << a + 2 << endl;
  }
  return 0;
}
