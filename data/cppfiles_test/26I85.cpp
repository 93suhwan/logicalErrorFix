#include <bits/stdc++.h>
using namespace std;
int mn;
void recur(string s, int n, int a, int b) {
  if ((10 - n) / 2 + b < a) mn = min(mn, n);
  if ((10 - n - 1) / 2 + a < b) mn = min(mn, n);
  if (n == 10) {
    return;
  } else if (s[n] == '?') {
    if (n % 2 == 1) {
      recur(s, n + 1, a, b);
      recur(s, n + 1, a, b + 1);
    } else {
      recur(s, n + 1, a + 1, b);
      recur(s, n + 1, a, b);
    }
  } else if (s[n] == '1') {
    if (n % 2 == 1)
      recur(s, n + 1, a, b + 1);
    else
      recur(s, n + 1, a + 1, b);
  } else {
    recur(s, n + 1, a, b);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    mn = 10;
    recur(s, 0, 0, 0);
    cout << mn + 1 << "\n";
  }
}
