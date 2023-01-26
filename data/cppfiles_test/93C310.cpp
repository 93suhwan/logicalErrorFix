#include <bits/stdc++.h>
using namespace std;
const int n = 3e5 + 5;
int v[n];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b;
  for (int i = 1; i < n; i++) {
    v[i] = v[i - 1] ^ (i - 1);
  }
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int x = v[a];
    if (x == b)
      cout << a << endl;
    else if ((x ^ b) == a)
      cout << a + 2 << endl;
    else
      cout << a + 1 << endl;
  }
  return 0;
}
