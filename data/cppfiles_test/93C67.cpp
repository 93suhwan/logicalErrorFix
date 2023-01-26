#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, a, b;
int s[N];
int main() {
  int temp = 0;
  for (int i = 0; i <= 3e5 + 1; i++) {
    temp ^= i;
    s[i] = temp;
  }
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int res = 0;
    res += a;
    int k = a ^ s[a - 1];
    if (s[a - 1] != b && k == b)
      res += 2;
    else if (s[a - 1] != b && k != b)
      res += 1;
    cout << res << endl;
  }
  return 0;
}
