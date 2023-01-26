#include <bits/stdc++.h>
using namespace std;
string a, b;
void sol(int tc) {
  cin >> a >> b;
  string ans = "";
  int cur = 0, pos = a.size() - 1, f = 0;
  for (int i = b.size() - 1; i >= 0; i--) {
    if (pos == -1) {
      ans = b[i] + ans;
      continue;
    }
    int num = (b[i] - '0');
    if (f)
      cur = num * 10 + cur;
    else
      cur = num;
    if (cur - (a[pos] - '0') < 0)
      f = 1;
    else {
      if (cur - (a[pos] - '0') >= 10) {
        cout << "-1\n";
        return;
      }
      ans = to_string(cur - (int)(a[pos] - '0')) + ans;
      pos--;
      f = 0;
      cur = 0;
    }
  }
  if (pos >= 0)
    cout << "-1\n";
  else
    cout << stoll(ans) << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) sol(0);
  return 0;
}
