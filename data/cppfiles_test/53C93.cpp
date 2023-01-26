#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int n;
string ss;
string ch;
void solve() {
  cin >> n >> ch >> ss;
  int flag = 0;
  bool st = false;
  for (int i = 0; i < n; i++) {
    if (ss[i] == ch[0]) {
      flag = i + 1;
    } else
      st = true;
  }
  if (!st)
    cout << 0 << endl;
  else {
    if (flag * 2 > n) {
      cout << 1 << endl;
      cout << flag << endl;
    } else {
      cout << 2 << endl;
      cout << n - 1 << ' ' << n << endl;
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
