#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    vector<int> v(100007);
    int x = v[a];
    if (x == b)
      cout << a << endl;
    else if (x ^ b == a)
      cout << a + 2 << endl;
    else
      cout << a + 1 << endl;
  }
  return 0;
}
