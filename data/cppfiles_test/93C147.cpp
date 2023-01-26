#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> v;
  v.push_back(0);
  for (int i = 1; i <= 3 * 10e5; i++) v.push_back(v[i - 1] ^ i);
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = b ^ v[a - 1];
    if (ans == 0)
      cout << a << endl;
    else if (ans < a || ans > a)
      cout << a + 1 << endl;
    else
      cout << a + 2 << endl;
  }
  return 0;
}
