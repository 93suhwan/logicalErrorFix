#include <bits/stdc++.h>
using namespace std;
int n, q, f;
string s, t;
void dfs(int a, int b, int h) {
  if (b == t.size() - 1) f = 1;
  if (a + h >= 0 && a + h < s.size())
    if (s[a + h] == t[b + 1]) dfs(a + h, b + 1, h);
  if (h == 1 && a - h >= 0 && a - h < s.size())
    if (s[a - h] == t[b + 1]) dfs(a - h, b + 1, h * (-1));
  return;
}
int main() {
  cin >> q;
  while (q--) {
    cin >> s;
    cin >> t;
    int len = s.size();
    f = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == t[0]) {
        dfs(i, 0, 1);
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
