#include <bits/stdc++.h>
using namespace std;
string s, e;
void slove() {
  int n, x = 0, y = 0, z = 0, ans = 100010;
  cin >> n >> s >> e;
  for (int i = 0; i < n; ++i)
    x += s[i] - '0', y += e[i] - '0', z += (s[i] != e[i]);
  if (x == y) ans = z;
  if (x == n - y + 1) ans = min(ans, n - z);
  cout << (ans == 100010 ? -1 : ans) << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
  return 0;
}
